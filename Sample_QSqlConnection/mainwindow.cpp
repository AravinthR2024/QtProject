// CREATE MACRO FOR SHOWING AND HIGING IN THE FUNCTION LINE#620 on_leDeleteName_currentIndexChanged



#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_bIsNamesLoaded = false;
    m_bIsQualificationLoaded = false;

    bool ok = false;
    ok = createConnection ();
    if (!ok)
    {
        QMessageBox::warning (this, TXT_CONNECTION_TITLE, "Error while connecting to Db");
    }

    ok = establishTable ();
    if(!ok)
    {
        QMessageBox::warning (this, TXT_CONNECTION_TITLE, "Error while establishing Table");
    }

    m_strQualificationList << "SSLC" << "HSC" << "Diplomo" << "Bachelor's Degree (Professional)" \
                         << "Master's Degree (Professional)" << "Bachelor's Degree (Arts & Science)" << \
                            "Master's Degree (Arts & Science)";

    ui->cmbQualification->addItems (m_strQualificationList);

    QCompleter *completerQualification = new QCompleter (m_strQualificationList, this);
    completerQualification->setCaseSensitivity (Qt::CaseInsensitive);
    completerQualification->setCompletionMode (QCompleter::PopupCompletion);
    ui->cmbQualification->setCompleter (completerQualification);

    ok = establishTable ();
    ui->twDisplayWidget->setCurrentIndex (0);
    ui->leName->setFocus ();

    QStringList strHeaderLabelList;
    strHeaderLabelList << "Name" << "Age" << "Qualification" << "Address";
    ui->twDetailsViewTable->horizontalHeader ()->setSectionResizeMode (QHeaderView::ResizeToContents);
    ui->twDetailsViewTable->setHorizontalHeaderLabels (strHeaderLabelList);
}

bool MainWindow::createConnection()
{
    m_dbConn = QSqlDatabase::addDatabase (DBPARAM_CONNECTION);
    m_dbConn.setHostName (DBPARAM_HOST_NAME);
    m_dbConn.setDatabaseName (DBPARAM_DB_NAME);
    m_dbConn.setUserName (DBPARAM_USER_NAME);
    m_dbConn.setPassword (DBPARAM_PASSWORD);

    return m_dbConn.open ();
}

bool MainWindow::establishTable()
{
    QString strCreateQuery;
    strCreateQuery.sprintf ("CREATE TABLE IF NOT EXISTS %s"
                            "(sno integer PRIMARY KEY AUTOINCREMENT, name varchar(50), age integer, "
                            "qualification varchar(25), address varchar(100))", DBPARAM_TABLE_NAME);
    QSqlQuery queryCreateQuery;

    if (!queryCreateQuery.exec (strCreateQuery))
    {
        qWarning("%s", queryCreateQuery.lastError().text().toLocal8Bit().data());
        QMessageBox::warning (this, TXT_CONNECTION_TITLE, "Error while Establishing the Table");
        return false;
    }
    return true;
}

bool MainWindow::addPerson(QString in_strName, int in_iAge, QString in_strQualification, QString in_strAddress)
{
    CHECK_PERSON_EXISTS(in_strName);

    QString strInsertQuery;
    strInsertQuery.sprintf ("INSERT INTO %s (name, age, qualification, address) "
                            "VALUES (?, ?, ?, ?)", DBPARAM_TABLE_NAME);

    QSqlQuery queryInsert;
    queryInsert.prepare (strInsertQuery);

    queryInsert.addBindValue (in_strName.toStdString ().c_str ());
    queryInsert.addBindValue (in_iAge);
    queryInsert.addBindValue (in_strQualification.toStdString ().c_str ());
    queryInsert.addBindValue (in_strAddress.toStdString ().c_str ());

    if (!queryInsert.exec ())
    {
        QMessageBox::warning (this, TXT_APPLICAITON_TITLE, "Error while Adding Person");
        qWarning("%s", queryInsert.lastError ().text ().toLocal8Bit ().data ());
        return false;
    }

    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Person Added");
    return true;
}

