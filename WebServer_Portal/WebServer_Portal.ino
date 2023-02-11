// ---------------------------------------------------//
#include "config.h"
#include <Ticker.h>
#include <Arduino_JSON.h>

#include "Wifi_Controller.h"
#include "Server_Controller.h"
Ticker sendTicker;

String getReadings(){
  JSONVar esp_info;
  esp_info["x"] = millis();
  esp_info["y"] = millis();
  esp_info["theta"] = millis();
  return JSON.stringify( esp_info );
}

void send_data(){
  events.send(getReadings().c_str(), ESP_DATA , millis());
}

void setup() {
  Serial.begin(115200);
  connectToWifi();
  initWebServer();
  sendTicker.attach_ms( time_interval, send_data );
}

void loop() {
  if ( Serial.available() ){
    char data = Serial.read();
    if ( data == 'S'){
      DUMPSLN("SEND DATA TO ENDPOINT");
      events.send(getReadings().c_str(), ESP_DATA , millis());
    }
  }
  
}
