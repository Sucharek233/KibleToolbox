#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QDebug>
#include <QFile>
#include <QProcess>

class functionThread : public QThread
{
    Q_OBJECT

public:
    void setF(QString funct, int typ) {function = funct; type = typ;}

    void setCRDInfo(QString Command, int Pin) {command = Command; pin = Pin;}

protected:
    virtual void run();

signals:
   void update(QString);

private:
   QString function;
   int type;

   QString command;
   int pin;
};
#endif // THREAD_H
