#include <ESPAsyncDNSServer.h>
#include <ESPAsyncWebServer.h>


AsyncWebServer server( SERVER_PORT );
AsyncDNSServer dns;

void initWebServer() {
  // Handle Web Server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", "Hello MQTT");
  });

  server.begin();
  DUMPSLN("SERVER ON");
}
