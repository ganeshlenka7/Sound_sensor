int sensorPin = 2;
int ledPin = 13;

bool ledState = false;

int lastSensorState = HIGH;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);
}

void loop() {

  int currentSensorState = digitalRead(sensorPin);

  // Detect only NEW sound event
  if (lastSensorState == HIGH && currentSensorState == LOW) {

    ledState = !ledState;

    digitalWrite(ledPin, ledState);

    delay(50);
  }

  lastSensorState = currentSensorState;
}