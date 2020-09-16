#ifndef RDADEVDATA_H
#define RDADEVDATA_H

#include <QDateTime>
#include <QFile>
#include <QString>
#include <QVector>

#include <rdavector10.h>

class RdaDevData
{
private:
    int m_deviceNumber;
    int m_numberOfVectors;

    QVector<RdaVector10> m_dataVectors;
    QByteArray m_headerVector;
    QByteArray inputedFile;

    int m_interval_1_regTime;
    int m_interval_2_regTime;
    int m_interval_3_regTime;
    int m_interval_4_regTime;
    int m_interval_5_regTime;
    int m_interval_6_regTime;
    int m_interval_7_regTime;
    int m_interval_8_regTime;

    int m_interval_1_regPeriod;
    int m_interval_2_regPeriod;
    int m_interval_3_regPeriod;
    int m_interval_4_regPeriod;
    int m_interval_5_regPeriod;
    int m_interval_6_regPeriod;
    int m_interval_7_regPeriod;
    int m_interval_8_regPeriod;

    int m_dateAndTimeOfBegin;
    QDateTime m_startOfTheRecord;

public:
    static RdaDevData fromFile(QString addresOfInFile);
    static RdaDevData fromData(QString text);

    void fromBytes(QByteArray inputBin);

    QString getJsonHeader();
    QString getTextHeader();

    int getDeviceNumber();
    int getVectotQuontity();

    int getTimeOfStart();

    int getInterval_1_regTime();
    int getInterval_2_regTime();
    int getInterval_3_regTime();
    int getInterval_4_regTime();
    int getInterval_5_regTime();
    int getInterval_6_regTime();
    int getInterval_7_regTime();
    int getInterval_8_regTime();

    int getInterval_1_regPeriod();
    int getInterval_2_regPeriod();
    int getInterval_3_regPeriod();
    int getInterval_4_regPeriod();
    int getInterval_5_regPeriod();
    int getInterval_6_regPeriod();
    int getInterval_7_regPeriod();
    int getInterval_8_regPeriod();

    RdaVector10 at(int number);

    void addVector(RdaVector10 newVector);
    void recalculate();

protected:
    RdaDevData();
    RdaDevData(QByteArray inputBinArray);
};

#endif // RDADEVDATA_H
