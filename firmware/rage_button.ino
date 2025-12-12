const int buttonPin = 7;
const int buzzerPin = 10;
bool alarmTriggered = false;
unsigned long alarmStart = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !alarmTriggered) {
    alarmTriggered = true;
    alarmStart = millis();
    digitalWrite(buzzerPin, HIGH);
  }

  if (alarmTriggered && millis() - alarmStart >= 10000) {
    digitalWrite(buzzerPin, LOW);
    alarmTriggered = false;
  }
}
