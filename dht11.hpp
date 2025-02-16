#pragma once

#include <DHT.h>

#define DHTTYPE DHT11   // DHT 11

struct DhtData{
  float temp;
  byte  humidity;
};

void InitDHT ();
DhtData GetDhtData ();