
// ---------------------------------------------------//
// ---------------------------------------------------//
/* ------------- Set Up Wifi Parameters  -------------*/
// ------------------ WIFI CONFIG --------------------//

#define WIFIMANAGER   true
#define WIFI_SSID   "ZMS_SSID"
#define WIFI_PASS   "*******"
#define WIFI_HOST   "WIFIMANAGER"
#define LOCAL_IP IPAddress(192, 168, 1, 180)

#define WIFIEVENTS   false

// ------------ WIFI CONFIG ------------ //
#define GATEWAY IPAddress(192, 168, 1, 1)
#define SUBNET IPAddress(255, 255, 0, 0)
#define PRIMARYDNS IPAddress(9, 9, 9, 9)
#define SECONDARYDNS IPAddress(208, 67, 222, 222)
#define WIFI_RECONNECT_TIMER_S   20

// ----------- SERVER CONFIG ----------- //
#define SERVER_ENDPOINT "/wifimanager"
#define SERVER_PORT  80

// ------------------ SERIAL CONFIG --------------------//
#define SERIALDEBUG Serial

#define  DUMPS(s)    {  SERIALDEBUG.print(F(s)); }
#define  DUMPSLN(s)    {  SERIALDEBUG.println(F(s)); }
#define  DUMPPRINTLN() { SERIALDEBUG.println();}
#define  DUMPV(v)    {  SERIALDEBUG.print(v); }
#define  DUMPLN(s, v)  { DUMPS(s); DUMPV(v); DUMPPRINTLN(); }
