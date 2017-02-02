#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QFile>
#include <QTextStream>
#include "smtp.h"
namespace Ui {



class MainWindow;
}
enum motorState {
    start,
    stop
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupPlot();

private slots:
    void on_exitButton_clicked();
    void connect2controller();
    void StartStopMotor();
    void RecieveData();
    void zadanaChanged();
    void zadajPolozenie();
    void sendEmail();
    void saveAdress();
    void hSliderChanged();
    void lSliderChanged();
    void applyAlarams();
    void alarmStatusChanged();


private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QString portName;
    motorState state;
    QByteArray r_data;
    float wartosc_zadana;
    double x1,x2;
    float hlimit, llimit;
    bool halarm;
    bool lalarm;
    bool alarmCanBeSet;
    bool emailSent;
    QPalette* sample_palette;
    QString email;
    QString tresc;
    Smtp* smtp;

signals:
    void EmailSig();


};

#endif // MAINWINDOW_H
