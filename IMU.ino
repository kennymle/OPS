#include <IMU.h>
#include <sensor_fusion.h>
extern float IMU_X;
extern float IMU_Y;
extern float IMU_Z;
#define LED_X 3
#define LED_Y 5
#define LED_Z 6
int X_new=0;
int Y_new=0;
int Z_new=0;
void setup() {
  
imu_setup();
pinMode(LED_X,OUTPUT);
pinMode(LED_Y,OUTPUT);
pinMode(LED_Z,OUTPUT);
Serial.begin(9600);
}

void loop() {
delay(1000);
imu_loop();
  X_new=map(IMU_X*100,-100,100,0,225); 
  Y_new=map(IMU_Y*100,-100,100,0,225); 
  Z_new=map(IMU_Z*100,-100,100,0,225); 
  analogWrite(LED_X,X_new);
  analogWrite(LED_Y,Y_new);
  analogWrite(LED_Z,Z_new);
Serial.print("X:");
Serial.println((int)(IMU_X*100));
Serial.print("Y:");
Serial.println((int)(IMU_Y*100));
Serial.print("Z:");
Serial.println((int)(IMU_Z*100));

}
