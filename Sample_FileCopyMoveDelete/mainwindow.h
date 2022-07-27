#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QFileDialog>
#include <QDebug>

#include <QThread>

#include "macros.h"
#include "errors.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool m_bCurrentPathSelect;

    QString m_qstrFilePath;

    void dragEnterEvent (QDragEnterEvent *evt);
    void dragLeaveEvent (QDragLeaveEvent *);
    void dropEvent (QDropEvent *evt);

    void updateFilepath (QString in_qstrFilepath);
    unsigned short copyFile (QString in_qstrSource, QString in_qstrDestination);
    unsigned short moveFile (QString in_qstrSource, QString in_qstrDestination);
    unsigned short removeFile (QString in_qstrFilePath);
    unsigned short renameFile (QString in_qstrOldFile, QString in_qstrNewFile);

private slots:
    void on_pbBrowse1_clicked();

    void on_pbBrowse2_clicked();

    void on_pbBrowse_clicked();

    void on_rbCopy_toggled(bool checked);

    void on_pbDo_clicked();

    void on_rbMove_toggled(bool checked);

    void on_rbRemove_toggled(bool checked);

    void on_rbRename_toggled(bool checked);

    void on_pbBrowseCancel_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
