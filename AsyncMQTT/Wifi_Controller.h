// ---------------------------------------------------//
// ------------------ WiFi Connector -----------------//
// ---------------------------------------------------//
#if defined(ESP32)
  #include <WiFi.h>
#endif

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESP8266mDNS.h>
  #include <ESP8266HTTPClient.h>
#endif

#if defined(ESP8266)
  WiFiEventHandler wifiConnectHandler;
  WiFiEventHandler wifiDisconnectHandler;
#endif

bool connectToWifi() {
  bool connected = false;
  DUMPSLN("Wi-Fi ...");
  WiFi.mode(WIFI_STA);
  
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

  if( connected ){
    DUMPSLN( "" );
    DUMPLN( "Wifi Connected - Local IP : ",WiFi.localIP() );
    DUMPLN( "GateWay IP = ", WiFi.gatewayIP() );
    DUMPLN( "SubnetMask = ", WiFi.subnetMask() );
  } 
  return connected;
}
