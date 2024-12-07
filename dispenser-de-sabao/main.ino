#define BUTTON 22
#define BUZZER 23
#define TRIGGER 5
#define ECHO 18
#define PIR 27

float distance;
float allowedDistance = 30;
int counter = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);        
  pinMode(PIR, INPUT); 
}

float getDistance() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  return pulseIn(ECHO, HIGH) * 0.034 / 2;
}

void loop() {
  distance = getDistance();

  if (digitalRead(PIR) && distance > 0 && distance <= allowedDistance) {
    Serial.print("Person detected. Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (digitalRead(BUTTON) == LOW) { // LOW indica que o botão foi pressionado
      delay(50);

      if (digitalRead(BUTTON) == LOW) {
        counter++;
        Serial.print("Dispenser was used. Total uses: ");
        Serial.println(counter);

        digitalWrite(BUZZER, HIGH);
        while (digitalRead(BUTTON) == LOW);
      }
    }
  }

  digitalWrite(BUZZER, LOW);
  delay(100);
}