#include <AsyncMqttClient.h>
Ticker mqttReconnectTimer;

AsyncMqttClient mqttClient;

void connectToMqtt() {
  DUMPSLN("Connecting to MQTT...");
  mqttClient.connect();
  delay(1000);
  if( !mqttClient.connected()){
    DUMPSLN("Invalid MQTT Credentials or MQTT service is down\n");
    
  }
}

void onMqttConnect(bool sessionPresent) {
  DUMPSLN("Connected to MQTT.");
  DUMPLN("Session present: ", sessionPresent);
  
  char topic[strlen(MQTTROOM_ID)+strlen(MQTT_ID)];
  strcpy(topic, MQTTROOM_ID ); 
  DUMPLN("Subscribed to Topic: ",topic);
  mqttClient.subscribe( topic, MQTT_QOS );
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
  mqtt_reset_trycounter++;
  DUMPLN("Disconnected from MQTT. Try : ", mqtt_reset_trycounter);
  if( mqtt_reset_trycounter > MQTT_RESET_MAXTRIES){
    DUMPSLN("Restart ESP: ");
    ESP.restart();
  }else{
    if (WiFi.isConnected()) {
      //MQTT Reconnect in 2 seconds
      mqttReconnectTimer.once(2, connectToMqtt);
    }
  }
}

void onMqttSubscribe(uint16_t packetId, uint8_t qos) {
  DUMPS("Subscribe acknowledged.\t ");
  DUMPLN("  packetId: ", packetId);
  DUMPLN("  qos: ",qos);
}

void onMqttUnsubscribe(uint16_t packetId) {
  DUMPS("Unsubscribe acknowledged. \t ");
  DUMPLN("  packetId: ", packetId);
}

void onMqttPublish(uint16_t packetId) {
  DUMPS("Publish acknowledged. \t ");
  DUMPLN("  packetId: ", packetId);
}

void onMqttMessage(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total) {
  DUMPSLN("Publish received.");
  DUMPLN("  topic: ", topic);
  DUMPLN("  qos: ", properties.qos);
  DUMPLN("  dup: ", properties.dup);
  DUMPLN("  retain: ", properties.retain);
  DUMPLN("  len: ", len);
  DUMPLN("  index: ", index);
  DUMPLN("  total: ", total);
  DUMPLN(" Payload: ", payload );
  char messageArray[len];
  memcpy ( messageArray, payload, len );
  String message(messageArray);
  DUMPLN( " Message: ", message );

  //Send ack
  String ack_message = "Received from : "+ String(MQTT_ID);
  char ack_buf[ ack_message.length()+1 ];
  ack_message.toCharArray(ack_buf, ack_message.length() +1);
  
  char ack_topic[strlen(MQTT_ACKTOPIC)+strlen(MQTT_ID)];
  strcpy(ack_topic, MQTT_ACKTOPIC ); 
  strcat(ack_topic, MQTT_ID);
  
  mqttClient.publish( ack_topic, MQTT_QOS, false, ack_buf, ack_message.length()+1 );
}

void MQTT_init(){
  mqttClient.setClientId(MQTT_ID);
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onSubscribe(onMqttSubscribe);
  mqttClient.onUnsubscribe(onMqttUnsubscribe);
  mqttClient.onPublish(onMqttPublish);
  mqttClient.onMessage(onMqttMessage);

  mqttClient.setServer(MQTT_HOST, String(MQTT_PORT).toInt());

  #if MQTT_CREDENTIALS
    // If your broker requires authentication (username and password), set them below
    mqttClient.setCredentials(MQTT_USER, MQTT_PASS);
  #endif
  DUMPSLN("MQTT Init...");
}

String getReadings(){
  JSONVar esp_info;
  esp_info["x"] = millis();
  esp_info["y"] = millis();
  esp_info["theta"] = millis();
  return JSON.stringify( esp_info );
}
