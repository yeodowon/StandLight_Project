#include "TempHumidService.h"

TempHumidService::TempHumidService(TempHumidView *tempHumiView)
{
    this->tempHumiView = tempHumiView;
}

TempHumidService::~TempHumidService()
{
}

void TempHumidService::updateEvent(DHT_Data dhtData)
{
    float temp, humid;
    temp = (float)dhtData.Temp + (float)(dhtData.TempDec/10.0);
    humid = (float)dhtData.RH + (float)(dhtData.RHDec/10.0);
    
    tempHumiView->setTempHumidData(temp, humid);
}