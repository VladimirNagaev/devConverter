#include "rdadevdata.h"

void RdaDevData::fromBytes(QByteArray inputBin)
{}

void RdaDevData::addVector(RdaVector10 newVector)
{
    m_dataVectors.append(newVector);
}

void RdaDevData::recalculate()
{}

RdaDevData::RdaDevData()
{}

RdaDevData::RdaDevData(QByteArray inputBinArray)
{
    this->fromBytes(inputBinArray);
}