bool MainWindow::updatePerson(S_PERSON_DETAILS *in_SPersonDetails)
{
    QString strUpdateQuery;
    strUpdateQuery.sprintf ("UPDATE %s SET `age` = ?, `qualification` = ?, `address` = ? WHERE `name` = ?", DBPARAM_TABLE_NAME);

    QSqlQuery queryUpdate;
    queryUpdate.prepare (strUpdateQuery);

    queryUpdate.addBindValue (in_SPersonDetails->iAge);
    queryUpdate.addBindValue (in_SPersonDetails->strQualification.toStdString ().c_str ());
    queryUpdate.addBindValue (in_SPersonDetails->strAddress.toStdString ().c_str ());
    queryUpdate.addBindValue (in_SPersonDetails->strName.toStdString ().c_str ());

    if (!queryUpdate.exec ())
    {
        QMessageBox::warning (this, TXT_APPLICAITON_TITLE, "Error while Updating Details");
        qWarning("%s", queryUpdate.lastError ().text ().toLocal8Bit ().data ());
        return false;
    }

    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Person details updated");
    return true;
}

int MainWindow::checkPersonExists(QString in_strName)
{
    QString strCountRecordQuery;
    strCountRecordQuery.sprintf ("SELECT * FROM %s WHERE name = '%s'", DBPARAM_TABLE_NAME, in_strName.toStdString ().c_str ());

    QSqlQuery queryCountRecord;

    if (!queryCountRecord.exec (strCountRecordQuery))
    {
        QMessageBox::warning (this, TXT_APPLICAITON_TITLE, "Error while searching record");
        qWarning("%s", queryCountRecord.lastError ().text ().toLocal8Bit ().data ());
        return ERR_QUERY_EXEC;
    }

    return queryCountRecord.last ();
}

bool MainWindow::retrieveColumnData(int in_iColumn, QStringList *out_strDataList)
{
    if (in_iColumn < 0 || in_iColumn > 4)
    {
        qDebug ("Invalid Column Send for Retrieval of Data");
        return false;
    }

    QString strRetrieveQuery;
    strRetrieveQuery.sprintf ("SELECT * FROM '%s'", DBPARAM_TABLE_NAME);

    QSqlQuery queryFetchData;
    bool bOk = queryFetchData.exec (strRetrieveQuery);
    if (!bOk)
    {
        qWarning("Fetch Error : %s", queryFetchData.lastError ().text ().toLocal8Bit ().data ());
        return false;
    }

    /* If no data found */
    if (queryFetchData.first () == 0)
    {
        return true;
    }

    do
    {
        out_strDataList->append (queryFetchData.value (in_iColumn).toString ());
    } while (queryFetchData.next ());

    return true;
}

bool MainWindow::retrieveDataByName(QString in_strName, S_PERSON_DETAILS *out_SPersonDetails)
{
    QString strRetrieveQuery;
    strRetrieveQuery.sprintf ("SELECT * FROM '%s' WHERE `name` = '%s'", DBPARAM_TABLE_NAME, in_strName.toStdString ().c_str ());

    QSqlQuery queryFetchPersonDetails;
    bool bOk = queryFetchPersonDetails.exec (strRetrieveQuery);
    if (!bOk)
    {
        QMessageBox::information (this, TXT_CONNECTION_TITLE, "Error while retrieving data");
        qWarning ("Fetch Error : %s", queryFetchPersonDetails.lastError ().text ().toLocal8Bit ().data ());
        return false;
    }

    /* If no data found */
    if (queryFetchPersonDetails.first () == 0)
    {
        return false;
    }

    /* If person found */
    out_SPersonDetails->strName = queryFetchPersonDetails.value (TBL_IDX_Name).toString ();
    out_SPersonDetails->iAge = queryFetchPersonDetails.value (TBL_IDX_Age).toInt ();
    out_SPersonDetails->strQualification = queryFetchPersonDetails.value (TBL_IDX_Qualification).toString ();
    out_SPersonDetails->strAddress = queryFetchPersonDetails.value (TBL_IDX_Address).toString ();

    return true;
}

