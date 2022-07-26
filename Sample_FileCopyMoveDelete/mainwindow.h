#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QDebug>

#include <QThread>

#include "macros.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int m_iCurrentPage;
    bool m_bCurrentPathSelect;
    QString m_qstrFilePath;

    void dragEnterEvent (QDragEnterEvent *evt);
    void dragLeaveEvent (QDragLeaveEvent *evt);
    void dropEvent (QDropEvent *evt);

    void updateFilepath (QString in_qstrFilepath);

private slots:
    void on_pbBrowse1_clicked();

    void on_pbBrowse2_clicked();

    void on_pbBrowse_clicked();

    void on_rbCopy_toggled(bool checked);

    void on_pbDo_clicked();

    void on_rbMove_toggled(bool checked);

    void on_rbRemove_toggled(bool checked);

    void on_rbRename_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
