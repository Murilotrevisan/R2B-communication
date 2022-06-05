#include "WiFi.h"
 
void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  Serial.println("----------------------------------------------")
  Serial.println("Bem vindo ao identificador de MAC addres da sua ESP")
  Serial.print("\r\nSeu endereço MAC é: \t")
  Serial.println(WiFi.macAddress());
  Serial.println("----------------------------------------------")
}
 
void loop(){

}
