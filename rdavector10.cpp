#include "rdavector10.h"

RdaVector10::RdaVector10()
{}
    RdaVector10::RdaVector10(QByteArray ourVector){
        this->m_ourVector = ourVector;
    }

    int RdaVector10::getADCPressure(){
        return m_adcPressureData;
    }

    int RdaVector10::getNumber(){
        return m_vectorNumber;
    }
    void RdaVector10::setNumber(int nomber){
        m_vectorNumber = nomber;
    }

    short RdaVector10::getADC_Tp(){
        return m_adc_TP;
    }
    float RdaVector10::getCurrentVoltage(){
        return m_currentVoltage;
    }
    int RdaVector10::getPressure(){
        return m_pressure;
    }

    bool RdaVector10::getValidness(){
        return m_isValid;
    }

    short RdaVector10::getAsAnotherVector(){
        return m_isAsVector;
    }
    void RdaVector10::setAsAnotherVector(int exVector){
        m_isAsVector = exVector;
    }

    void RdaVector10::setValidnes(bool validnes){
        m_isValid = validnes;
    }

    bool RdaVector10::isNull(){
        return m_isNull;
    }
    void RdaVector10::nullThisVector(bool status){
        m_isNull = !status;
    }

    QByteArray RdaVector10::getBytes(){
        return  m_ourVector;
    }

     short RdaVector10::bytesToInt(quint8 byte1, quint8 byte2, quint8 byte3){ //byte 1  -older bute 3 is small

         uint32_t pressure = (static_cast<uint32_t>(byte3) << 16) |
                 (static_cast<uint32_t>(byte2) << 8) | byte1;

         return (short)pressure;

    }
     short RdaVector10::bytesToInt(quint8 byte1, quint8 byte2){  //byte 1  -older byte2 is small

         uint16_t pressure =(static_cast<uint32_t>(byte2) << 8) | byte1;

         return (short)pressure;
     }

     int RdaVector10::bytesToInt(quint8 byte1, quint8 byte2, quint8 byte3, quint8 byte4){ //byte1  -older byte4 is small

         uint32_t pressure = (static_cast<uint32_t>(byte4) << 24) |
                 (static_cast<uint32_t>(byte3) << 16) |
                 (static_cast<uint32_t>(byte2) << 8) | byte1;

         return (int)pressure;
     }

    QString RdaVector10::toText(){
        QString text = "";

        if (!m_isNull){
            if(!m_TimeOfThisVector.isNull()){
                text.append(m_TimeOfThisVector.toString("dd:hh:mm:ss:MMMM"));
                text.append(" ");
            }else {
                text.append(" |");
            }
            text.append(" vec# ");
            text.append(m_vectorNumber);
            text.append(" P(MPa) ");
            text.append(m_pressure);
            text.append(" Tp ");
            text.append(m_adc_TP);
            text.append(" ADC_P ");
            text.append(m_adcPressureData);
            if (m_isValid){
                text.append(" valid");
            }else {
                text.append(" inValid");
                }

        }else {

            if(!m_TimeOfThisVector.isNull()){
                text.append(m_TimeOfThisVector.toString("dd:hh:mm:ss:MMMM"));
                text.append(" ");
            }else {
                text.append(" |");
            }
            text.append(" vec# ");
            text.append(0);
            text.append(" P(MPa) ");
            text.append(0);
            text.append(" Tp ");
            text.append(0);
            text.append(" ADC_P ");
            text.append(0);
            if (m_isValid){
                text.append(" inValid/null");
            }else {
                text.append(" inValid");
                }
    }


        return text;
    }

    void RdaVector10::deserializeFromText(QString text){
       QStringList stringlist = text.split(" ", QString::SkipEmptyParts);

       if(stringlist.at(0)!="|"){
           m_TimeOfThisVector = QDateTime::fromString(stringlist.at(0), "dd:hh:mm:ss:MMMM");
       }else {
           //todo do something
       }

       for (int i = 1;i < stringlist.size() ;++i ) {
           if (stringlist.at(i) == "vec#" && i< stringlist.size()-1){
               m_vectorNumber = stringlist.at(i+1).toInt();
           }
           if (stringlist.at(i) == "P(MPa)" && i< stringlist.size()-1){
               m_pressure = stringlist.at(i+1).toInt();
           }
           if (stringlist.at(i) == "Tp" && i< stringlist.size()-1){
               m_adc_TP = stringlist.at(i+1).toInt();
           }
           if (stringlist.at(i) == "ADC_P" && i< stringlist.size()-1){
               m_adcPressureData = stringlist.at(i+1).toInt();
           }
           if (stringlist.at(i).contains("alid")){
               m_isValid = (stringlist.at(i) == "valid");
           }
       }
       if (m_vectorNumber != 0 && m_pressure != 0 && m_adc_TP != 0 && m_adcPressureData != 0 ){
           m_isNull = true;
       }else {
           m_isNull = false;
}
    }


    RdaVector10 RdaVector10::deserializeVectorFromText(QString text){
        RdaVector10 rdaVector;
        QStringList stringlist = text.split(" ", QString::SkipEmptyParts);
        if(stringlist.at(0)!="|"){
            rdaVector.m_TimeOfThisVector = QDateTime::fromString(stringlist.at(0), "dd:hh:mm:ss:MMMM");
        }else {
            //todo do something
        }
        for (int i = 1;i < stringlist.size() ;++i ) {
            if (stringlist.at(i) == "vec#" && i< stringlist.size()-1){
                rdaVector.m_vectorNumber = stringlist.at(i+1).toInt();
            }
            if (stringlist.at(i) == "P(MPa)" && i< stringlist.size()-1){
                rdaVector.m_pressure = stringlist.at(i+1).toInt();
            }
            if (stringlist.at(i) == "Tp" && i< stringlist.size()-1){
                rdaVector.m_adc_TP = stringlist.at(i+1).toInt();
            }
            if (stringlist.at(i) == "ADC_P" && i< stringlist.size()-1){
                rdaVector.m_adcPressureData = stringlist.at(i+1).toInt();
            }
            if (stringlist.at(i).contains("alid")){
                rdaVector.m_isValid = (stringlist.at(i) == "valid");
            }
        }
        if (rdaVector.m_vectorNumber != 0 && rdaVector.m_pressure != 0 &&
                rdaVector.m_adc_TP != 0 && rdaVector.m_adcPressureData != 0 ){
            rdaVector.m_isNull = true;
        }else {
            rdaVector.m_isNull = false;
 }


        return rdaVector;
    }


    QString RdaVector10::toJson(){
        QString json = "";
        json.append("{Time&Date");
        json.append(":");
        if(!m_TimeOfThisVector.isNull()){
            json.append(m_TimeOfThisVector.toString("dd:hh:mm:ss:MMMM"));
        }else {
            json.append("null");
        }
        json.append(",");
        json.append("vecNomber");
        json.append(":");
        json.append(m_vectorNumber);
        json.append(",");
        json.append("Pressure");
        json.append(":");
        json.append(m_pressure);
        json.append(",");
        json.append("T_p");
        json.append(":");
        json.append(m_adc_TP);
        json.append(",");
        json.append("ADC_P");
        json.append(":");
        json.append(m_adcPressureData);
        json.append(",");
        json.append("isValid");
        json.append(":");
        json.append(m_isValid);

        return json;
    }




    RdaVector10 RdaVector10::fromBytes(QByteArray ourVector){
        RdaVector10 rdaVector;

        rdaVector.m_vectorNumber = 0;

        if (ourVector.size()!= 10){
            rdaVector.nullThisVector(true);
            return rdaVector;
        }
        rdaVector.m_adcPressureData = bytesToInt(ourVector.at(2),ourVector.at(1), ourVector.at(0));
        rdaVector.m_adc_TP = bytesToInt(ourVector.at(4),ourVector.at(3));
        rdaVector.m_currentVoltage = ((float)ourVector.at(5))*0.1;
        rdaVector.m_pressure = bytesToInt(ourVector.at(6), ourVector.at(7), ourVector.at(8), ourVector.at(9));
        rdaVector.m_isAsVector = 0;



        return rdaVector;
    }

    RdaVector10 RdaVector10::fromBytes(QByteArray ourVector, int vectoNumber){
        RdaVector10 rdaVector = RdaVector10::fromBytes(ourVector);
        rdaVector.setNumber(vectoNumber);
        return rdaVector;
            }

