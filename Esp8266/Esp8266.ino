#include <SimplePgSQL.h>
//#include <WIFI.h>
#include <ESP8266WiFi.h>
#include <Ethernet.h>

byte mac[6];
String ID;

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("Juanfra", "123454321");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  //Printing Mac from Esp8266
  Serial.println();
  Serial.print("MAC: ");
  WiFi.macAddress(mac);
  Serial.println(WiFi.macAddress());
  Serial.println(mac[0]);
  Serial.println(mac[1]);
  ID= String(String(mac[0],HEX)+String(mac[5],HEX));
  Serial.println(ID);
}
void loop() {}
