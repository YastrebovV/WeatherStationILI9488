#pragma once

#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "station_eeprom.hpp"
#include "weather_data.hpp"

//char http_request[150];

void GetWeatherDataFromServer(WeatherStructure & weather, const StationWorkData & station_data);
bool ParseData(String && http_data, WeatherStructure & weather);
void SettingsWiFi(const char* ssid, const char* password);
char * CreateRequest(const StationWorkData & station_data);