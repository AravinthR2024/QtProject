#include "cpersondetails.h"
#include "ui_cpersondetails.h"

CPersonDetails::CPersonDetails(QWidget *parent, S_PERSON_DETAILS *in_SPersonDetails) :
    QDialog(parent),
    ui(new Ui::CPersonDetails)
{
    ui->setupUi(this);
    ui->leDisplayName->setText (in_SPersonDetails->strName);
    ui->leDisplayAge->setText (QString::number (in_SPersonDetails->iAge));
    ui->leDisplayQualification->setText (in_SPersonDetails->strQualification);
    ui->teDisplayAddress->setPlainText (in_SPersonDetails->strAddress);

    QString strWindowTitle;
    strWindowTitle.sprintf ("Person Details : %s", in_SPersonDetails->strName.toStdString ().c_str ());
    this->setWindowTitle (strWindowTitle);
}

CPersonDetails::~CPersonDetails()
{
    delete ui;
}

void CPersonDetails::on_pbPersonOK_clicked()
{
    this->close ();
}

void CPersonDetails::on_pbPersonUpdate_clicked()
{
    ((MainWindow*)this->parent ())->updatePersonFuncCall (ui->leDisplayName->text ());
    this->close ();
}

void CPersonDetails::on_pbPersonDelete_clicked()
{
    QString strQuestionString;
    strQuestionString.sprintf ("Sure want to delete '%s'", ui->leDisplayName->text ().toStdString ().c_str ());
    int iOk = QMessageBox::question (this, TXT_APPLICAITON_TITLE, strQuestionString, QMessageBox::Yes | QMessageBox::No, \
                                     QMessageBox::Yes);
    if (iOk == QMessageBox::No)
    {
        return;
    }
    this->close ();
    ((MainWindow*)this->parent ())->deletePersonFuncCall (ui->leDisplayName->text ());
}
