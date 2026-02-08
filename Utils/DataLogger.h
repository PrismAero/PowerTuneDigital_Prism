#ifndef DATALOGGER_H
#define DATALOGGER_H
#include <QObject>
#include <QThread>
#include <QTime>
#include <QTimer>

class datalogger;
class DashBoard;

class datalogger : public QObject
{
    Q_OBJECT


public:
    explicit datalogger(QObject *parent = nullptr);
    explicit datalogger(DashBoard *dashboard, QObject *parent = nullptr);
    Q_INVOKABLE void startLog(QString Logfilename);
    Q_INVOKABLE void stopLog();


public slots:

    void updateLog();
    void createHeader();

private:
    DashBoard *m_dashboard;
    QTimer m_updatetimer;
};

#endif  // DATALOGGER_H
