// ---------------------------------------------------//
#include "config.h"
#include <Arduino_JSON.h>

const char* request = "http://api.open-meteo.com/v1/forecast?latitude=41.64999480549614&longitude=-0.8923184300057693&daily=weathercode,temperature_2m_max,temperature_2m_min&timezone=auto";

#include "Wifi_Controller.h"

void setup() {
  Serial.begin(115200);
  connectToWifi();
}

void loop() {
  if ( Serial.available() ){
    char data = Serial.read();
    if ( data == 'S'){
      sendAPIRequest();
    }
  }
}
