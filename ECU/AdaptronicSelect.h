#ifndef ADAPTRONICSELECT_H
#define ADAPTRONICSELECT_H
#include <QModbusClient>
#include <QModbusDataUnit>
#include <QModbusReply>
#include <QObject>
#include <QtSerialPort/QSerialPort>


class DashBoard;
class Serialport;
class QModbusClient;
class QModbusReply;

class AdaptronicSelect : public QObject
{
    Q_OBJECT

public:
    explicit AdaptronicSelect(QObject *parent = nullptr);
    explicit AdaptronicSelect(DashBoard *dashboard, QObject *parent = nullptr);
    ~AdaptronicSelect() override;

private:
public slots:
    void openConnection(const QString &portName);
    void closeConnection();
    void AdaptronicStartStream();
    void readyToRead();
    void decodeAdaptronic(QModbusDataUnit serialdata);

private:
    DashBoard *m_dashboard;
    QModbusReply *lastRequest;
    QModbusClient *modbusDevice;
    QModbusDataUnit readRequest() const;


signals:
    void sig_adaptronicReadFinished();
};


#endif  // ADAPTRONICSELECT_H
