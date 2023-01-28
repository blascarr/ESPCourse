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

  ESPAsync_WMParameter  custom_mqtt_server("server", "MQTT server", MQTT_HOST, 40);
  ESPAsync_WMParameter  custom_mqtt_port("port", "MQTT port", MQTT_PORT, 6);
  ESPAsync_WMParameter  custom_sleep("SleepMode", "Sleep Mode", SLEEP_TIME, 20);
  #if MQTT_CREDENTIALS
    ESPAsync_WMParameter  custom_mqtt_user("user", "MQTT user", MQTT_USER, 20);
    ESPAsync_WMParameter  custom_mqtt_pass("pass", "MQTT pass", MQTT_PASS, 20);
  #endif
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
    wifiManager.addParameter(&custom_mqtt_server);
    wifiManager.addParameter(&custom_mqtt_port);
    wifiManager.addParameter(&custom_sleep);
    
    #if MQTT_CREDENTIALS
      wifiManager.addParameter(&custom_mqtt_user);
      wifiManager.addParameter(&custom_mqtt_pass);
    #endif
    
    
    bool wifiManagerConnected = wifiManager.autoConnect(WIFI_HOST);
    
    if( wifiManagerConnected ){
        DUMPSLN("Async WifiManager On");
        DUMPS("Connected to Wifi - Local IP : ");
        
        // Configures static IP address
        //strncpy(MQTT_HOST, custom_mqtt_server.getValue(), sizeof(MQTT_HOST));
        //strncpy(MQTT_PORT, custom_mqtt_port.getValue(), sizeof(MQTT_PORT));
    
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
