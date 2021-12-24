#ifndef MACROS
#define MACROS

/* DB PARAMETERS */
#define DBPARAM_CONNECTION  "QSQLITE"
#define DBPARAM_HOST_NAME   "localhost"
#define DBPARAM_USER_NAME   "root"
#define DBPARAM_PASSWORD    "root"
#define DBPARAM_DB_NAME     "SamplePrjtDB.db"
#define DBPARAM_TABLE_NAME  "PersonDetails"

/* MESSAGEBOX */
#define TXT_CONNECTION_TITLE        "DB Connection"
#define TXT_APPLICAITON_TITLE       "Person Information Application"
#define MSGBOX_NO_DATA      {\
    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "No data to display");\
    ui->twDisplayWidget->setCurrentIndex (TAB_ADD_PERSON);\
}

/* SQL ERRORS */
#define ERR_QUERY_EXEC       -1

/* WIDGET TAB INDEX */
#define TAB_ADD_PERSON       0
#define TAB_UPDATE_PERSON    1
#define TAB_VIEW_PERSON      2
#define TAB_DELETE_PERSON    3

/* HIDE/SHOW OPERATION */
#define DELETE_TAB_HIDE {\
    ui->leDeleteQualification->hide ();\
    ui->leDeleteAge->hide ();\
    }
#define DELETE_TAB_SHOW {\
    ui->leDeleteQualification->show ();\
    ui->leDeleteAge->show ();\
    }
#define UPDATE_TAB_HIDE {\
    ui->cmbNewQualification->hide ();\
    ui->sbNewAge->hide ();\
    }
#define UPDATE_TAB_SHOW {\
    ui->cmbNewQualification->show ();\
    ui->sbNewAge->show ();\
    }

/* SQL TABLE COLUMN INDEX */
enum SQL_TABLE_INDEX
{
    TBL_IDX_Name = 1,
    TBL_IDX_Age,
    TBL_IDX_Qualification,
    TBL_IDX_Address
};

/* INPUT VALIDATIONS */
#define CHECK_PERSON_EXISTS(strName) if (checkPersonExists (strName) > 0)\
{\
    qDebug("Person exists");\
    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Person already exists");\
    ui->leName->setFocus ();\
    ui->leName->selectAll ();\
    return false;\
}

#define VALIDATION_NAME(strName) if (strName.isEmpty ())\
{\
    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Enter the Person Name");\
    ui->leName->selectAll ();\
    ui->leName->setFocus ();\
    return;\
}\
else if (validateName (strName.toStdString ()) == INVALID_NAME)\
{\
    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Enter a VALID Name<br/><br/><code style=\"font-size: 13px;\">Letter should be lower case, Period (.) or Underscore (_)</code>");\
    ui->leName->selectAll ();\
    ui->leName->setFocus ();\
    return;\
}\
else {}

#define VALIDATION_AGE(iAge) if (iAge <= 0)\
{\
    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Enter a valid Age");\
    ui->sbAge->setFocus ();\
    return;\
}\
else if (iAge < 13)\
{\
    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Your age <small><code>(&lt;13)</code></small> is not allowed");\
    ui->sbAge->setFocus ();\
    return;\
}\
else {}

#define VALIDATION_ADDRESS(strAddress) if(strAddress.isEmpty ())\
{\
    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Enter Address");\
    ui->teAddress->setFocus ();\
    return;\
}\
else if (strAddress.length () < 20)\
{\
    QMessageBox::information (this, TXT_APPLICAITON_TITLE, "Enter valid Address");\
    ui->teAddress->setFocus ();\
    ui->teAddress->selectAll ();\
    return;\
}\
else {}

/* NAME VALIDATIONH */
#define VALID_NAME      0
#define INVALID_NAME    1

#define _SUCCESS_       0


#endif // MACROS

