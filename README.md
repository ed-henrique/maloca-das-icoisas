# Maloca das iCoisas

Projetos realizados no curso Maloca das iCoisas pelo grupo 13 - Os Suricatos Cibernéticos.

## Equipe

- Eduardo Henrique Freire Machado;
- Gabriel Peixoto Menezes da Costa;
- Natália Ribeiro de Almada;

## Projetos Realizados
O código-fonte para a implementação real do projeto está disponível no seguinte arquivo:  
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

===========0---=-0=-0-0-0-=0=

Antes de compilar e carregar o código no ESP32, certifique-se de modificar os seguintes dados no arquivo para adequá-los à sua rede WiFi e conta do CallMeBot:

1. **Credenciais da Rede WiFi:**
   - Substitua `SEU_SSID` e `SUA_SENHA` pelos dados da sua rede:
     ```cpp
     const char* ssid = "SEU_SSID";
     const char* password = "SUA_SENHA";
     ```

2. **Dados do CallMeBot:**
   - Atualize o número de WhatsApp e a API Key fornecida pelo CallMeBot:
     ```cpp
     String phoneNumber = "SEU_NUMERO_WHATSAPP";
     String apiKey = "SUA_APIKEY";
     ```
---

## **Configuração do CallMeBot**

> **Nota:** O serviço CallMeBot exige uma configuração inicial no WhatsApp para permitir o envio de mensagens. Siga os passos abaixo para configurá-lo.

- . **Salve o número do CallMeBot:**  
   Salve o número **+34 644 81 58 78** nos seus contatos do WhatsApp com um nome como "CallMeBot".

- . **Envie uma mensagem de autorização:**  
   Abra o WhatsApp e envie para o contato "CallMeBot" a mensagem abaixo:

   ```text
   I allow callmebot to send me messages

- . **Mensagem Personalizada:**
   - Altere a mensagem que será enviada:
     ```cpp
     String mensagem = "ALERTA! Estou em perigo. Preciso de ajuda imediatamente.";
     ```

---

## **Passos para Implementação**
1. **Configuração do Ambiente:**
   - Instale a [IDE Arduino](https://www.arduino.cc/en/software).
   - Configure a placa ESP32 na IDE.

2. **Montagem do Circuito:**
   - Conecte os componentes ao ESP32:
     - Botão no GPIO 21.
     - LED externo (com resistor de 100Ω) no GPIO 23.
     - LED interno no GPIO 2.

3. **Teste e Upload:**
   - Abra o arquivo `main.ino` na IDE Arduino.
   - Faça as modificações necessárias e carregue o código no ESP32.
   - Pressione o botão e verifique o funcionamento:  
     - O LED externo piscará durante o envio.
     - A mensagem será enviada para o WhatsApp configurado.

---

Para dúvidas ou problemas abra uma **issue**. 😊
