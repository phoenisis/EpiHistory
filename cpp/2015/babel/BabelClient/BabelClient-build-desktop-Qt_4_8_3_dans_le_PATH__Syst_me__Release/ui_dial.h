/********************************************************************************
** Form generated from reading UI file 'dial.ui'
**
** Created: Tue Dec 11 20:47:24 2012
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAL_H
#define UI_DIAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dial
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *HangOutPushButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *LoginLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Dial)
    {
        if (Dial->objectName().isEmpty())
            Dial->setObjectName(QString::fromUtf8("Dial"));
        Dial->resize(249, 408);
        Dial->setMinimumSize(QSize(249, 408));
        gridLayoutWidget = new QWidget(Dial);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 310, 211, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        HangOutPushButton = new QPushButton(gridLayoutWidget);
        HangOutPushButton->setObjectName(QString::fromUtf8("HangOutPushButton"));

        gridLayout->addWidget(HangOutPushButton, 0, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(Dial);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 60, 211, 251));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(gridLayoutWidget_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(Dial);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(19, 20, 211, 41));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        LoginLabel = new QLabel(gridLayoutWidget_3);
        LoginLabel->setObjectName(QString::fromUtf8("LoginLabel"));

        gridLayout_3->addWidget(LoginLabel, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        retranslateUi(Dial);

        QMetaObject::connectSlotsByName(Dial);
    } // setupUi

    void retranslateUi(QWidget *Dial)
    {
        Dial->setWindowTitle(QApplication::translate("Dial", "Form", 0, QApplication::UnicodeUTF8));
        HangOutPushButton->setText(QApplication::translate("Dial", "Hang Out", 0, QApplication::UnicodeUTF8));
        LoginLabel->setText(QApplication::translate("Dial", "Login", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dial: public Ui_Dial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAL_H
