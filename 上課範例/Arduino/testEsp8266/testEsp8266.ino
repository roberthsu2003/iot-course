#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

FirebaseData firebaseData;


void setup() {
  Serial.begin(115200);
  Serial.println();
  WiFi.begin("robert_hsu", "1234567890");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());


  Firebase.begin("arduinofirebase-6d104.firebaseio.com", "z5lPWwjZLZuNNcUEelbJdiNaIvnR2Zfq49BuQBAa");
  Firebase.reconnectWiFi(true);
  Firebase.setMaxRetry(firebaseData, 3);
  Firebase.setMaxErrorQueue(firebaseData, 30);
  
  pinMode(D1,OUTPUT);
}

void loop() {
  if (Firebase.getBool(firebaseData, "/led/D2")) {    
      Serial.println(firebaseData.boolData());  
      bool boolValue = firebaseData.boolData(); 
      if (boolValue){
        digitalWrite(D1,HIGH);
      }else{
        digitalWrite(D1,LOW);
      }
  }
  
  delay(1000);
}
