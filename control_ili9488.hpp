#include <SPI.h>
#include <TFT_eSPI.h>
#include <cstring>
#include "weather_icons.hpp"
#include "weather_data.hpp"

#define WHITE       0xFFFF
#define BLACK       0x0000
#define BLUE        0x001F
#define RED         0xF800
#define GREEN       0x07E0
#define CYAN        0x07FF
#define MAGENTA     0xF81F
#define YELLOW      0xFFE0
#define GREY        0x2108 
#define SCALE0      0xC655                                                               // accent color for unused scale segments                                   
#define SCALE1      0x5DEE                                                               // accent color for unused scale segments
#define TEXT_COLOR  0xFFFF   


void DrawScreen(TFT_eSPI & tft, const WeatherStructure & weather);
void InitTft(TFT_eSPI & tft);