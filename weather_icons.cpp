#include "weather_icons.hpp"

// Helper function, should be part of the weather station library and should disappear soon
const char* GetMeteoIconFromProgmem(String iconText) {
  if (iconText == "01d" || iconText == "01n") return sunny;
  if (iconText == "02d" || iconText == "02n") return partlysunny;
  if (iconText == "03d" || iconText == "03n") return partlycloudy;
  if (iconText == "04d" || iconText == "04n") return mostlycloudy;
  if (iconText == "09d" || iconText == "09n") return rain;
  if (iconText == "10d" || iconText == "10n") return rain;
  if (iconText == "11d" || iconText == "11n") return tstorms;
  if (iconText == "13d" || iconText == "13n") return snow;
  if (iconText == "50d" || iconText == "50n") return fog;
  return unknown;
}
const uint8_t* GetMiniMeteoIconFromProgmem(String iconText) {
 /* if (iconText == "01d" || iconText == "01n") return minisunny;
  if (iconText == "02d" || iconText == "02n") return minipartlysunny;
  if (iconText == "03d" || iconText == "03n") return minipartlycloudy;
  if (iconText == "04d" || iconText == "04n") return minimostlycloudy;
  if (iconText == "09d" || iconText == "09n") return minirain;*/
  if (iconText == "10d" || iconText == "10n") return minicloudy;
 /* if (iconText == "11d" || iconText == "11n") return minitstorms;
  if (iconText == "13d" || iconText == "13n") return minisleet;
  if (iconText == "50d" || iconText == "50n") return minifog;*/
  return miniunknown;
}