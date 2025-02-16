#pragma once

#include <EEPROM.h>

#define EEPROM_SIZE 512 // задаем количество байтов, к которым нужно получить доступ

struct StationWorkData {
    char* latArr;
    char* lonArr;
    char* ssidArr;
    char* passwordArr;  
    char* appidArr;
};

void GetDataFromEeprom (StationWorkData & station_data);
void SetDataToEeprom(const StationWorkData & station_data);