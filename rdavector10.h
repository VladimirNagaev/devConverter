#ifndef RDAVECTOR_H
#define RDAVECTOR_H

#include <QString>
#include <QByteArray>
#include <QVector>
#include <QDateTime>


class RdaVector10
{
private:
    int m_vectorNumber;
    QDateTime m_TimeOfThisVector; // date time format dd:hh:mm:ss:MMMM
    QByteArray m_ourVector;
    int m_adcPressureData;
    int m_adc_TP;
    int m_currentVoltage; // 0,1* (voltage bytes)
    int m_pressure; // MPa or Atm

    bool m_isValid = true;


public:
    static RdaVector10 fromBytes(QByteArray ourVector);
    //static QString fromVector(RdaVector10);

    QString toJson();
    QString toText();

    int getNumber();
    void setNumber(int nomber);

    int getADCPressure();
    //void setADCPressure(int newPressure);

    int getADC_Tp();

    int getCurrentVoltage();

    int getPressure();

    QByteArray getBytes();

    bool getValidness();

protected:


    RdaVector10();
    RdaVector10(QByteArray ourVector);
};

#endif // RDAVECTOR_H
