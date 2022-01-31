#define switchinputB 4
#define switchinputA 2
#define ledoutputY 5
void setup() {
  // put your setup code here, to run once:
  pinMode(ledoutputY,OUTPUT);
pinMode(switchinputA,INPUT);
pinMode(switchinputB,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(switchinputA)==HIGH && digitalRead(switchinputB)==HIGH)
  {
    digitalWrite(ledoutputY,HIGH);
  }
  else
  {
      digitalWrite(ledoutputY,LOW);
  }
  
}
