#include <WiFi.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

#define LED 23
#define BUTTON 21
#define WIFI_SSID "CIT_Alunos"
#define WIFI_SENHA "alunos@2024"

String TELEFONE = "559591258388";
String CALLMEBOT_API_KEY = "4882014";

void sendMessage(String message) {
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + TELEFONE + "&apikey=" + CALLMEBOT_API_KEY + "&text=" + urlEncode(message);
  HTTPClient http;
  http.begin(url);

  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int responseCode = http.POST(url);
  if (responseCode == 200) {
    Serial.println("Mensagem enviada");
  } else {
    Serial.println("Houve um erro");
  }

  http.end();
}

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  WiFi.begin(WIFI_SSID, WIFI_SENHA);

  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
}

void loop() {
  if (digitalRead(BUTTON)) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
    sendMessage("Socorro");
  }
}