#define RECEIVER 18     //A4
#define LED 7          //D7
void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(RECEIVER,INPUT);
  Serial.begin(9600);
}
void loop() 
{
  int val = analogRead(RECEIVER);
  Serial.println(val);
  digitalWrite(LED,HIGH);
  delay(val);
  digitalWrite(LED,LOW);
  delay(val);
}
