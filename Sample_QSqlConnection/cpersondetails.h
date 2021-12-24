#ifndef CPERSONDETAILS_H
#define CPERSONDETAILS_H

#include <QDialog>
#include "structure.h"
#include "mainwindow.h"
#include "macros.h"

namespace Ui {
class CPersonDetails;
}

class CPersonDetails : public QDialog
{
    Q_OBJECT

public:
    explicit CPersonDetails(QWidget *parent = 0, S_PERSON_DETAILS *in_SPersonDetails = 0);
    ~CPersonDetails();

private slots:
    void on_pbPersonOK_clicked();

    void on_pbPersonUpdate_clicked();

    void on_pbPersonDelete_clicked();

private:
    Ui::CPersonDetails *ui;
};

#endif // CPERSONDETAILS_H
