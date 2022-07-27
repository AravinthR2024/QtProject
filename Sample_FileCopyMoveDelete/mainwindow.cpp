#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex (0);

    m_bCurrentPathSelect = 0;
    m_qstrFilePath = QString();

    ui->rbCopy->setChecked (true);
    ui->lblLabel1->setText ("Source file");
    ui->lblLabel2->setText ("Destination folder");

    connect(ui->pbBrowse1, SIGNAL(entered()), this, SLOT(on_pbBrowse1_clicked()));
    connect(ui->pbBrowse1, SIGNAL(dropped()), this, SLOT(on_pbBrowseCancel_clicked()));
    connect(ui->pbBrowse2, SIGNAL(entered()), this, SLOT(on_pbBrowse2_clicked()));
    connect(ui->pbBrowse2, SIGNAL(dropped()), this, SLOT(on_pbBrowseCancel_clicked()));

    setAcceptDrops (true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *evt)
{
    ui->lblDropInstruction->setText ("Drag file to Browse buttons to select respectively");
    ui->lblDropInfo->setStyleSheet ("QLabel { border: 3px solid blue }");
    if (ui->stackedWidget->currentIndex () == 1 && evt->mimeData ()->hasUrls ())
    {
        evt->acceptProposedAction ();
    }
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *)
{
    ui->lblDropInstruction->setText ("Drag file to Browse buttons to select respectively");
    ui->stackedWidget->setCurrentIndex (0);
    ui->lblDropInfo->setStyleSheet ("QLabel { border: none }");
}

void MainWindow::dropEvent(QDropEvent *evt)
{
    ui->lblDropInstruction->setText ("Drag file to Browse buttons to select respectively");
    ui->lblDropInfo->setStyleSheet ("QLabel { border: none }");

    if (evt->mimeData ()->urls ().isEmpty ())
    {
        QMessageBox::information (this, "File", "No file selected");
        return;
    }
    m_qstrFilePath = evt->mimeData ()->urls ().at (0).toLocalFile ();

    updateFilepath (m_qstrFilePath);

    ui->stackedWidget->setCurrentIndex (0);
}

void MainWindow::updateFilepath(QString in_qstrFilepath)
{
    if (m_bCurrentPathSelect)
    {
        ui->lePath2->setText (in_qstrFilepath);
        ui->lePath2->setText (in_qstrFilepath);
    }
    else
    {
        ui->lePath1->setText (in_qstrFilepath);
        ui->lePath1->setToolTip (in_qstrFilepath);
    }
}

unsigned short MainWindow::copyFile(QString in_qstrSource, QString in_qstrDestination)
{
    bool bOk = true;
    CHECK_STRING_NOT_NULL (in_qstrSource, "Please choose the source file to copy", SOURCEFILE_NOT_SELECTED);
    CHECK_STRING_NOT_NULL (in_qstrDestination, "Please choose the destination folder to copy", DESTINATIONFILE_NOT_SELECTED);

    QFile fileSource (in_qstrSource);
    QString qstrFilename = QFileInfo(fileSource).fileName ();
    in_qstrDestination = in_qstrDestination + "/" + qstrFilename;

    bOk = QFile::copy (in_qstrSource, in_qstrDestination);

    return (bOk ? SUCCESS : OPERATION_UNSUCCESS);
}

unsigned short MainWindow::moveFile(QString in_qstrSource, QString in_qstrDestination)
{
    CHECK_STRING_NOT_NULL (in_qstrSource, "Please choose the source file to move", SOURCEFILE_NOT_SELECTED);
    CHECK_STRING_NOT_NULL (in_qstrDestination, "Please choose the destination folder to move", DESTINATIONFILE_NOT_SELECTED);

    QString qstrFilename = QFileInfo(QFile(in_qstrSource)).fileName ();
    in_qstrDestination += "/" + qstrFilename;
    bool bOk = QFile::rename (in_qstrSource, in_qstrDestination);

    return (bOk ? SUCCESS : OPERATION_UNSUCCESS);
}

