#ifndef SENSORS_H
#define SENSORS_H

#include <QAccelerometer>
#include <QAmbientTemperatureSensor>
#include <QCompass>
#include <QGyroscope>
#include <QObject>
#include <QPressureSensor>

class Sensors;
class DashBoard;

class Sensors : public QObject
{
    Q_OBJECT

public:
    explicit Sensors(QObject *parent = nullptr);
    explicit Sensors(DashBoard *dashboard, QObject *parent = nullptr);
    Q_INVOKABLE void Comp();
    Q_INVOKABLE void Accel();
    Q_INVOKABLE void Gyro();
    Q_INVOKABLE void Temperature();
    Q_INVOKABLE void Pressure();


public slots:
    void updateCompass();
    void updateAccel();
    void updateGyro();
    void updateAmbientSens();
    void updatePressureSens();
    void error(int);

private:
    DashBoard *m_dashboard;

    QCompass *Compass;
    QAccelerometer *Accelerometer;
    QGyroscope *Gyroscope;
    QAmbientTemperatureSensor *AmbientTemperatureSensor;
    QPressureSensor *PressureSensor;
    QCompassReading *compass_reading;
    QAccelerometerReading *accel_reading;
    QGyroscopeReading *gyro_reading;
    QAmbientTemperatureReading *temp_reading;
    QPressureReading *press_reading;
};

#endif  // SENSORS_H
