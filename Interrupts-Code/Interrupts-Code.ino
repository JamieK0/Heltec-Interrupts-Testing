const int intPin = 17;
const int ledPin = 45;
int buttonState = 0;

unsigned long button_time = 0;  
unsigned long last_button_time = 0; 

void IRAM_ATTR ISR() {
    button_time = millis();
    if (button_time - last_button_time > 250)
    {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    last_button_time = button_time;
}
}

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  attachInterrupt(intPin, ISR, FALLING);
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