bool MainWindow::retrieveAllData(QList<S_PERSON_DETAILS> *out_SPersonsDetailsList)
{
    QString strRetrieveQuery;
    strRetrieveQuery.sprintf ("SELECT * FROM '%s'", DBPARAM_TABLE_NAME);

    QSqlQuery queryFetchDetails;
    bool bOk = queryFetchDetails.exec (strRetrieveQuery);
    if (!bOk)
    {
        QMessageBox::information (this, TXT_CONNECTION_TITLE, "Error while retrieving all data");
        qWarning ("Fetching Error : %s", queryFetchDetails.lastError ().text ().toLocal8Bit ().data ());
        return false;
    }

    /* If no data present */
    if (queryFetchDetails.first () == 0)
    {
        MSGBOX_NO_DATA
        return false;
    }

    /* Iterating all data and storing in the QList */
    do
    {
        S_PERSON_DETAILS STempDetails;
        STempDetails.strName = queryFetchDetails.value (TBL_IDX_Name).toString ();
        STempDetails.iAge = queryFetchDetails.value (TBL_IDX_Age).toInt ();
        STempDetails.strQualification = queryFetchDetails.value (TBL_IDX_Qualification).toString ();
        STempDetails.strAddress = queryFetchDetails.value (TBL_IDX_Address).toString ();

        /* Adding the data to the list */
        out_SPersonsDetailsList->append (STempDetails);
    } while (queryFetchDetails.next ());

    return true;
}

void MainWindow::clearInputFields(int in_iTabIndex)
{
    if (in_iTabIndex == TAB_ADD_PERSON)
    {
        ui->leName->clear ();
        ui->cmbQualification->setCurrentIndex (0);
        ui->sbAge->setValue (18);
        ui->teAddress->clear ();
        ui->leName->setFocus ();
    }
    else if (in_iTabIndex == TAB_UPDATE_PERSON)
    {
        ui->leUpdateName->setCurrentIndex (0);
        ui->cmbNewQualification->setCurrentIndex (0);
        ui->sbNewAge->setValue (18);
        ui->teNewAddress->clear ();
        ui->leUpdateName->setFocus ();
    }
    else if (in_iTabIndex == TAB_DELETE_PERSON)
    {
        ui->leDeleteAge->setValue (0);
        ui->leDeleteName->setCurrentIndex (0);
        ui->leDeleteQualification->setCurrentIndex (0);
        ui->teDeleteAddress->clear ();
        ui->leDeleteName->setFocus ();
    }
}

int MainWindow::validateName(std::string in_strName)
{
    int iLength = in_strName.length();

    // Checking lower alphabet in string
    bool bHasDigit = false, bHasSpecialChar = false;

    std::string normalChars = "abcdefghijklmnopqrstuvwxyz1234567890._";

    for (int iLoop = 0; iLoop < iLength; iLoop++) {
        if (isdigit(in_strName[iLoop]))
            bHasDigit = true;

        size_t special = in_strName.find_first_not_of(normalChars);
        if (special != std::string::npos)    // string::npos = -1 for all
            bHasSpecialChar = true;
    }

    // Strength of password
    if (bHasDigit || bHasSpecialChar || (iLength < 8))
    {return INVALID_NAME;}
    else
    {return VALID_NAME;}
}

void MainWindow::loadAvailableNamesFromDB(QComboBox *in_cmbBox)
{
    QStringList strNameList;
//    if (in_cmbBox == ui->leDeleteName)
//    {
        strNameList << "-- Choose Name --";
//    }

    if (!retrieveColumnData (TBL_IDX_Name, &strNameList))
    {
        QMessageBox::information (this, TXT_CONNECTION_TITLE, "Error while retrieving data");
        return;
    }

    if (strNameList.isEmpty () || strNameList.length () < 2)
    {
        MSGBOX_NO_DATA;
    }

    in_cmbBox->addItems (strNameList);
}

