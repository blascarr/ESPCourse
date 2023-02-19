// ---------------------------------------------------//
#include "config.h"
#include <Ticker.h>
#include <Arduino_JSON.h>

#include "Wifi_Controller.h"
#include "Server_Controller.h"
#include "MQTT_Controller.h"

void setup() {
  Serial.begin(115200);
  connectToWifi();
  initWebServer();
  MQTT_init();
  connectToMqtt();
}

void loop() {
  
}
