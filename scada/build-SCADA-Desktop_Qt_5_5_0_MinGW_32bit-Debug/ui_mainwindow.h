/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *connectButton;
    QComboBox *COMcomboBox;
    QPushButton *exitButton;
    QPushButton *startMotor;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *zadanaLabel;
    QPushButton *zadaj;
    QCheckBox *notification;
    QTextEdit *emailEdit;
    QPushButton *saveEmailBtn;
    QSlider *Hslider;
    QSlider *Lslider;
    QLabel *label_3;
    QLabel *HLabel;
    QLabel *LLabel;
    QLabel *label_6;
    QPushButton *applyAlarmbtn;
    QCheckBox *setAlarm;
    QLCDNumber *x1_disp;
    QLCDNumber *x2_disp;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *CustomPlot;
    QCustomPlot *CustomPlot2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1366, 809);
        MainWindow->setMinimumSize(QSize(1366, 500));
        MainWindow->setMaximumSize(QSize(1366, 809));
        MainWindow->setSizeIncrement(QSize(1, 1));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1366, 768));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 131, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(330, 10, 131, 41));
        QFont font1;
        font1.setPointSize(16);
        connectButton->setFont(font1);
        COMcomboBox = new QComboBox(centralWidget);
        COMcomboBox->setObjectName(QStringLiteral("COMcomboBox"));
        COMcomboBox->setGeometry(QRect(190, 10, 131, 41));
        COMcomboBox->setFont(font1);
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(1200, 10, 131, 41));
        exitButton->setFont(font1);
        startMotor = new QPushButton(centralWidget);
        startMotor->setObjectName(QStringLiteral("startMotor"));
        startMotor->setGeometry(QRect(720, 10, 160, 41));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(startMotor->sizePolicy().hasHeightForWidth());
        startMotor->setSizePolicy(sizePolicy);
        startMotor->setFont(font1);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 590, 500, 41));
        horizontalSlider->setMinimum(-180);
        horizontalSlider->setMaximum(180);
        horizontalSlider->setSingleStep(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 550, 201, 31));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        zadanaLabel = new QLabel(centralWidget);
        zadanaLabel->setObjectName(QStringLiteral("zadanaLabel"));
        zadanaLabel->setGeometry(QRect(280, 550, 141, 31));
        zadanaLabel->setFont(font1);
        zadanaLabel->setFrameShadow(QFrame::Sunken);
        zadaj = new QPushButton(centralWidget);
        zadaj->setObjectName(QStringLiteral("zadaj"));
        zadaj->setGeometry(QRect(440, 550, 131, 41));
        zadaj->setFont(font1);
        notification = new QCheckBox(centralWidget);
        notification->setObjectName(QStringLiteral("notification"));
        notification->setGeometry(QRect(1170, 660, 151, 41));
        notification->setFont(font1);
        emailEdit = new QTextEdit(centralWidget);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));
        emailEdit->setGeometry(QRect(1050, 560, 271, 31));
        QFont font3;
        font3.setPointSize(12);
        emailEdit->setFont(font3);
        saveEmailBtn = new QPushButton(centralWidget);
        saveEmailBtn->setObjectName(QStringLiteral("saveEmailBtn"));
        saveEmailBtn->setGeometry(QRect(1190, 610, 131, 41));
        saveEmailBtn->setFont(font1);
        Hslider = new QSlider(centralWidget);
        Hslider->setObjectName(QStringLiteral("Hslider"));
        Hslider->setGeometry(QRect(660, 540, 41, 221));
        Hslider->setMinimum(-180);
        Hslider->setMaximum(180);
        Hslider->setSingleStep(10);
        Hslider->setOrientation(Qt::Vertical);
        Lslider = new QSlider(centralWidget);
        Lslider->setObjectName(QStringLiteral("Lslider"));
        Lslider->setGeometry(QRect(1000, 550, 41, 221));
        Lslider->setMinimum(-180);
        Lslider->setMaximum(180);
        Lslider->setSingleStep(10);
        Lslider->setOrientation(Qt::Vertical);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(720, 530, 100, 20));
        label_3->setFont(font1);
        HLabel = new QLabel(centralWidget);
        HLabel->setObjectName(QStringLiteral("HLabel"));
        HLabel->setGeometry(QRect(720, 580, 131, 20));
        HLabel->setFont(font1);
        LLabel = new QLabel(centralWidget);
        LLabel->setObjectName(QStringLiteral("LLabel"));
        LLabel->setGeometry(QRect(870, 580, 131, 20));
        LLabel->setFont(font1);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(870, 530, 71, 20));
        label_6->setFont(font1);
        applyAlarmbtn = new QPushButton(centralWidget);
        applyAlarmbtn->setObjectName(QStringLiteral("applyAlarmbtn"));
        applyAlarmbtn->setGeometry(QRect(780, 710, 131, 41));
        applyAlarmbtn->setFont(font1);
        setAlarm = new QCheckBox(centralWidget);
        setAlarm->setObjectName(QStringLiteral("setAlarm"));
        setAlarm->setGeometry(QRect(1170, 710, 131, 41));
        setAlarm->setFont(font1);
        x1_disp = new QLCDNumber(centralWidget);
        x1_disp->setObjectName(QStringLiteral("x1_disp"));
        x1_disp->setGeometry(QRect(60, 690, 201, 51));
        x1_disp->setSmallDecimalPoint(true);
        x1_disp->setDigitCount(5);
        x2_disp = new QLCDNumber(centralWidget);
        x2_disp->setObjectName(QStringLiteral("x2_disp"));
        x2_disp->setGeometry(QRect(370, 690, 201, 51));
        x2_disp->setSmallDecimalPoint(true);
        x2_disp->setDigitCount(5);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 650, 201, 31));
        label_4->setFont(font2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 650, 201, 31));
        label_5->setFont(font2);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1050, 530, 181, 20));
        label_7->setFont(font1);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 70, 1321, 441));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        CustomPlot = new QCustomPlot(layoutWidget);
        CustomPlot->setObjectName(QStringLiteral("CustomPlot"));

        horizontalLayout->addWidget(CustomPlot);

        CustomPlot2 = new QCustomPlot(layoutWidget);
        CustomPlot2->setObjectName(QStringLiteral("CustomPlot2"));

        horizontalLayout->addWidget(CustomPlot2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 1366, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setFont(font1);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SCADA", 0));
        label->setText(QApplication::translate("MainWindow", "Port COM:", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Po\305\202\304\205cz", 0));
        exitButton->setText(QApplication::translate("MainWindow", "Zamknij", 0));
        startMotor->setText(QApplication::translate("MainWindow", "Uruchom silnik", 0));
        label_2->setText(QApplication::translate("MainWindow", "Warto\305\233\304\207 zadana:", 0));
        zadanaLabel->setText(QApplication::translate("MainWindow", "0", 0));
        zadaj->setText(QApplication::translate("MainWindow", "Zadaj", 0));
        notification->setText(QApplication::translate("MainWindow", "Powiadmenie", 0));
        saveEmailBtn->setText(QApplication::translate("MainWindow", "Zapisz", 0));
        label_3->setText(QApplication::translate("MainWindow", "H Limit", 0));
        HLabel->setText(QString());
        LLabel->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "L Limit", 0));
        applyAlarmbtn->setText(QApplication::translate("MainWindow", "Zatwierd\305\272", 0));
        setAlarm->setText(QApplication::translate("MainWindow", "Alarm", 0));
        label_4->setText(QApplication::translate("MainWindow", "Po\305\202o\305\274enie [rad]", 0));
        label_5->setText(QApplication::translate("MainWindow", "Pr\304\231dko\305\233\304\207 [rad/s]", 0));
        label_7->setText(QApplication::translate("MainWindow", "Adres e-mail:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
