#include<ESP32Servo.h>
Servo myservo;


int enable=2;
int input1=18;
int input2=19;

int buttonCloseA=22;
int buttonOpenA=34;

int buttonCloseB=12;
int buttonOpenB=26;

void setup() {
  myservo.attach(14);
pinMode(enable,OUTPUT);
pinMode(input1,OUTPUT);
pinMode(input2,OUTPUT);
pinMode(buttonCloseA,INPUT);
pinMode(buttonCloseB,INPUT);

pinMode(buttonOpenA,INPUT);
pinMode(buttonOpenB,INPUT);


Serial.begin(9600);
  
}
void loop() {
int closeVal_A=digitalRead(buttonCloseA);    
int OpenVal_A=digitalRead(buttonOpenA);

int closeVal_B=digitalRead(buttonCloseB);    
int OpenVal_B=digitalRead(buttonOpenB);


Serial.println(closeVal_A);
Serial.println(OpenVal_A);
Serial.println(closeVal_B);

Serial.println();


if(closeVal_A==HIGH){
        
digitalWrite(input1,HIGH);
digitalWrite(input2,LOW);
analogWrite(enable,200);
  
  }

 else if(OpenVal_A==HIGH){
        
digitalWrite(input1,LOW);
digitalWrite(input2,HIGH);
analogWrite(enable,200);
  
  }

   else if(closeVal_B==HIGH){
       
        myservo.write(180);
  
  }

   else if(OpenVal_B==HIGH){
      
        myservo.write(30);
  
  }

  else {
    digitalWrite(input1,LOW);
digitalWrite(input2,LOW);
analogWrite(enable,0);
    
    }

      


  }

      
