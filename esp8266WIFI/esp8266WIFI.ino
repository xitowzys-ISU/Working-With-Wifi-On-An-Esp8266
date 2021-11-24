#include "Config.h"
#include "WIFI.h"
#include "Server.h"

void setup() {
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  WiFi_init(true);
  server_init();
}

void loop() {
  server.handleClient();  
}
