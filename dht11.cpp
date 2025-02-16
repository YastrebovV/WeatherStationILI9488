#include "dht11.hpp"

// DHT датчик
uint8_t DhtPin = 12;
DHT dht(DhtPin, DHTTYPE);  

void InitDHT (){
  pinMode(DhtPin, INPUT);  
  dht.begin(10);
  Serial.print("InitDHT");
}

DhtData GetDhtData (){
  DhtData dht_data;
  dht_data.temp = dht.readTemperature(false, false); // Получает значения температуры
  dht_data.humidity = dht.readHumidity(false); // Получает значения влажности

  return dht_data;
}