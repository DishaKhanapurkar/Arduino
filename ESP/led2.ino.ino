#define switchinputB 5
#define switchinputA 2
#define ledoutputY 4
#define switchinputC 3
int prev=0;
int state=0;
int counter=0;

void setup() {
  // put your setup code here, to run once:
pinMode(ledoutputY,OUTPUT);
pinMode(switchinputA,INPUT);
pinMode(switchinputB,INPUT);
Serial.begin(9600);
}


void loop() {
   if(digitalRead(switchinputC)==HIGH)
   {
   //prev=1;
   counter=counter+1;
   if(counter>=20)
   {
    prev=1;
    
   }
   }
   
  // put your main code here, to run repeatedly:
  if(digitalRead(switchinputC)==LOW && prev==1)
  {
    prev=0;
    counter=0;
    state=state+1;
  }
  if(state>3)
  state=0;
  Serial.println(state);
    
  }
