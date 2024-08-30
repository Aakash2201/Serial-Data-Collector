/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_configSerial;
    QLabel *label_speed;
    QLabel *label_dataBits;
    QLabel *label_stopBits;
    QLabel *label_parity;
    QLabel *label_flowControl;
    QComboBox *comboBox_speed;
    QComboBox *comboBox_dataBits;
    QComboBox *comboBox_parity;
    QComboBox *comboBox_stopBits;
    QComboBox *comboBox_flowControl;
    QComboBox *comboBox_comPort;
    QLabel *label_comPort;
    QPushButton *pushButton_open;
    QLabel *label_actionMsg;
    QTextEdit *Corr_Data_Display;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(500, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_configSerial = new QGroupBox(centralwidget);
        groupBox_configSerial->setObjectName(QString::fromUtf8("groupBox_configSerial"));
        groupBox_configSerial->setGeometry(QRect(14, 6, 470, 190));
        label_speed = new QLabel(groupBox_configSerial);
        label_speed->setObjectName(QString::fromUtf8("label_speed"));
        label_speed->setGeometry(QRect(10, 70, 110, 16));
        label_dataBits = new QLabel(groupBox_configSerial);
        label_dataBits->setObjectName(QString::fromUtf8("label_dataBits"));
        label_dataBits->setGeometry(QRect(10, 110, 110, 16));
        label_stopBits = new QLabel(groupBox_configSerial);
        label_stopBits->setObjectName(QString::fromUtf8("label_stopBits"));
        label_stopBits->setGeometry(QRect(285, 70, 70, 16));
        label_parity = new QLabel(groupBox_configSerial);
        label_parity->setObjectName(QString::fromUtf8("label_parity"));
        label_parity->setGeometry(QRect(285, 30, 70, 16));
        label_flowControl = new QLabel(groupBox_configSerial);
        label_flowControl->setObjectName(QString::fromUtf8("label_flowControl"));
        label_flowControl->setGeometry(QRect(285, 110, 70, 16));
        comboBox_speed = new QComboBox(groupBox_configSerial);
        comboBox_speed->setObjectName(QString::fromUtf8("comboBox_speed"));
        comboBox_speed->setGeometry(QRect(126, 68, 100, 20));
        comboBox_dataBits = new QComboBox(groupBox_configSerial);
        comboBox_dataBits->setObjectName(QString::fromUtf8("comboBox_dataBits"));
        comboBox_dataBits->setGeometry(QRect(126, 108, 100, 20));
        comboBox_parity = new QComboBox(groupBox_configSerial);
        comboBox_parity->setObjectName(QString::fromUtf8("comboBox_parity"));
        comboBox_parity->setGeometry(QRect(365, 28, 100, 20));
        comboBox_stopBits = new QComboBox(groupBox_configSerial);
        comboBox_stopBits->setObjectName(QString::fromUtf8("comboBox_stopBits"));
        comboBox_stopBits->setGeometry(QRect(365, 68, 100, 20));
        comboBox_flowControl = new QComboBox(groupBox_configSerial);
        comboBox_flowControl->setObjectName(QString::fromUtf8("comboBox_flowControl"));
        comboBox_flowControl->setGeometry(QRect(365, 108, 100, 20));
        comboBox_comPort = new QComboBox(groupBox_configSerial);
        comboBox_comPort->setObjectName(QString::fromUtf8("comboBox_comPort"));
        comboBox_comPort->setGeometry(QRect(126, 28, 100, 20));
        label_comPort = new QLabel(groupBox_configSerial);
        label_comPort->setObjectName(QString::fromUtf8("label_comPort"));
        label_comPort->setGeometry(QRect(13, 30, 100, 16));
        pushButton_open = new QPushButton(groupBox_configSerial);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(10, 150, 80, 24));
        label_actionMsg = new QLabel(groupBox_configSerial);
        label_actionMsg->setObjectName(QString::fromUtf8("label_actionMsg"));
        label_actionMsg->setGeometry(QRect(130, 150, 331, 20));
        Corr_Data_Display = new QTextEdit(centralwidget);
        Corr_Data_Display->setObjectName(QString::fromUtf8("Corr_Data_Display"));
        Corr_Data_Display->setGeometry(QRect(15, 210, 360, 60));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_configSerial->setTitle(QCoreApplication::translate("MainWindow", "Configure the serial line", nullptr));
        label_speed->setText(QCoreApplication::translate("MainWindow", "Speed ( BaudRate )", nullptr));
        label_dataBits->setText(QCoreApplication::translate("MainWindow", "Data bits", nullptr));
        label_stopBits->setText(QCoreApplication::translate("MainWindow", "Stop bits", nullptr));
        label_parity->setText(QCoreApplication::translate("MainWindow", "Parity", nullptr));
        label_flowControl->setText(QCoreApplication::translate("MainWindow", "Flow control", nullptr));
        label_comPort->setText(QCoreApplication::translate("MainWindow", "Com-Port name", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        label_actionMsg->setText(QCoreApplication::translate("MainWindow", "ACTION MSG BAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
