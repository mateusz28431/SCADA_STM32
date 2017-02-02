#ifndef SMTPTHREAD_H
#define SMTPTHREAD_H
#include "smtp.h"
#include <QThread>
class SmtpThread : public QThread
{
    Q_OBJECT
public:
    SmtpThread(QObject* parent = 0);
    void run();
signals:

public slots:
};

#endif // SMTPTHREAD_H

