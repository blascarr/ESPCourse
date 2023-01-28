// ---------------------------------------------------//
// ------------------ WiFi Connector -----------------//
// ---------------------------------------------------//
#if defined(ESP32)
  #include <WiFi.h>
#endif

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESP8266mDNS.h>
#endif

#if defined(ESP8266)
  WiFiEventHandler wifiConnectHandler;
  WiFiEventHandler wifiDisconnectHandler;
#endif

// ---------------------------------------------------//
// ------------------ WiFi PARAMETERS ----------------//
// ---------------------------------------------------//

#if WIFIMANAGER 
  #include "ESPAsync_WiFiManager.h"
  ESPAsync_WiFiManager wifiManager(&server,&dns);
#endif

// ---------------------------------------------------//
// ----------------- WiFi TICKER EVENT ---------------//
// ---------------------------------------------------//
// Ticker wifiReconnectTimer;

bool connectToWifi() {
  bool connected = false;
  DUMPSLN("Wi-Fi ...");
  WiFi.mode(WIFI_STA);
  #if WIFIMANAGER 
    DUMPSLN("Connecting to WifiManager...");
    
    bool wifiManagerConnected = wifiManager.autoConnect(WIFI_HOST);
    
    if( wifiManagerConnected ){
        DUMPSLN("Async WifiManager On");
        DUMPS("Connected to Wifi - Local IP : ");
    
        if (!WiFi.config(LOCAL_IP, GATEWAY, SUBNET, PRIMARYDNS, SECONDARYDNS)) {
          DUMPSLN("STA Failed to configure");
        }else{
          connected = true;
        }
    }
    else {
        DUMPSLN("Configportal running");
    }
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
      DUMPSLN("Connection Failed! Rebooting...");
      delay(5000);
      ESP.restart();
    }
  #else
    WiFi.begin( WIFI_SSID, WIFI_PASS );
    if (!WiFi.config(LOCAL_IP, GATEWAY, SUBNET, PRIMARYDNS, SECONDARYDNS)) {
      DUMPSLN("STA Failed to configure");
    }
    DUMPSLN("Connecting to Wifi...");
    while (WiFi.status() != WL_CONNECTED) {
      DUMPS(".");
      delay(1000);
    }
    connected = true;
  #endif
  
  if( connected ){
    DUMPLN( "Wifi Connected - Local IP : ",WiFi.localIP() );
    DUMPLN( "GateWay IP = ", WiFi.gatewayIP() );
    DUMPLN( "SubnetMask = ", WiFi.subnetMask() );
  } 
  return connected;
}
