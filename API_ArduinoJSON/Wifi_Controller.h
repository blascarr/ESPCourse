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

void serializeAPIResponse( String payload ){
  JSONVar JSON_data = JSON.parse(payload);
  if (JSON.typeof(JSON_data) == "undefined") {
    DUMPSLN("Parsing input failed!");
    return;
  }
  
  if (JSON_data.hasOwnProperty("latitude") && JSON_data.hasOwnProperty("longitude")) {
    DUMPLN("Lat: ", JSON_data["latitude"]);
    DUMPLN("Lng: ", JSON_data["longitude"]);
  }

  if (JSON_data.hasOwnProperty("elevation")) {
    DUMPLN("Elevation: ", JSON_data["elevation"]);
  }

  if (JSON_data.hasOwnProperty("daily")) {
    DUMPLN("WeatherCode First Day: ", JSON_data["daily"]["weathercode"][0]);
    DUMPLN("Max Temp First Day: ", JSON_data["daily"]["temperature_2m_max"][0]);
    DUMPLN("Min Temp First Day: ", JSON_data["daily"]["temperature_2m_min"][0]);
  }
}

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

void sendAPIRequest(){
  
  HTTPClient http;
  http.begin( request );
  int httpCode = http.GET();
  
  if( httpCode  != HTTP_CODE_OK ){
        DUMPSLN("HTTP CODE NOT OK");
        DUMPLN("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        return;
  }
  
  String payload = http.getString();
  DUMPLN ("Payload: ", payload);
  serializeAPIResponse( payload );
}
