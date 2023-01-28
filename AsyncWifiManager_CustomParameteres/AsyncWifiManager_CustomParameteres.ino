// ---------------------------------------------------//
#include "config.h"
#include <Ticker.h>

// ---------------------------------------------------//
// ----------------- WiFi CONTROLLERS ----------------//
// ---------------------------------------------------//
#include "Server_Controller.h"
#include "Wifi_Controller.h"

#if WIFIEVENTS
  #include "WifiEvents_Controller.h" 
#endif

void setup() {
  Serial.begin(115200);  

  #if WIFIEVENTS
    onWifiEvents();
  #endif

  bool isConnected = connectToWifi();
  if( isConnected ){
    DUMPSLN("IS WIFI CONNECTED");
    initWebServer();
  }
}

void loop() {
  
}
