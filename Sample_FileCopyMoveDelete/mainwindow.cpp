#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex (0);

//    m_iCurrentPage = 0;
    m_bCurrentPathSelect = 0;
    m_qstrFilePath = QString();

    ui->statusBar->showMessage ("HIIIIII");

    ui->rbCopy->setChecked (true);
    ui->lblLabel1->setText ("Source file");
    ui->lblLabel2->setText ("Destination folder");

    setAcceptDrops (true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *evt)
{
    ui->lblDropInfo->setStyleSheet ("QLabel { border: 3px solid blue }");
    if (ui->stackedWidget->currentIndex () == 1 && evt->mimeData ()->hasUrls ())
    {
        evt->acceptProposedAction ();
    }
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *evt)
{
    ui->lblDropInfo->setStyleSheet ("QLabel { border: none }");
}

void MainWindow::dropEvent(QDropEvent *evt)
{
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
    }
    else
    {
        ui->lePath1->setText (in_qstrFilepath);
    }
}

void MainWindow::on_pbBrowse1_clicked()
{
    ui->stackedWidget->setCurrentIndex (1);

    m_bCurrentPathSelect = 0;

    ui->lePath1->setText (m_qstrFilePath);
}

void MainWindow::on_pbBrowse2_clicked()
{
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
        CHANGE_TEXT("File Path", "New Name", "&Rename", true);
    }
    else
    {
        QMessageBox::information (this, "Operation Error", "Please select a File Operation");
        return;
    }
}

void MainWindow::on_pbDo_clicked()
{
    STATUS_BAR_INITIAL_UPDATE;

    QThread::sleep (1);

    STATUS_BAR_FINAL_UPDATE;
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
