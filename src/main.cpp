/*

 * This ESP32 code is created by esp32io.com

 *

 * This ESP32 code is released in the public domain

 *

 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/communication-between-two-esp32

 */

// ESP32: TCP CLIENT + A BUTTON/SWITCH

#include <WiFi.h>


//#define BUTTON_PIN 21 // ESP32 pin GPIO21 connected to button

unsigned long current_time = 0;
const char* ssid = "HTL-Weiz";     // CHANGE TO YOUR WIFI SSID
const char* password = "HTL-Weiz"; // CHANGE TO YOUR WIFI PASSWORD
const char* serverAddress = "172.31.182.29"; // CHANGE TO ESP32#2'S IP ADDRESS
const int serverPort = 4080;
int buttonPin = 21;
int buttonState = 0;

WiFiClient TCPclient;


void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("ESP32: TCP CLIENT + A BUTTON/SWITCH");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
 
  // connect to TCP server (Arduino #2)
  if (TCPclient.connect(serverAddress, serverPort)) {

    Serial.println("Connected to TCP server");
  } else {
    Serial.println("Failed to connect to TCP server");
  }
}


void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH && WiFi.status() == WL_CONNECTED) {
    // turn LED on
    TCPclient.write('1');
    delay(100);
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("is connected!!");
    
    //delay(1000);
  }
  else if (WiFi.status() != WL_CONNECTED) {
    Serial.println("is NOT connected!!");
  }

  }
