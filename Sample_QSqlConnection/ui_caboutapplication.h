/********************************************************************************
** Form generated from reading UI file 'caboutapplication.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CABOUTAPPLICATION_H
#define UI_CABOUTAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CAboutApplication
{
public:
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *CAboutApplication)
    {
        if (CAboutApplication->objectName().isEmpty())
            CAboutApplication->setObjectName(QStringLiteral("CAboutApplication"));
        CAboutApplication->resize(475, 367);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CAboutApplication->sizePolicy().hasHeightForWidth());
        CAboutApplication->setSizePolicy(sizePolicy);
        CAboutApplication->setMinimumSize(QSize(475, 367));
        CAboutApplication->setMaximumSize(QSize(475, 367));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/images/about_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CAboutApplication->setWindowIcon(icon);
        CAboutApplication->setStyleSheet(QLatin1String("QMainWindow, QDialog, QMenu {\n"
"	background-color: rgb(10, 10, 10);\n"
"}\n"
"\n"
"QLabel	, QRadioButton, QCheckBox, QGroupBox {\n"
"color:rgba(255,255,255,255);\n"
"}\n"
"\n"
"QLineEdit, QTextEdit, QSpinBox, QDoubleSpinBox {\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(75,75,75);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QGroupBox{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(255, 255, 255, 20));\n"
"	border-radius: 9px;\n"
"	border: 2px;\n"
"	margin-top: 1em;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 2px 0 2px;\n"
"}\n"
"\n"
"QSplitter::handle {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(255, 255, 255, 40));\n"
"	margin: 5px 1px;	\n"
"}\n"
"\n"
"QSplitter::handle:pressed {\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTableWidget{\n"
"    background-color: rgb(75, 75, 75);\n"
"    background-colo"
                        "r: rgb(25, 25, 25);\n"
"    color: rgb(255, 255, 255);\n"
"    gridline-color: grey;\n"
"    border: 1px solid grey;\n"
"}\n"
"QTableWidget::item{\n"
"    text-align: center;\n"
"}\n"
"QTableCornerButton::section {\n"
"    background-color: rgb(75, 75, 75);\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: qlineargradient(spread:reflect, x1:0.511, y1:0, x2:0.517, y2:1, stop:0 rgba(40, 45, 50, 255), stop:0.5 rgba(60, 65, 70, 255), stop:1 rgba(40, 45, 50, 255));\n"
"    border: none;\n"
"    color: rgb(255, 255, 255);\n"
"    border : 1px solid grey;\n"
"}\n"
"\n"
"\n"
"QMenuBar {\n"
"	background-color: qlineargradient(spread:reflect, x1:0.511, y1:0, x2:0.517, y2:1, stop:0 rgba(40, 45, 50, 255), stop:0.5 rgba(60, 65, 70, 255), stop:1 rgba(40, 45, 50, 255));\n"
"	background-color: qlineargradient(spread:reflect, x1:0.511, y1:0, x2:0.517, y2:1, stop:0 rgba(36, 36, 36, 255), stop:0.409091 rgba(81, 81, 81, 255), stop:1 rgba(36, 36, 36, 255));\n"
"}\n"
"QMenuBar::item {\n"
"	background-color: qlineargradient"
                        "(spread:reflect, x1:0.511, y1:0, x2:0.517, y2:1, stop:0 rgba(40, 45, 50, 255), stop:0.5 rgba(60, 65, 70, 255), stop:1 rgba(40, 45, 50, 255));\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QMenu::item {\n"
"	background-color: rgb(70, 75, 80);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QMenuBar::item:hover, QMenu::item:selected, QSplitter::handle:pressed, QMenuBar::item:pressed {\n"
"	background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgba(106,106,106,255),stop:1 rgba(106,106,106,75));\n"
"	background-color: rgb(77, 154, 231);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(CAboutApplication);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(CAboutApplication);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(271, 71));
        label->setMaximumSize(QSize(271, 71));
        QFont font;
        font.setFamily(QStringLiteral("Mongolian Baiti"));
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_2 = new QLabel(CAboutApplication);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(81, 21));
        label_2->setMaximumSize(QSize(81, 21));
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_5 = new QLabel(CAboutApplication);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(161, 21));
        label_5->setMaximumSize(QSize(161, 21));
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        label_3 = new QLabel(CAboutApplication);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(81, 21));
        label_3->setMaximumSize(QSize(81, 21));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_4 = new QLabel(CAboutApplication);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(161, 21));
        label_4->setMaximumSize(QSize(161, 21));
        label_4->setFont(font1);

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        retranslateUi(CAboutApplication);

        QMetaObject::connectSlotsByName(CAboutApplication);
    } // setupUi

    void retranslateUi(QDialog *CAboutApplication)
    {
        CAboutApplication->setWindowTitle(QApplication::translate("CAboutApplication", "About Person Details", 0));
        label->setText(QApplication::translate("CAboutApplication", "Person Details", 0));
        label_2->setText(QApplication::translate("CAboutApplication", "Version", 0));
        label_5->setText(QApplication::translate("CAboutApplication", "0v01", 0));
        label_3->setText(QApplication::translate("CAboutApplication", "Author", 0));
        label_4->setText(QApplication::translate("CAboutApplication", "aravinth.rajalingam", 0));
    } // retranslateUi

};

namespace Ui {
    class CAboutApplication: public Ui_CAboutApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CABOUTAPPLICATION_H
