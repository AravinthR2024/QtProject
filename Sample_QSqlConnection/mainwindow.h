#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>

#include <QMessageBox>
#include <QCloseEvent>
#include <QCompleter>
#include <QStringList>
#include <QList>
#include <QComboBox>
#include <QTextStream>

#include "macros.h"
#include "structure.h"
#include "caboutapplication.h"
#include "cpersondetails.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QSqlDatabase m_dbConn;

    QStringList m_strQualificationList;

    bool m_bIsNamesLoaded;
    bool m_bIsQualificationLoaded;

    bool createConnection ();
    bool establishTable ();
    bool addPerson (QString in_strName, int in_iAge, QString in_strQualification, QString in_strAddress);
    bool updatePerson (S_PERSON_DETAILS *in_SPersonDetails);
    int checkPersonExists (QString in_strName);
    bool retrieveColumnData (int in_iColumn, QStringList *out_strDataList);
    bool retrieveDataByName (QString in_strName, S_PERSON_DETAILS *out_SPersonDetails);
    bool retrieveAllData (QList<S_PERSON_DETAILS> *out_SPersonsDetailsList);

    void clearInputFields (int in_iTabIndex);
    int validateName (std::string in_strName);
    void loadAvailableNamesFromDB (QComboBox *in_cmbBox);
    void displayPersonDetails ();
    void displaySelectedPersonDetails (QString in_strName);
    void updatePersonFuncCall (QString in_strName);
    void deletePersonFuncCall (QString in_strName);

    void changeThemeState (bool in_bState);

    void closeEvent (QCloseEvent *evtClose);

    ~MainWindow();

private slots:
    void on_pbAdd_clicked();

    void on_leName_returnPressed();

    void on_actionAdd_Person_triggered();

    void on_actionView_Person_triggered();

    void on_actionUpdateDetails_triggered();

    void on_actionDelete_Persons_triggered();

    void on_actionQuit_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionAbout_Application_triggered();

    void on_twDisplayWidget_currentChanged(int index);

    void on_pbUpdate_clicked();

    void on_leUpdateName_currentIndexChanged(const QString &arg1);

    void on_twDetailsViewTable_clicked(const QModelIndex &index);

    void on_twDetailsViewTable_doubleClicked(const QModelIndex &index);

    void on_leDeleteName_currentIndexChanged(const QString &arg1);

    void on_pbDelete_clicked();

    void on_cbIsLightMode_stateChanged(int in_iEnableLightTheme);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
