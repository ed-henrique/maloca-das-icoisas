# Botão do Pânico

O botão do pânico é um dispositivo de segurança utilizado para alertar rapidamente autoridades ou serviços de emergência em situações de risco, como assaltos, sequestros ou agressões. Ele pode ser um botão físico ou uma função em dispositivos móveis, como aplicativos de celular, e ao ser acionado, envia um sinal discreto para a polícia, familiares ou centros de monitoramento. Casos comuns de uso incluem em situações de violência doméstica, em estabelecimentos comerciais durante um assalto, por profissionais que trabalham sozinhos em locais isolados ou por pessoas em risco iminente de perigo, como idosos ou pessoas com deficiência.

## Metas

Ao apertar o botão, devem ser realizadas essas ações:

- Envio de mensagem de socorro via Whatsapp;
- Alerta sonoro via buzzer;
- Log deve ser mostrado na tela e armazenado em banco de dados;

## Requisitos

### Hardware

- 1x ESP32;
- 1x LED;
- 1x Buzzer;
- 1x Botão;

### Software

- Acesso à API do Whatsapp [CallMeBot](https://www.callmebot.com/blog/free-api-whatsapp-messages/);

## Simulação

![Simulação](./sim.jpeg)

![Simulação com Indicação](./sim2.png)

- O pino 21 se conecta ao resistor de 330 ohms e ao polo positivo do buzzer;
- O pino 23 se conecta ao botão;
- O GND se conecta ao botão, ao polo negativo do LED e ao polo negativo do buzzer;
- O resistor se conecta ao polo positivo do LED;

## *Proof of Concept (PoC)*

https://github.com/user-attachments/assets/694ea2ef-6716-475d-92dc-67022a44746a
