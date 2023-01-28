#if defined(ESP8266)
  #include <ESP8266WebServer.h>
#endif

WiFiServer server(SERVER_PORT);

void initWebServer() {
  WiFiClient client = server.available();

  server.begin();
  DUMPSLN("SERVER ON");
}
