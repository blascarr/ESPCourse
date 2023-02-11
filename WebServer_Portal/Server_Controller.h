#include <ESPAsyncDNSServer.h>
#include <ESPAsyncWebServer.h>
#include "webpage.h"

AsyncWebServer server( SERVER_PORT );
AsyncDNSServer dns;

AsyncEventSource events( SERVER_EVENTS_ENDPOINT );

void initWebServer() {
  // Handle Web Server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/html", esp_html);
  });

  server.addHandler( &events );
  server.begin();
  DUMPSLN("SERVER ON");
}
