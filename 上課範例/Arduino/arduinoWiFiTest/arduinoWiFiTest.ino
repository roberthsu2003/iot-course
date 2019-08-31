#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

FirebaseData firebaseData;
void setup()
{
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
  Firebase.setMaxErrorQueue(firebaseData, 30);
  Firebase.setMaxRetry(firebaseData, 3);

  pinMode(D3,OUTPUT);
}


void loop() {
  if (Firebase.getBool(firebaseData,"/lcd/relay1")){
    if(firebaseData.boolData()){
      digitalWrite(D3,HIGH);
    }else{
      digitalWrite(D3,LOW);
    }
  }
  delay(300);
 }
