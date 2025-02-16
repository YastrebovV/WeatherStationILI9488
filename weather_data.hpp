#pragma once

struct WeatherStructure {
  unsigned int id;
  const char* main;
  const char* icon;
  const char* descript;
  float temp;
  float pressure;
  byte  humidity;
  float speed;
  float deg;

  float temp_inside;
  byte  humidity_inside;
};
