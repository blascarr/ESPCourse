#include <ESPAsyncDNSServer.h>
#include <ESPAsyncWebServer.h>
#include "webpage.h"

AsyncWebServer server( SERVER_PORT );
AsyncDNSServer dns;

void initWebServer() {
  // Handle Web Server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/html", esp_html);
  });

  server.on( SERVER_ENDPOINT ,  HTTP_GET, [] (AsyncWebServerRequest *request) {  
    DUMPLN(" Server Data From  ", SERVER_ENDPOINT );
    if (request->hasParam( SERVER_DATA )){
      String jsonData = request->getParam(SERVER_DATA)->value();
      DUMPLN(" JSON Data ", jsonData );
      request->send(200, "text/plain", "OK");
    }
  });
  
  server.begin();
  DUMPSLN("SERVER ON");
}