unsigned short MainWindow::removeFile(QString in_qstrFilePath)
{
    CHECK_STRING_NOT_NULL (in_qstrFilePath, "Please choose the file to delete", SOURCEFILE_NOT_SELECTED);
    bool bOk = true;
    QFile file(in_qstrFilePath);

    QMessageBox::StandardButton btnConfirmation = QMessageBox::question (this, "Confirm", "Really want to remove file?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (btnConfirmation == QMessageBox::Yes)
    {
        bOk = file.remove ();
    }
    else
    {
        QMessageBox::information (this, "Remove file", "Remove file cancelled");
        return OPERATION_CANCELLED;
    }

    return (bOk ? SUCCESS : OPERATION_UNSUCCESS);
}

unsigned short MainWindow::renameFile(QString in_qstrOldFile, QString in_qstrNewFile)
{
    CHECK_STRING_NOT_NULL (in_qstrOldFile, "Please choose the file to rename", SOURCEFILE_NOT_SELECTED);
    CHECK_STRING_NOT_NULL (in_qstrNewFile, "Please enter a new file name", DESTINATIONFILE_NOT_SELECTED);

    QFile file(in_qstrOldFile);
    QString qstrExtension = QFileInfo(file).completeSuffix ();
    return (QFile::rename (in_qstrOldFile, QFileInfo(file).absolutePath () + "/" + in_qstrNewFile + "." + qstrExtension) ? SUCCESS : OPERATION_UNSUCCESS);
}

void MainWindow::on_pbBrowse1_clicked()
{
    ui->lblDropInfo->setStyleSheet ("QLabel { border: none }");
    ui->stackedWidget->setCurrentIndex (1);

    m_bCurrentPathSelect = 0;

    ui->lePath1->setText (m_qstrFilePath);
}

void MainWindow::on_pbBrowse2_clicked()
{
    ui->lblDropInfo->setStyleSheet ("QLabel { border: none }");
    ui->stackedWidget->setCurrentIndex (1);

    m_bCurrentPathSelect = 1;

    ui->lePath1->setText (m_qstrFilePath);
}

void MainWindow::on_pbBrowse_clicked()
{
    if (m_bCurrentPathSelect)
    {
        m_qstrFilePath = QFileDialog::getExistingDirectory (this, "Select destination director", qApp->applicationDirPath (), QFileDialog::ShowDirsOnly);
    }
    else
    {
        m_qstrFilePath = QFileDialog::getOpenFileName (this, "Select source file", qApp->applicationDirPath ());
    }
    updateFilepath (m_qstrFilePath);

    ui->stackedWidget->setCurrentIndex (0);
}

void MainWindow::on_rbCopy_toggled(bool checked)
{
    Q_UNUSED(checked);

    if (ui->rbCopy->isChecked ())
    {
        CHANGE_TEXT("Source File", "Destination folder", "&Copy", true);
    }
    else if (ui->rbMove->isChecked ())
    {
        CHANGE_TEXT("Source File", "Destination folder", "&Move", true);
    }
    else if (ui->rbRemove->isChecked ())
    {
        CHANGE_TEXT("File Path", "", "&Remove", false);
    }
    else if (ui->rbRename->isChecked ())
    {
        ui->pbBrowse2->setEnabled (false);
        CHANGE_TEXT("File Path", "New Name", "&Rename", true);

        ui->lePath2->setReadOnly (false);
    }
    else
    {
        QMessageBox::information (this, "Operation Error", "Please select a File Operation");
        return;
    }
}

void MainWindow::on_pbDo_clicked()
{
//    STATUS_BAR_INITIAL_UPDATE;

//    QThread::sleep (1);

    QString qstrPath1 = QString();
    QString qstrPath2 = QString();

    unsigned short usResult = 0;

    qstrPath1 = ui->lePath1->text ();
    qstrPath2 = ui->lePath2->text ();

    if (ui->rbCopy->isChecked ())
    {
        usResult = copyFile (qstrPath1, qstrPath2);
        if (usResult != SUCCESS)
        {
            QMessageBox::information (this, "Copy File", "File Copy failed");
            return;
        }
        else if (usResult == OPERATION_CANCELLED)
        {
            return;
        }
        else
        {
            QMessageBox::information (this, "Copy File", "File copied successfully");
            return;
        }
    }
    else if (ui->rbMove->isChecked ())
    {
        usResult = moveFile (qstrPath1, qstrPath2);
        if (usResult != SUCCESS)
        {
            QMessageBox::information (this, "Move File", "File Move failed");
            return;
        }
        else if (usResult == OPERATION_CANCELLED)
        {
            return;
        }
        else
        {
            QMessageBox::information (this, "Move File", "File moved successfully");
            return;
        }
    }
    else if (ui->rbRemove->isChecked ())
    {
        usResult = removeFile (qstrPath1);
        if (usResult == SUCCESS)
        {
            ui->lePath1->setText ("");
            QMessageBox::information (this, "Remove File", "File deleted successfully");
            return;
        }
        else if (usResult == OPERATION_CANCELLED)
        {
            return;
        }
        else
        {
            QMessageBox::information (this, "Remove File", "File Delete failed");
            return;
        }
    }
    else if (ui->rbRename->isChecked ())
    {
        usResult = renameFile (qstrPath1, qstrPath2);
        if (usResult != SUCCESS)
        {
            QMessageBox::information (this, "Rename File", "File Rename failed");
            return;
        }
        else if (usResult == OPERATION_CANCELLED)
        {
            return;
        }
        else
        {
            QMessageBox::information (this, "Rename File", "File renamed successfully");
            return;
        }
    }

//    STATUS_BAR_FINAL_UPDATE;
}

void MainWindow::on_rbMove_toggled(bool checked)
{
    on_rbCopy_toggled (checked);
}

void MainWindow::on_rbRemove_toggled(bool checked)
{
    on_rbCopy_toggled (checked);
}

void MainWindow::on_rbRename_toggled(bool checked)
{
    on_rbCopy_toggled (checked);
}

void MainWindow::on_pbBrowseCancel_clicked()
{
    ui->lePath1->clear ();
    ui->lePath2->clear ();
    ui->stackedWidget->setCurrentIndex (0);
}
