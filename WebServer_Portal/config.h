// ---------------------------------------------------//
// ---------------------- WiFi -----------------------//
// ---------------------------------------------------//
// ------------------ WIFI CONFIG --------------------//

#define WIFI_SSID   "ZMS_SSID"
#define WIFI_PASS   "********"
#define LOCAL_IP IPAddress(192, 168, 1, 180)

// ------------ WIFI CONFIG ------------ //
#define GATEWAY IPAddress(192, 168, 1, 1)
#define SUBNET IPAddress(255, 255, 0, 0)
#define PRIMARYDNS IPAddress(9, 9, 9, 9)
#define SECONDARYDNS IPAddress(208, 67, 222, 222)

// ----------- SERVER CONFIG ----------- //
#define SERVER_PORT  80
#define HOST_PORT 80
long time_interval = 1000;

#define SERVER_EVENTS_ENDPOINT "/esp_events"
#define ESP_DATA "esp_data"

// ------------------ SERIAL CONFIG --------------------//
#define SERIALDEBUG Serial

#define  DUMPS(s)    {  SERIALDEBUG.print(F(s)); }
#define  DUMPSLN(s)    {  SERIALDEBUG.println(F(s)); }
#define  DUMPPRINTLN() { SERIALDEBUG.println();}
#define  DUMPV(v)    {  SERIALDEBUG.print(v); }
#define  DUMPLN(s, v)  { DUMPS(s); DUMPV(v); DUMPPRINTLN(); }
