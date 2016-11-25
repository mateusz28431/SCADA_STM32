#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
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

private slots:
    void on_exitButton_clicked();
    void connect2controller();
    void StartStopMotor();
    void RecieveData();
    void zadanaChanged();
    void zadajPolozenie();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QString portName;
    motorState state;
    QByteArray r_data;
    int wartosc_zadana;
    double x1,x2;
};

#endif // MAINWINDOW_H
