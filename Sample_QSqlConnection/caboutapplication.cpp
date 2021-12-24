#include "caboutapplication.h"
#include "ui_caboutapplication.h"

CAboutApplication::CAboutApplication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CAboutApplication)
{
    ui->setupUi(this);
}

CAboutApplication::~CAboutApplication()
{
    delete ui;
}
