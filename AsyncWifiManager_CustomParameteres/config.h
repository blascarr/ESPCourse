
// ---------------------------------------------------//
// ------------------ WiFi and MQTT ------------------//
// ---------------------------------------------------//
/* --- Set Up Wifi Parameters and MQTT Credentials ---*/
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

// ------------------ MQTT CONFIG --------------------//
#define MQTT_HOST_LEN           64
#define MQTT_PORT_LEN           6
#define MQTT_USER_LEN           32
#define MQTT_PASS_LEN           32
#define MQTT_TOPIC_LEN          16
#define MQTT_QOS                1

char MQTT_HOST [MQTT_HOST_LEN]    = "broker.emqx.io";   //  https://www.emqx.com/en/blog/popular-online-public-mqtt-brokers
char MQTT_PORT   [MQTT_PORT_LEN]  = "1883";
char MQTT_TOPIC   [MQTT_TOPIC_LEN]   = "test/";


#define MQTT_CREDENTIALS false
char MQTT_USER  [MQTT_USER_LEN]   = "admin";
char MQTT_PASS  [MQTT_PASS_LEN]   = "*******";

// ----------- SLEEP CONFIG ----------- //
#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define SLEEP_TIME_LEN    10
char SLEEP_TIME  [SLEEP_TIME_LEN] = "3000";

// ------------------ SERIAL CONFIG --------------------//
#define SERIALDEBUG Serial

#define  DUMPS(s)    {  SERIALDEBUG.print(F(s)); }
#define  DUMPSLN(s)    {  SERIALDEBUG.println(F(s)); }
#define  DUMPPRINTLN() { SERIALDEBUG.println();}
#define  DUMPV(v)    {  SERIALDEBUG.print(v); }
#define  DUMPLN(s, v)  { DUMPS(s); DUMPV(v); DUMPPRINTLN(); }
