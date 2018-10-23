//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "casasegura-b6acb.firebaseio.com"
#define FIREBASE_AUTH "Cw1xkD4PuJPgcpQkbKd5jObOIUGJ0g2yn2cXpTht"
#define WIFI_SSID "Juanfra"
#define WIFI_PASSWORD "123454321"

//Vars Id
byte mac[6];
String ID;

void configuracionInicial(){
  // Configuracion inicial del disositivo
  
  Firebase.setString("Devices","");
  if (Firebase.failed()) {
      Serial.print("setting /ID failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  ///////////
  Firebase.setString(String("Devices/"+ID),"");
  if (Firebase.failed()) {
      Serial.print("setting /ID failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  Firebase.setString(String("Devices/"+ID+"/lugar"), "");
  if (Firebase.failed()) {
      Serial.print("setting /ID failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  /////////////
  Firebase.setBool(String("Devices/"+ID+"/corte de luz"), false);
  if (Firebase.failed()) {
      Serial.print("setting /encendido failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  //////////
  Firebase.setString(String("Devices/"+ID+"/descripcion"), "");
  if (Firebase.failed()) {
      Serial.print("setting /ID failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
}



void setup() {
  Serial.begin(115200);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  //Se saca la MAC
  WiFi.macAddress(mac);
  ID= String(String(mac[0],HEX)+String(mac[5],HEX));
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  configuracionInicial();
  Serial.println("Configuracion Inicial cargada");
}


void loop() {
  Serial.println(digitalRead(D1));
  if (digitalRead(D1)== true){
    Firebase.setBool(String("Devices/"+ID+"/corte de luz"), true);
    if (Firebase.failed()) {
        Serial.print("setting /encendido failed:");
        Serial.println(Firebase.error());  
        return;
    }
  }
  else{
    Firebase.setBool(String("Devices/"+ID+"/corte de luz"), false);
    if (Firebase.failed()) {
        Serial.print("setting /encendido failed:");
        Serial.println(Firebase.error());  
        return;
    
    }
  }
  delay(10000);
  
}
