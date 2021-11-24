#include <ESP8266WiFi.h>

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

void WiFi_init(bool mode_ap) {
  if (mode_ap) {
    StartAP();
    ip = WiFi.softAPIP().toString();
  } else {

  }

  Serial.println("IP Address: ");
  Serial.println(ip);
}
