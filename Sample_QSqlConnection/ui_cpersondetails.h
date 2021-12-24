/********************************************************************************
** Form generated from reading UI file 'cpersondetails.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPERSONDETAILS_H
#define UI_CPERSONDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CPersonDetails
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLineEdit *leDisplayName;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *leDisplayAge;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *leDisplayQualification;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_8;
    QPlainTextEdit *teDisplayAddress;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pbPersonUpdate;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pbPersonDelete;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pbPersonOK;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QDialog *CPersonDetails)
    {
        if (CPersonDetails->objectName().isEmpty())
            CPersonDetails->setObjectName(QStringLiteral("CPersonDetails"));
        CPersonDetails->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CPersonDetails->sizePolicy().hasHeightForWidth());
        CPersonDetails->setSizePolicy(sizePolicy);
        CPersonDetails->setMinimumSize(QSize(640, 480));
        CPersonDetails->setMaximumSize(QSize(640, 480));
        verticalLayout = new QVBoxLayout(CPersonDetails);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(CPersonDetails);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(92, 21));
        QFont font;
        font.setPointSize(13);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        leDisplayName = new QLineEdit(CPersonDetails);
        leDisplayName->setObjectName(QStringLiteral("leDisplayName"));
        sizePolicy.setHeightForWidth(leDisplayName->sizePolicy().hasHeightForWidth());
        leDisplayName->setSizePolicy(sizePolicy);
        leDisplayName->setMinimumSize(QSize(301, 20));
        leDisplayName->setMaximumSize(QSize(301, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(20);
        leDisplayName->setFont(font1);
        leDisplayName->setReadOnly(true);

        horizontalLayout_5->addWidget(leDisplayName);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(CPersonDetails);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(92, 21));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        leDisplayAge = new QLineEdit(CPersonDetails);
        leDisplayAge->setObjectName(QStringLiteral("leDisplayAge"));
        sizePolicy.setHeightForWidth(leDisplayAge->sizePolicy().hasHeightForWidth());
        leDisplayAge->setSizePolicy(sizePolicy);
        leDisplayAge->setMinimumSize(QSize(301, 20));
        leDisplayAge->setMaximumSize(QSize(301, 20));
        leDisplayAge->setFont(font1);
        leDisplayAge->setReadOnly(true);

        horizontalLayout_4->addWidget(leDisplayAge);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(CPersonDetails);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(92, 21));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        leDisplayQualification = new QLineEdit(CPersonDetails);
        leDisplayQualification->setObjectName(QStringLiteral("leDisplayQualification"));
        sizePolicy.setHeightForWidth(leDisplayQualification->sizePolicy().hasHeightForWidth());
        leDisplayQualification->setSizePolicy(sizePolicy);
        leDisplayQualification->setMinimumSize(QSize(301, 20));
        leDisplayQualification->setMaximumSize(QSize(301, 20));
        leDisplayQualification->setFont(font1);
        leDisplayQualification->setReadOnly(true);

        horizontalLayout_3->addWidget(leDisplayQualification);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(CPersonDetails);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(92, 21));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        teDisplayAddress = new QPlainTextEdit(CPersonDetails);
        teDisplayAddress->setObjectName(QStringLiteral("teDisplayAddress"));
        teDisplayAddress->setMinimumSize(QSize(491, 161));
        teDisplayAddress->setFont(font);
        teDisplayAddress->setReadOnly(true);

        horizontalLayout->addWidget(teDisplayAddress);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        pbPersonUpdate = new QPushButton(CPersonDetails);
        pbPersonUpdate->setObjectName(QStringLiteral("pbPersonUpdate"));

        horizontalLayout_6->addWidget(pbPersonUpdate);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        pbPersonDelete = new QPushButton(CPersonDetails);
        pbPersonDelete->setObjectName(QStringLiteral("pbPersonDelete"));

        horizontalLayout_6->addWidget(pbPersonDelete);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        pbPersonOK = new QPushButton(CPersonDetails);
        pbPersonOK->setObjectName(QStringLiteral("pbPersonOK"));
        pbPersonOK->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	font-size: 13px;\n"
"}"));

        horizontalLayout_6->addWidget(pbPersonOK);

        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);


        retranslateUi(CPersonDetails);

        pbPersonUpdate->setDefault(false);
        pbPersonOK->setDefault(true);


        QMetaObject::connectSlotsByName(CPersonDetails);
    } // setupUi

    void retranslateUi(QDialog *CPersonDetails)
    {
        CPersonDetails->setWindowTitle(QApplication::translate("CPersonDetails", "Dialog", 0));
#ifndef QT_NO_WHATSTHIS
        CPersonDetails->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("CPersonDetails", "Name", 0));
        leDisplayName->setText(QString());
        label_2->setText(QApplication::translate("CPersonDetails", "Age", 0));
        leDisplayAge->setText(QString());
        label->setText(QApplication::translate("CPersonDetails", "Qualification", 0));
        leDisplayQualification->setText(QString());
        label_4->setText(QApplication::translate("CPersonDetails", "Address", 0));
        pbPersonUpdate->setText(QApplication::translate("CPersonDetails", "Update", 0));
        pbPersonDelete->setText(QApplication::translate("CPersonDetails", "Delete", 0));
        pbPersonOK->setText(QApplication::translate("CPersonDetails", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class CPersonDetails: public Ui_CPersonDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPERSONDETAILS_H
