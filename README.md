# Maloca das iCoisas

Projetos realizados no curso Maloca das iCoisas pelo grupo 13 - Os Suricatos Cibernéticos.

## Equipe

- Eduardo Henrique Freire Machado;
- Gabriel Peixoto Menezes da Costa;
- Natália Ribeiro de Almada;

## Projetos Realizados

1. [Botão do Pânico](./botao-do-panico)

Este projeto implementa um **botão de pânico** utilizando o ESP32. O sistema permite o envio de uma mensagem de alerta via WhatsApp usando a API do **CallMeBot**, ao mesmo tempo que aciona um LED (ou buzzer) como sinal visual e sonoro. O projeto é ideal para situações de emergência, oferecendo uma solução rápida e simples para solicitar ajuda.

---

## **Funcionalidades**
- **Envio de mensagens de alerta via WhatsApp:** A mensagem "Socorro" é enviada para um número configurado.
- **Alerta visual e sonoro:** Um LED ou buzzer é acionado para reforçar a sinalização.
- **Conexão via WiFi:** O sistema utiliza a rede WiFi para acessar a API do CallMeBot.

---

## **Pré-requisitos**
1. **Hardware Necessário:**
   - ESP32.
   - Botão push-button.
   - LED ou buzzer.
   - Protoboard e jumpers.
   - Resistor (100Ω recomendado, caso utilize LED).

2. **Software Necessário:**
   - Arduino IDE.
   - Biblioteca **WiFi.h** (inclusa no suporte ao ESP32).
   - Biblioteca **UrlEncode**:
     - Instale em **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas**.

3. **Conta no CallMeBot:**
   - Salve o número **+34 644 81 58 78** no WhatsApp.
   - Envie a mensagem:  
     ```
     I allow callmebot to send me messages
     ```
   - Anote a API Key fornecida.

---

## **Configuração do Código**
Antes de carregar o código no ESP32, personalize as seguintes variáveis:

### **1. Rede WiFi:**
Adicione o nome (`SSID`) e a senha da sua rede WiFi:
```cpp
#define WIFI_SSID "INSIRA_O_NOME_DO_WIFI_AQUI"
#define WIFI_SENHA "INSIRA_A_SENHA_DO_WIFI_AQUI"

### **2. Número de WhatsApp e API Key:**
Adicione o número de telefone no formato internacional e a chave API fornecida pelo CallMeBot:

```cpp
String TELEFONE = "INSIRA_SEU_TELEFONE_AQUI";
String CALLMEBOT_API_KEY = "INSIRA_SUA_CHAVE_DO_CALLMEBOT_AQUI";



