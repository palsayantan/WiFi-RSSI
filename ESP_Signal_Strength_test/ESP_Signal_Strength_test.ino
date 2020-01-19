#include <ESP8266WiFi.h>

//SSID of your network
char ssid[] = "YOURSSID";
//password of your WPA Network
char pass[] = "YOURPASSWORD";

void setup() {
  Serial.begin(115200);
  Serial.println("ESP8266 WiFi Signal Strength Checker");

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(10);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // if you are connected, print out info about the connection:
  Serial.print("\nConnected to: ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("");
}

void loop () {
  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("RSSI: ");
  Serial.println(rssi);
  delay(1000);
}
