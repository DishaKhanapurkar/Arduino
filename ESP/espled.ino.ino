#define ledPin 4
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, HIGH);
  delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledPin, HIGH);
  delay(1000);
 
  digitalWrite(ledPin, LOW);
  delay(1000);
}
