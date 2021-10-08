#define RECIEVER 0
#define TRANSMITER 1 
#define yellow 13 //D13 yellow LED
#define red 12 //D17 red LED
char byteRead;

int count = 0;
int randNumber;

void setup() {
Serial.begin(9600);
pinMode(yellow, OUTPUT);
pinMode(red, OUTPUT);

randNumber= random(0,2);
Serial.println(randNumber);
if (randNumber==0){
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
}
else if(randNumber ==1){
  digitalWrite(red,HIGH);
  digitalWrite(yellow,LOW);
}
}

void loop() {
if(Serial.available()>0){
  byteRead =Serial.read();
  if(randNumber==0&&byteRead=='a'){
  count++;
  Serial.write('y');
  Serial.println(count);
  }
  
  else if(randNumber==0&&byteRead=='b'){
    Serial.println(count);
    count=0;
    Serial.print("Game Reset. Score is set to ");
    Serial.println(count);
    Serial.write('n');
  }
  else if(randNumber==1&&byteRead=='b'){
  count++;
  Serial.write('y');
  Serial.println(count);
  }
  else if(randNumber==1&&byteRead=='a'){
    Serial.println(count);
    count=0;
    Serial.print("Game Reset. Score is set to ");
    Serial.println(count);
    Serial.write('n');
  }
randNumber= random(0,2);
Serial.println(randNumber);
if (randNumber==0){
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
}
else if(randNumber ==1){
  digitalWrite(red,HIGH);
  digitalWrite(yellow,LOW);
}
}
}

/*if (Serial.available()>0){
  if (count%2==0){
    digitalWrite(LED, HIGH);
    count++;
  }
  else {
    digitalWrite(LED, LOW);
    count++;
  }
  byteRead = Serial.read();
  Serial.println(byteRead);
}*/
//  while(byteRead!='a'&&byteRead!='b'){ //if (byteRead=='t'){
//    Serial.println(byteRead);
//    
//    byteRead=Serial.read();
//    }
/*  else if(byteRead=='b'){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
  }
  else{
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
  }
  Serial.println(byteRead);
}
} */
