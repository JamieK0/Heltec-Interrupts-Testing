const int intPin = 17;
const int ledPin = 45;
int buttonState = 0;

void IRAM_ATTR ISR() {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
}

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  attachInterrupt(intPin, ISR, RISING);
  pinMode(ledPin, OUTPUT);
  pinMode(intPin, INPUT);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);

}

void loop() {
  buttonState = digitalRead(intPin);
  // put your main code here, to run repeatedly:
  Serial.println(buttonState);
}