void MainWindow::displayPersonDetails()
{
    int iLoop = 0;
    QList<S_PERSON_DETAILS> SPersonDetailsList;
    if (!retrieveAllData (&SPersonDetailsList))
    {
        return;
    }

    ui->twDetailsViewTable->setRowCount (0);

    foreach (S_PERSON_DETAILS SPersonDetails, SPersonDetailsList)
    {
        QTableWidgetItem *itemName = new QTableWidgetItem(SPersonDetails.strName);
        itemName->setFlags(itemName->flags() ^ Qt::ItemIsEditable);

        QTableWidgetItem *itemAge = new QTableWidgetItem(QString::number (SPersonDetails.iAge));
        itemAge->setFlags(itemAge->flags() ^ Qt::ItemIsEditable);

        QTableWidgetItem *itemQualification = new QTableWidgetItem(SPersonDetails.strQualification);
        itemQualification->setFlags(itemQualification->flags() ^ Qt::ItemIsEditable);

        QTableWidgetItem *itemAddress = new QTableWidgetItem(SPersonDetails.strAddress.replace ("\n", ""));    // Removing new-line
        itemAddress->setFlags(itemAddress->flags() ^ Qt::ItemIsEditable);

        ui->twDetailsViewTable->insertRow (iLoop);
        ui->twDetailsViewTable->setItem (iLoop, 0, itemName);
        ui->twDetailsViewTable->setItem (iLoop, 1, itemAge);
        ui->twDetailsViewTable->setItem (iLoop, 2, itemQualification);
        ui->twDetailsViewTable->setItem (iLoop, 3, itemAddress);

        iLoop++;
    }
}

void MainWindow::displaySelectedPersonDetails(QString in_strName)
{
    S_PERSON_DETAILS SPersonDetails;

    retrieveDataByName (in_strName, &SPersonDetails);

    CPersonDetails *objPersonDetailDialog = new CPersonDetails(this, &SPersonDetails);
    objPersonDetailDialog->exec ();
}

void MainWindow::updatePersonFuncCall(QString in_strName)
{
    ui->twDisplayWidget->setCurrentIndex (TAB_UPDATE_PERSON);
    if (!m_bIsNamesLoaded)
    {
        loadAvailableNamesFromDB (ui->leUpdateName);
        m_bIsNamesLoaded = true;
    }
    ui->leUpdateName->setCurrentText (in_strName);
}

void MainWindow::deletePersonFuncCall(QString in_strName)
{
    QString strDeleteQuery;
    strDeleteQuery.sprintf ("DELETE FROM '%s' WHERE `name` = '%s'", DBPARAM_TABLE_NAME, in_strName.toStdString ().c_str ());

    QSqlQuery queryDelete;
    if (!queryDelete.exec (strDeleteQuery))
    {
        qWarning("%s", queryDelete.lastError ().text ().toLocal8Bit ().data ());
        QMessageBox::warning (this, TXT_APPLICAITON_TITLE, "Error while deleting the record");
        return;
    }

    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Person deleted successfully");
    m_bIsNamesLoaded = false;

    QList<S_PERSON_DETAILS> SNULL;
    if (!retrieveAllData (&SNULL))
    {
        ui->twDisplayWidget->setCurrentIndex (TAB_ADD_PERSON);
        return;
    }

    on_twDisplayWidget_currentChanged (TAB_DELETE_PERSON);
    on_twDisplayWidget_currentChanged (TAB_UPDATE_PERSON);
    on_twDisplayWidget_currentChanged (TAB_VIEW_PERSON);

    ui->twDisplayWidget->setCurrentIndex (TAB_VIEW_PERSON);
}

void MainWindow::changeThemeState(bool in_bState)
{
    ui->cbIsLightMode->setChecked (in_bState);
    on_cbIsLightMode_stateChanged ((in_bState) ? (Qt::Checked) : (Qt::Unchecked));
}

void MainWindow::changeFocusToTab(int in_iTabIndex)
{
    ui->twDisplayWidget->setCurrentIndex (in_iTabIndex);
}

