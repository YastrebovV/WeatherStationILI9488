#include "station_eeprom.hpp"

void GetDataFromEeprom (StationWorkData & station_data){
    //Init EEPROM
    EEPROM.begin(EEPROM_SIZE);
    
    uint addr = 0;  

    EEPROM.get(addr, station_data.ssidArr);
    Serial.println(station_data.ssidArr);
    addr += sizeof(station_data.ssidArr);
    
    EEPROM.get(addr, station_data.passwordArr);
    Serial.println(station_data.passwordArr);
    addr += sizeof(station_data.passwordArr);

    EEPROM.get(addr, station_data.lonArr);
    Serial.println(station_data.lonArr);
    addr += sizeof(station_data.lonArr);

    EEPROM.get(addr, station_data.latArr);
    Serial.println(station_data.latArr);
    addr += sizeof(station_data.latArr);

    EEPROM.get(addr, station_data.appidArr);
    Serial.println(station_data.appidArr);
    
    EEPROM.end();   
}

void SetDataToEeprom(const StationWorkData & station_data){
    //Init EEPROM
    EEPROM.begin(EEPROM_SIZE);
    
    uint addr = 0;

    //Serial.println(station_data.ssidArr);
    EEPROM.put(addr, station_data.ssidArr);
    addr += sizeof(station_data.ssidArr);
    
    EEPROM.put(addr, station_data.passwordArr);
    addr += sizeof(station_data.passwordArr);

    EEPROM.put(addr, station_data.lonArr);
    addr += sizeof(station_data.lonArr);
    
    EEPROM.put(addr, station_data.latArr);
    addr += sizeof(station_data.latArr);
    
    EEPROM.put(addr, station_data.appidArr);

    EEPROM.commit();
    delay(1000);
    EEPROM.end(); 
}