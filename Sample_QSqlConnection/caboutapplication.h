#ifndef CABOUTAPPLICATION_H
#define CABOUTAPPLICATION_H

#include <QDialog>

namespace Ui {
class CAboutApplication;
}

class CAboutApplication : public QDialog
{
    Q_OBJECT

public:
    explicit CAboutApplication(QWidget *parent = 0);
    ~CAboutApplication();

private:
    Ui::CAboutApplication *ui;
};

#endif // CABOUTAPPLICATION_H