void MainWindow::closeEvent(QCloseEvent *evtClose)
{
    QString strTheme;
    if (ui->cbIsLightMode->isChecked ())
    {
        strTheme = "light";
    }
    else
    {
        strTheme = "dark";
    }

    int iOk = QMessageBox::question (this, TXT_APPLICAITON_TITLE, tr("Are you sure to close the application?")
                                                               , QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (iOk == QMessageBox::Yes)
    {
        QFile fileConfig("./config/config.bin");
        if (!fileConfig.open (QIODevice::WriteOnly))
        {
            qDebug("Config File loading Error");
        }
        QDataStream stream(&fileConfig);
        stream << strTheme;
        fileConfig.close ();
        evtClose->accept ();
    }
    else
    {
        evtClose->ignore ();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbAdd_clicked()
{
#if 0
    QString strName = ui->leName->text ();
    int iAge = ui->sbAge->value ();
    QString strQualification = ui->cmbQualification->currentText ();
    QString strAddress = ui->teAddress->toPlainText ();
#endif

    S_PERSON_DETAILS SPersonDetails;
    SPersonDetails.strName = ui->leName->text ().toLower ();
    SPersonDetails.iAge = ui->sbAge->value ();
    SPersonDetails.strQualification = ui->cmbQualification->currentText ();
    SPersonDetails.strAddress = ui->teAddress->toPlainText ();

    /* Validating Name */
    VALIDATION_NAME(SPersonDetails.strName);

    /* Validating Age */
    VALIDATION_AGE(SPersonDetails.iAge);

    /* Validating Address */
    VALIDATION_ADDRESS(SPersonDetails.strAddress);

    /* If all validations succeeded */
    if (addPerson (SPersonDetails.strName, SPersonDetails.iAge, SPersonDetails.strQualification, SPersonDetails.strAddress))
    {
        /* Clearing the data fields */
        clearInputFields (TAB_ADD_PERSON);
    }

    m_bIsNamesLoaded = false;   /* To update the list after adding new person */
}
void MainWindow::on_leName_returnPressed()
{
    on_pbAdd_clicked ();
}

void MainWindow::on_actionAdd_Person_triggered()
{
    ui->twDisplayWidget->setCurrentIndex (TAB_ADD_PERSON);
}

void MainWindow::on_actionView_Person_triggered()
{
    ui->twDisplayWidget->setCurrentIndex (TAB_VIEW_PERSON);
}

void MainWindow::on_actionUpdateDetails_triggered()
{
    ui->twDisplayWidget->setCurrentIndex (TAB_UPDATE_PERSON);
}

void MainWindow::on_actionDelete_Persons_triggered()
{
    ui->twDisplayWidget->setCurrentIndex (TAB_DELETE_PERSON);
}

void MainWindow::on_actionQuit_triggered()
{
    this->close ();
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt (this, "About QT");
}

void MainWindow::on_actionAbout_Application_triggered()
{
    CAboutApplication *objAboutApp = new CAboutApplication;
    objAboutApp->exec ();
}

void MainWindow::on_twDisplayWidget_currentChanged(int index)
{
    if (index == TAB_UPDATE_PERSON)
    {
        ui->leUpdateName->clear ();
        loadAvailableNamesFromDB (ui->leUpdateName);
        m_bIsNamesLoaded = true;
//        updatePersonFuncCall ("-- Choose Name --");
        clearInputFields (TAB_ADD_PERSON);
        clearInputFields (TAB_DELETE_PERSON);
    }
    else if (index == TAB_VIEW_PERSON)
    {
        displayPersonDetails ();
        clearInputFields (TAB_ADD_PERSON);
        clearInputFields (TAB_DELETE_PERSON);
        clearInputFields (TAB_UPDATE_PERSON);
    }
    else if (index == TAB_DELETE_PERSON)
    {
        ui->twDisplayWidget->setCurrentIndex (TAB_DELETE_PERSON);

        ui->leDeleteName->clear ();
        loadAvailableNamesFromDB (ui->leDeleteName);
        m_bIsNamesLoaded = true;

        clearInputFields (TAB_ADD_PERSON);
        clearInputFields (TAB_UPDATE_PERSON);
    }
}

void MainWindow::on_pbUpdate_clicked()
{
    S_PERSON_DETAILS SPersonDetailsNew;
    SPersonDetailsNew.strName = ui->leUpdateName->currentText ();
    SPersonDetailsNew.iAge = ui->sbNewAge->value ();
    SPersonDetailsNew.strQualification = ui->cmbNewQualification->currentText ();
    SPersonDetailsNew.strAddress = ui->teNewAddress->toPlainText ();

    /* Validating new values */
    VALIDATION_NAME(SPersonDetailsNew.strName);
    VALIDATION_AGE(SPersonDetailsNew.iAge);
    VALIDATION_ADDRESS(SPersonDetailsNew.strAddress);

    /* If all validations passed */
    if (updatePerson (&SPersonDetailsNew))
    {
        clearInputFields (TAB_UPDATE_PERSON);
    }
    on_leUpdateName_currentIndexChanged (SPersonDetailsNew.strName);    /* Updating new data in UI */
}

void MainWindow::on_leUpdateName_currentIndexChanged(const QString &arg1)
{
    if (ui->leUpdateName->currentIndex () == 0)
    {
        clearInputFields (TAB_UPDATE_PERSON);
        UPDATE_TAB_HIDE;
        return;
    }

    UPDATE_TAB_SHOW;

    S_PERSON_DETAILS SPersonDetails;
    if (!retrieveDataByName (arg1, &SPersonDetails))
    {
        return;
    }

    /* Loading the qualification list in combobox */
    if (!m_bIsQualificationLoaded)
    {
        ui->cmbNewQualification->addItems (m_strQualificationList);
        m_bIsQualificationLoaded = true;
    }

    ui->sbNewAge->setValue (SPersonDetails.iAge);
    ui->cmbNewQualification->setCurrentText (SPersonDetails.strQualification);
    ui->teNewAddress->setPlainText (SPersonDetails.strAddress);
}

void MainWindow::on_twDetailsViewTable_clicked(const QModelIndex &index)
{
    ui->twDetailsViewTable->selectRow (index.row ());
}

void MainWindow::on_twDetailsViewTable_doubleClicked(const QModelIndex &index)
{
    QString strSelectedName = ui->twDetailsViewTable->item (index.row (), 0)->text ();
    displaySelectedPersonDetails (strSelectedName);
}

void MainWindow::on_leDeleteName_currentIndexChanged(const QString &arg1)
{
    if (ui->leDeleteName->currentIndex () == 0 || ui->leDeleteName->currentText ().isEmpty ())
    {
        clearInputFields (TAB_DELETE_PERSON);
        DELETE_TAB_HIDE;
        return;
    }

    DELETE_TAB_SHOW;

    S_PERSON_DETAILS SPersonDetails;
    if (!retrieveDataByName (arg1, &SPersonDetails))
    {
        return;
    }

    /* Loading the qualification list in combobox */
    if (!m_bIsQualificationLoaded)
    {
        ui->leDeleteQualification->addItem (SPersonDetails.strQualification);
        m_bIsQualificationLoaded = true;
    }

    ui->leDeleteAge->setValue (SPersonDetails.iAge);
    ui->teDeleteAddress->setPlainText (SPersonDetails.strAddress);
}

void MainWindow::on_pbDelete_clicked()
{
    QString strDeleteName = ui->leDeleteName->currentText ().toStdString ().c_str ();

    if (strDeleteName == "-- Choose Name --")
    {
        QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Select a Person to Delete");
        return;
    }

    QString strQuestionString;
    strQuestionString.sprintf ("Sure want to delete '%s'", strDeleteName.toStdString ().c_str ());
    int iOk = QMessageBox::question (this, TXT_APPLICAITON_TITLE, strQuestionString, QMessageBox::Yes | QMessageBox::No, \
                                     QMessageBox::Yes);
    if (iOk == QMessageBox::No)
    {
        return;
    }
    deletePersonFuncCall (ui->leDeleteName->currentText ());
}

void MainWindow::on_cbIsLightMode_stateChanged(int in_iEnableLightTheme)
{
    QFile styleFile;
    if (in_iEnableLightTheme == Qt::Checked)
    {
        styleFile.setFileName (":/qss/qss/lightmode.css");
    }
    else
    {
        styleFile.setFileName (":/qss/qss/darkmode.css");
    }
    if (!styleFile.open (QIODevice::ReadOnly))
    {
        qDebug("Not opened darkmode");
        return;
    }
    QTextStream styleTextStream (&styleFile);
    QString styleText = styleTextStream.readAll ();
    this->setStyleSheet (styleText.toStdString ().c_str ());
}
