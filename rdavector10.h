#ifndef RDAVECTOR_H
#define RDAVECTOR_H

#include <QByteArray>
#include <QDataStream>
#include <QDateTime>
#include <QString>
#include <QVector>

class RdaVector10
{
private:
    int m_vectorNumber;
    short m_isAsVector;
    QDateTime m_TimeOfThisVector; // date time format dd:hh:mm:ss:MMMM
    QByteArray m_ourVector;
    quint32 m_adcPressureData;
    quint16 m_adc_TP;
    float m_currentVoltage; // 0,1* (voltage bytes)
    quint32 m_pressure; // MPa or Atm

    bool m_isValid = true;
    bool m_isNull = false;

public:
    static RdaVector10 fromBytes(QByteArray ourVector);
    static RdaVector10 fromBytes(QByteArray ourVector, int vectoNumber);
    static RdaVector10 deserializeVectorFromText(QString text);
    static quint16 bytesToInt(quint8 byte1, quint8 byte2);
    static quint32 bytesToInt(quint8 byte1, quint8 byte2, quint8 byte3);
    static int bytesToInt(quint8 byte1, quint8 byte2, quint8 byte3, quint8 byte4);
    static float fromBytesToFloat(quint8 byte4, quint8 byte3, quint8 byte2, quint8 byte1); // 7-first
    static QByteArray fromFloatToBytes(float i);
    //static QString fromVector(RdaVector10);

    QString toJson();
    QString toText();

    int getNumber();
    void setNumber(int nomber);

    int getADCPressure();
    //void setADCPressure(int newPressure);

    quint16 getADC_Tp();

    float getCurrentVoltage();

    quint32 getPressure();

    short getAsAnotherVector();
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
