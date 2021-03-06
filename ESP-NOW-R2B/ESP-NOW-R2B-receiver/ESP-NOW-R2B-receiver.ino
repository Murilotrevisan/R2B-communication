

#include <esp_now.h>
#include <WiFi.h>


// Must match the sender structure
typedef struct message_t {
    char text[32];
    int temp,cnt;
    float humid;
    bool test;
} message_t;

// Create a struct_message called myData
message_t myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.println("----------------------------------------------");
  Serial.print("Data received: ");
  Serial.println(len);
  Serial.print("text: ");
  Serial.println(myData.text);
  Serial.print("temperature: ");
  Serial.println(myData.temp);
  Serial.print("humid: ");
  Serial.println(myData.humid);
  Serial.print("test: ");
  Serial.println(myData.test);
  Serial.print("packet number: ");
  Serial.println(myData.cnt);
  Serial.println("----------------------------------------------");
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Registering callback function of receiving messages
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}
