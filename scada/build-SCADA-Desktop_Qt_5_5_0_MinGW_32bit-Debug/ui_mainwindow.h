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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

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
    QTextEdit *textEdit;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *zadanaLabel;
    QPushButton *zadaj;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1366, 807);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1366, 768));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 61, 16));
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(200, 10, 75, 23));
        COMcomboBox = new QComboBox(centralWidget);
        COMcomboBox->setObjectName(QStringLiteral("COMcomboBox"));
        COMcomboBox->setGeometry(QRect(110, 10, 69, 22));
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(590, 10, 75, 23));
        startMotor = new QPushButton(centralWidget);
        startMotor->setObjectName(QStringLiteral("startMotor"));
        startMotor->setGeometry(QRect(584, 50, 81, 31));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(110, 140, 301, 91));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(440, 410, 160, 22));
        horizontalSlider->setMaximum(10);
        horizontalSlider->setSingleStep(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 380, 91, 21));
        zadanaLabel = new QLabel(centralWidget);
        zadanaLabel->setObjectName(QStringLiteral("zadanaLabel"));
        zadanaLabel->setGeometry(QRect(540, 380, 61, 20));
        zadanaLabel->setFrameShadow(QFrame::Sunken);
        zadaj = new QPushButton(centralWidget);
        zadaj->setObjectName(QStringLiteral("zadaj"));
        zadaj->setGeometry(QRect(440, 440, 81, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 1366, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Port COM:", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Po\305\202\304\205cz", 0));
        exitButton->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", 0));
        startMotor->setText(QApplication::translate("MainWindow", "Uruchom silnik", 0));
        label_2->setText(QApplication::translate("MainWindow", "Warto\305\233\304\207 zadana:", 0));
        zadanaLabel->setText(QApplication::translate("MainWindow", "0", 0));
        zadaj->setText(QApplication::translate("MainWindow", "Zadaj", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
