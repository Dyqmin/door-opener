String incomingString = "";
int relaySignalPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(relaySignalPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incomingString = Serial.readString();

    if (incomingString.length() > 0) {
      digitalWrite(relaySignalPin, HIGH);
      delay(1000);
      digitalWrite(relaySignalPin, LOW);
      delay(1000);
    }
  }
  delay(200);
}
