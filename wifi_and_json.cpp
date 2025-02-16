#include "wifi_and_json.hpp" 

WiFiMulti wifi_multi;
String http_data;
WiFiClient client;
HTTPClient http;

bool ParseData(String && http_data, WeatherStructure & weather) {
  Serial.println(http_data);

  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, http_data);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return false;
  }

  weather.id       = doc["weather"][0]["id"];
  weather.main     = doc["weather"][0]["main"];
  weather.descript = doc["weather"][0]["description"];
  weather.icon     = doc["weather"][0]["icon"];
  weather.temp     = doc["main"]["temp"];//.as<float>();
  weather.humidity = doc["main"]["humidity"];
  weather.pressure = doc["main"]["pressure"].as<float>() * 0.7501f;
  weather.speed    = doc["wind"]["speed"];
  weather.deg      = doc["wind"]["deg"];

  return true;
}

void SettingsWiFi(const char* ssid, const char* password)
{
   WiFi.mode(WIFI_STA);
   wifi_multi.addAP(ssid, password);
   if ((wifi_multi.run() == WL_CONNECTED)) {
      Serial.println("WiFi connected..!");
      Serial.print("Got IP: ");  
      Serial.println(WiFi.localIP());
   }
}
 
void GetWeatherDataFromServer(WeatherStructure & weather, const StationWorkData & station_data){
  // wait for WiFi connection
  if (wifi_multi.run() == WL_CONNECTED) {

    Serial.print("[HTTP] begin...\n");
    
    if (http.begin(client, CreateRequest(station_data))) {  // HTTP  lon = 33.31; lat = 59.38; appid = b1f6b0a1ea9e10feb04eb3a2de2ad2b9

      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          ParseData(http.getString(), weather);  

          Serial.println("\nWeather");
          Serial.printf("icon: %s\n", weather.icon);
          Serial.printf("temp: %f celsius\n", weather.temp);
          Serial.printf("humidity: %f %\n", weather.humidity);
          Serial.printf("pressure: %f hPa or %f mmHg\n", weather.pressure, weather.pressure * 0.75);  
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();     
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
    delay(10000);
  }
}

char * CreateRequest(const StationWorkData & station_data) {
    char* http_request = new char[150];
    strcat(http_request, "http://api.openweathermap.org/data/2.5/weather?lat=");   
    strcat(http_request, station_data.latArr);
    strcat(http_request, "&lon=");
    strncat(http_request, station_data.lonArr, 5);
    strcat(http_request, "&units=metric&appid=");
    strcat(http_request, station_data.appidArr);
    Serial.print(http_request);

    return http_request;
}