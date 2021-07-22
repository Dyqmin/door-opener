String incomingString = "";
String text = "info: ";
int ledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incomingString = Serial.readString();

    if (incomingString.length() > 0) {
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
      delay(1000);
    }
  }
  Serial.println(text);
  delay(200);
}
