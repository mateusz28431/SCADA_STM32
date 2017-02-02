#include "Smtpthread.h"

SmtpThread::SmtpThread(QObject *parent)
    : QThread(parent)
{

}

void SmtpThread::run()
{
    qDebug() << "I am in thread\n";
    Smtp smtp("testuser2846@gmail.com", "!Abc1234", "smtp.gmail.com",465);
    smtp.sendMail("testuser2846@gmail.com", "mateusz28431@gmail.com" , "ALARM!!!","Przekorczono wartości dopuszczalne");
    QThread::sleep(5000);

}
