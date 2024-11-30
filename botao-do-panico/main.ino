#include <WiFi.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

#define BUTTON 21
#define LED_BUZZER 23
#define WIFI_SSID "INSIRA_O_NOME_DO_WIFI_AQUI" // IMPORTANTE
#define WIFI_SENHA "INSIRA_A_SENHA_DO_WIFI_AQUI" // IMPORTANTE

String TELEFONE = "INSIRA_SEU_TELEFONE_AQUI"; // IMPORTANTE
String CALLMEBOT_API_KEY = "INSIRA_SUA_CHAVE_DO_CALLMEBOT_AQUI"; // IMPORTANTE

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
  pinMode(LED_BUZZER, OUTPUT);

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
    digitalWrite(LED_BUZZER, LOW);
  } else {
    digitalWrite(LED_BUZZER, HIGH);
    sendMessage("Socorro");
    Serial.print("O pedido de socorro foi enviado e os dispositivos de alerta foram acionados.");
  }
}
