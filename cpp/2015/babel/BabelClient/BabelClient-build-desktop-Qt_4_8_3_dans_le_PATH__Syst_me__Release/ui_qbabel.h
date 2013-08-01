/********************************************************************************
** Form generated from reading UI file 'qbabel.ui'
**
** Created: Tue Dec 11 20:47:24 2012
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QBABEL_H
#define UI_QBABEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QBabel
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionSettings;
    QAction *actionQuit;
    QAction *actionAbout_QBabel;
    QAction *actionConnect_2;
    QAction *actionDisconnected;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QListView *tree;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *AddPushButton;
    QLineEdit *AddLineEdit;
    QPushButton *CallPushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QComboBox *comboBox;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *ServerLabel;
    QSpacerItem *verticalSpacer;
    QLineEdit *PortLineEdit;
    QLineEdit *LoginLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *LoginLabel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *PasswordLabel;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *SettingLabel;
    QLineEdit *PasswordLineEdit;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *ServerLineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *PortLabel;
    QSpacerItem *verticalSpacer_5;
    QPushButton *OkPushButton;
    QPushButton *CancelPushButton;
    QPushButton *CreatPushButton;
    QMenuBar *menuBar;
    QMenu *menuFichie;
    QMenu *menuHelp;
    QMenu *menuContact;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QBabel)
    {
        if (QBabel->objectName().isEmpty())
            QBabel->setObjectName(QString::fromUtf8("QBabel"));
        QBabel->resize(249, 408);
        QBabel->setMinimumSize(QSize(249, 408));
        QBabel->setMaximumSize(QSize(249, 408));
        actionConnect = new QAction(QBabel);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionDisconnect = new QAction(QBabel);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionSettings = new QAction(QBabel);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionQuit = new QAction(QBabel);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout_QBabel = new QAction(QBabel);
        actionAbout_QBabel->setObjectName(QString::fromUtf8("actionAbout_QBabel"));
        actionConnect_2 = new QAction(QBabel);
        actionConnect_2->setObjectName(QString::fromUtf8("actionConnect_2"));
        actionDisconnected = new QAction(QBabel);
        actionDisconnected->setObjectName(QString::fromUtf8("actionDisconnected"));
        centralWidget = new QWidget(QBabel);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 221, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tree = new QListView(gridLayoutWidget);
        tree->setObjectName(QString::fromUtf8("tree"));
        tree->setMinimumSize(QSize(219, 269));
        tree->setMaximumSize(QSize(219, 269));

        gridLayout->addWidget(tree, 0, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(9, 309, 221, 51));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        AddPushButton = new QPushButton(gridLayoutWidget_2);
        AddPushButton->setObjectName(QString::fromUtf8("AddPushButton"));

        gridLayout_2->addWidget(AddPushButton, 0, 1, 1, 1);

        AddLineEdit = new QLineEdit(gridLayoutWidget_2);
        AddLineEdit->setObjectName(QString::fromUtf8("AddLineEdit"));

        gridLayout_2->addWidget(AddLineEdit, 0, 0, 1, 1);

        CallPushButton = new QPushButton(gridLayoutWidget_2);
        CallPushButton->setObjectName(QString::fromUtf8("CallPushButton"));

        gridLayout_2->addWidget(CallPushButton, 0, 2, 1, 1);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 10, 260, 289));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, comboBox);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 241, 311));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 9, 0, 1, 1);

        ServerLabel = new QLabel(gridLayoutWidget_3);
        ServerLabel->setObjectName(QString::fromUtf8("ServerLabel"));

        gridLayout_3->addWidget(ServerLabel, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        PortLineEdit = new QLineEdit(gridLayoutWidget_3);
        PortLineEdit->setObjectName(QString::fromUtf8("PortLineEdit"));

        gridLayout_3->addWidget(PortLineEdit, 4, 2, 1, 1);

        LoginLineEdit = new QLineEdit(gridLayoutWidget_3);
        LoginLineEdit->setObjectName(QString::fromUtf8("LoginLineEdit"));

        gridLayout_3->addWidget(LoginLineEdit, 6, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 6, 1, 1, 1);

        LoginLabel = new QLabel(gridLayoutWidget_3);
        LoginLabel->setObjectName(QString::fromUtf8("LoginLabel"));

        gridLayout_3->addWidget(LoginLabel, 6, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 8, 1, 1, 1);

        PasswordLabel = new QLabel(gridLayoutWidget_3);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));

        gridLayout_3->addWidget(PasswordLabel, 8, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 5, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 3, 0, 1, 1);

        SettingLabel = new QLabel(gridLayoutWidget_3);
        SettingLabel->setObjectName(QString::fromUtf8("SettingLabel"));

        gridLayout_3->addWidget(SettingLabel, 0, 1, 1, 1);

        PasswordLineEdit = new QLineEdit(gridLayoutWidget_3);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));

        gridLayout_3->addWidget(PasswordLineEdit, 8, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 7, 0, 1, 1);

        ServerLineEdit = new QLineEdit(gridLayoutWidget_3);
        ServerLineEdit->setObjectName(QString::fromUtf8("ServerLineEdit"));

        gridLayout_3->addWidget(ServerLineEdit, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 1, 1, 1);

        PortLabel = new QLabel(gridLayoutWidget_3);
        PortLabel->setObjectName(QString::fromUtf8("PortLabel"));

        gridLayout_3->addWidget(PortLabel, 4, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 0, 0, 1, 1);

        OkPushButton = new QPushButton(gridLayoutWidget_3);
        OkPushButton->setObjectName(QString::fromUtf8("OkPushButton"));

        gridLayout_3->addWidget(OkPushButton, 10, 2, 1, 1);

        CancelPushButton = new QPushButton(gridLayoutWidget_3);
        CancelPushButton->setObjectName(QString::fromUtf8("CancelPushButton"));

        gridLayout_3->addWidget(CancelPushButton, 10, 1, 1, 1);

        CreatPushButton = new QPushButton(gridLayoutWidget_3);
        CreatPushButton->setObjectName(QString::fromUtf8("CreatPushButton"));

        gridLayout_3->addWidget(CreatPushButton, 10, 0, 1, 1);

        QBabel->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QBabel);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 249, 22));
        menuFichie = new QMenu(menuBar);
        menuFichie->setObjectName(QString::fromUtf8("menuFichie"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuContact = new QMenu(menuBar);
        menuContact->setObjectName(QString::fromUtf8("menuContact"));
        QBabel->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QBabel);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QBabel->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QBabel);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QBabel->setStatusBar(statusBar);

        menuBar->addAction(menuFichie->menuAction());
        menuBar->addAction(menuContact->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFichie->addAction(actionSettings);
        menuFichie->addAction(actionQuit);
        menuHelp->addAction(actionAbout_QBabel);
        menuContact->addAction(actionConnect_2);
        menuContact->addAction(actionDisconnected);

        retranslateUi(QBabel);

        QMetaObject::connectSlotsByName(QBabel);
    } // setupUi

    void retranslateUi(QMainWindow *QBabel)
    {
        QBabel->setWindowTitle(QApplication::translate("QBabel", "QBabel", 0, QApplication::UnicodeUTF8));
        actionConnect->setText(QApplication::translate("QBabel", "Connect", 0, QApplication::UnicodeUTF8));
        actionDisconnect->setText(QApplication::translate("QBabel", "Disconnect", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("QBabel", "Settings", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("QBabel", "Quit", 0, QApplication::UnicodeUTF8));
        actionAbout_QBabel->setText(QApplication::translate("QBabel", "About QBabel", 0, QApplication::UnicodeUTF8));
        actionConnect_2->setText(QApplication::translate("QBabel", "Connect", 0, QApplication::UnicodeUTF8));
        actionDisconnected->setText(QApplication::translate("QBabel", "Disconnected", 0, QApplication::UnicodeUTF8));
        AddPushButton->setText(QApplication::translate("QBabel", "Add", 0, QApplication::UnicodeUTF8));
        CallPushButton->setText(QApplication::translate("QBabel", "Call", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("QBabel", "Connected", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QBabel", "Disconnected", 0, QApplication::UnicodeUTF8)
        );
        ServerLabel->setText(QApplication::translate("QBabel", "Server :", 0, QApplication::UnicodeUTF8));
        LoginLabel->setText(QApplication::translate("QBabel", "Login :", 0, QApplication::UnicodeUTF8));
        PasswordLabel->setText(QApplication::translate("QBabel", "Password : ", 0, QApplication::UnicodeUTF8));
        SettingLabel->setText(QApplication::translate("QBabel", "Settings", 0, QApplication::UnicodeUTF8));
        PortLabel->setText(QApplication::translate("QBabel", "Port :", 0, QApplication::UnicodeUTF8));
        OkPushButton->setText(QApplication::translate("QBabel", "OK", 0, QApplication::UnicodeUTF8));
        CancelPushButton->setText(QApplication::translate("QBabel", "Cancel", 0, QApplication::UnicodeUTF8));
        CreatPushButton->setText(QApplication::translate("QBabel", "Creat", 0, QApplication::UnicodeUTF8));
        menuFichie->setTitle(QApplication::translate("QBabel", "Fichier", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("QBabel", "Help", 0, QApplication::UnicodeUTF8));
        menuContact->setTitle(QApplication::translate("QBabel", "Contact", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QBabel: public Ui_QBabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QBABEL_H
