#include "control_ili9488.hpp"

void InitTft(TFT_eSPI & tft){
  
  tft.init ();

  tft.fillScreen(TFT_BLACK);
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);

  // Set "cursor" at top left corner of display (0,0) and select font 4
  tft.setCursor(0, 4, 4);

  // Set the font colour to be white with a black background
  tft.setTextColor(TFT_WHITE);

  tft.setSwapBytes(true);

  // We can now plot text on screen using the "print" class
  tft.println(" TFT Initialised \n");

  Serial.println("InitTFT");
}

void DrawScreen(TFT_eSPI & tft, const WeatherStructure & weather){

    tft.fillScreen(TFT_BLACK);
    //tft.drawFastHLine(0, 30,  tft.width(), TFT_WHITE);  
    tft.setTextColor(TFT_WHITE);  
    //tft.setTextSize(2);               
    tft.setCursor(20, 7);             

////**************************
  //  tft.pushImage(6, 180, 128, 64, (uint16_t *) GetMeteoIconFromProgmem(weather.icon));
////**************************
 //  tft.pushImage(100, 100, 48, 48, cloud_83969, false);


tft.pushImage(100, 100, 48, 48, GetMiniMeteoIconFromProgmem("10d"), false);

    //tft.drawFastHLine(0, 76,  tft.width(), TFT_WHITE);   // draw horizontal white line at position (0, 76)
    //tft.drawFastHLine(0, 122,  tft.width(), TFT_WHITE);  // draw horizontal white line at position (0, 122)
/*
    tft.setCursor(40, 33);              
    tft.print("Temperatures");
  
    tft.setCursor(40, 79);              
    tft.print("HUMIDITY");
   
    tft.setCursor(40, 125);              
    
    tft.print("PRESSURE");
          
    //tft.setTextSize(2);                 // text size = 2
    // print °C
    tft.drawCircle(77, 56, 2, TFT_BLACK);  // print degree symbol ( ° )
    tft.setCursor(83, 54);                     
    tft.setTextColor(TFT_RED);  
    tft.print("C");

    tft.setCursor(26, 54);
    tft.printf( "%2.1f", weather.temp);
  
    // 2: print humidity
    tft.setCursor(40, 100);
    tft.printf("%02u%c", weather.humidity, '%');

    // 3: print pressure
    tft.setCursor(6, 144);
    tft.printf( "%4.0f%s", weather.pressure, "mmHg");*/
}


