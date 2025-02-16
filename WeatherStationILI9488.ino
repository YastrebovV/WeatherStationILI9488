#include <Arduino.h>
#include "control_ili9488.hpp"   
#include "station_eeprom.hpp"    
#include "wifi_and_json.hpp" 
#include "dht11.hpp"                                                

TFT_eSPI tft = TFT_eSPI();   

StationWorkData station_data;
WeatherStructure weather;

DhtData dht_data;

void setup() {

  Serial.begin(115200);
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }
/////**************
 // HTTP  lon = 33.31; lat = 59.38; appid = b1f6b0a1ea9e10feb04eb3a2de2ad2b9

  station_data.ssidArr = "HUAWEI_Yast";
  station_data.passwordArr = "gty24Se*";
  station_data.latArr = "59.38";
  station_data.lonArr = "33.31";
  station_data.appidArr = "b1f6b0a1ea9e10feb04eb3a2de2ad2b9";

  SetDataToEeprom(station_data);
  GetDataFromEeprom(station_data);   
  
  SettingsWiFi(station_data.ssidArr, station_data.passwordArr);

  InitDHT();
  InitTft(tft);
}

void loop() {

  GetWeatherDataFromServer(weather, station_data);
  dht_data = GetDhtData ();

  weather.temp_inside = dht_data.temp;
  weather.humidity_inside = dht_data.humidity;

  DrawScreen(tft, weather);

  delay(5000);
}
