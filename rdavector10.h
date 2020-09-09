#ifndef RDAVECTOR_H
#define RDAVECTOR_H

#include <QString>
#include <QByteArray>
#include <QVector>
#include <QDateTime>
#include <QDataStream>


class RdaVector10
{
private:
    int m_vectorNumber;
    int m_isAsVector;
    QDateTime m_TimeOfThisVector; // date time format dd:hh:mm:ss:MMMM
    QByteArray m_ourVector;
    int m_adcPressureData;
    int m_adc_TP;
    int m_currentVoltage; // 0,1* (voltage bytes)
    int m_pressure; // MPa or Atm

    bool m_isValid = true;
    bool m_isNull = false;


public:
    static RdaVector10 fromBytes(QByteArray ourVector);
    static RdaVector10 deserializeVectorFromText(QString text);
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

    int getAsAnotherVector();
    void setAsAnotherVector(int exVector);



    QByteArray getBytes();

    bool isNull();
    void nullThisVector(bool status);

    bool getValidness();
    void setValidnes(bool validnes);

    void deserializeFromText(QString text);
    //void deserializeFromJson(QString json);

protected:


    RdaVector10();
    RdaVector10(QByteArray ourVector);
};

#endif // RDAVECTOR_H
