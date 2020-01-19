#include <ESP8266WiFi.h>

#include <Adafruit_NeoPixel.h>

#define PIN         5
#define NUMPIXELS  12

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//SSID of your network
char ssid[] = "YOURSSID";
//password of your WPA Network
char pass[] = "YOURPASSWORD";

const int MAX_VAL = -20; // define maximum signal strength (in dBm)
const int MIN_VAL = -80; // define minimum signal strength (in dBm)

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

  pixels.begin(); // Initialize NeoPixel LEDs
}

void clearDisplay() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(  0,   0,   0));
  }
  pixels.show();
}

void loop () {
  clearDisplay();
  long rssi = WiFi.RSSI();
  Serial.print("RSSI: ");   // print the received signal strength:
  //Serial.println(rssi);
  int strength = map(rssi, MIN_VAL, MAX_VAL, 0, 11);
  
  for (int i = 0; i < strength; i++) {
    if (strength == 0) pixels.setPixelColor(i, pixels.Color(255,   0,   0));
    if (strength == 1) pixels.setPixelColor(i, pixels.Color(255,   4,   0));
    if (strength == 2) pixels.setPixelColor(i, pixels.Color(255,   8,   0));
    if (strength == 3) pixels.setPixelColor(i, pixels.Color(255,  16,   0));
    if (strength == 4) pixels.setPixelColor(i, pixels.Color(255,  64,   0));
    if (strength == 5) pixels.setPixelColor(i, pixels.Color(255, 128,   0));
    if (strength == 6) pixels.setPixelColor(i, pixels.Color(255, 255,   0));
    if (strength == 7) pixels.setPixelColor(i, pixels.Color(128, 255,   0));
    if (strength == 8) pixels.setPixelColor(i, pixels.Color( 64, 255,   0));
    if (strength == 9) pixels.setPixelColor(i, pixels.Color(  0, 255,   0));
    if (strength == 10) pixels.setPixelColor(i, pixels.Color( 0, 255, 128));
    if (strength == 11) pixels.setPixelColor(i, pixels.Color( 0, 255, 255));
  }
  
  pixels.show();
  delay(1000);
}
