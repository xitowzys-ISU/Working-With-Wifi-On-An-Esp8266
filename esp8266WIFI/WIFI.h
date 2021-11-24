#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifimulti;
WiFiClient wificlient;

String ip = "IP UNSET";

String id() {
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  String macID =
      String(mac[WL_MAC_ADDR_LENGTH - 2]) + String(mac[WL_MAC_ADDR_LENGTH - 1]);
  return macID;
}

bool StartAP() {
  IPAddress apIP(192, 168, 4, 1);
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(225, 225, 255, 0));
  WiFi.softAP((ssidAP + " " + id()).c_str(), passwordAP.c_str());
  Serial.println("\nWiFi AP start " + ssidAP + " " + id());
  return true;
}

bool startCLI() {
  wifimulti.addAP(ssidCLI.c_str(), passwordCLI.c_str());
  while(wifimulti.run() != WL_CONNECTED) {
    delay(1);
  }

  return true;
}

void WiFi_init(bool mode_ap) {
  if (mode_ap) {
    StartAP();
    ip = WiFi.softAPIP().toString();
  } else {
    startCLI();
    ip = WiFi.localIP().toString();

  }

  Serial.println("IP Address: ");
  Serial.println(ip);
}
