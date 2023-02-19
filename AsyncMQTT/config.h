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

// ----------- MQTT CONFIG ----------- //
#define MQTT_ID "ZMS"
#define MQTT_HOST_LEN           64
#define MQTT_PORT_LEN           6
#define MQTT_USER_LEN           32
#define MQTT_PASS_LEN           32
#define MQTT_TOPIC_LEN          16
#define MQTT_ACKTOPIC_LEN       16
#define MQTT_QOS                1

char MQTT_HOST [MQTT_HOST_LEN]    = "broker.emqx.io";   //  https://www.emqx.com/en/blog/popular-online-public-mqtt-brokers
char MQTT_PORT   [MQTT_PORT_LEN]  = "1883";
char MQTT_TOPIC   [MQTT_TOPIC_LEN]   = "zms/";
char MQTT_ACKTOPIC   [MQTT_ACKTOPIC_LEN]   = "ack/";
#define MQTT_TOPIC_ID_LEN         16
char MQTTROOM_ID  [MQTT_TOPIC_ID_LEN]   = "zms/room";

#define MQTT_CREDENTIALS false
char MQTT_USER  [MQTT_USER_LEN]   = "admin";
char MQTT_PASS  [MQTT_PASS_LEN]   = "*******";

#define MQTT_RESET_MAXTRIES 10
int mqtt_reset_trycounter = 0;

// ------------------ SERIAL CONFIG --------------------//
#define SERIALDEBUG Serial

#define  DUMPS(s)    {  SERIALDEBUG.print(F(s)); }
#define  DUMPSLN(s)    {  SERIALDEBUG.println(F(s)); }
#define  DUMPPRINTLN() { SERIALDEBUG.println();}
#define  DUMPV(v)    {  SERIALDEBUG.print(v); }
#define  DUMPLN(s, v)  { DUMPS(s); DUMPV(v); DUMPPRINTLN(); }
