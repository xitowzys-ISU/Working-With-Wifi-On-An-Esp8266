#include "Config.h"
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"

void setup() {
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  WiFi_init(MODE_AP);
  server_init();
  MQTT_init();
  String unique_topic = "assam";
  mqtt_client.publish((unique_topic + String("/state")).c_str(), "hello");
  mqtt_client.subscribe((unique_topic + String("/command")).c_str());
}

void loop() {
  server.handleClient();  
  mqtt_client.loop();
}
