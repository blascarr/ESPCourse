#include <ESPAsyncDNSServer.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server( SERVER_PORT );
AsyncDNSServer dns;

void initWebServer() {
  // Handle Web Server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/html", "WiFi connected");
  });

  server.begin();
  DUMPSLN("SERVER ON");
}
