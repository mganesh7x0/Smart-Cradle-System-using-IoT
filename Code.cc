#include <Servo.h>


#define switchpin 0 
#define TempPin 0 
#define Buzzer 5 
#define MoistPin 1 
#define ServoPin 7 


Servo Servo1;
int value; 
double angle = 45; int offtime=100; 
float voltage =5.0;

void setup() 
{
  Servo1.attach(ServoPin);
  Servo1.write(angle);
  pinMode(switchpin, INPUT); 	
  pinMode(TempPin,INPUT);	
  pinMode(Buzzer, OUTPUT);		
  pinMode(MoistPin,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  value = digitalRead(switchpin);
  if(value == HIGH) {
    
    
    for(int angle=45; angle<90; angle++){ 
    	Servo1.write(angle); 	 
    	delay(50); 				 
  	}
  	for(int angle=90; angle>0; angle--){ 
    	Servo1.write(angle);
    	delay(50); 
  	}
  	for(int angle=0; angle<45; angle++){
      	Servo1.write(angle);
      	delay(50);
  	}
  	delay(offtime);
  }
  else {    
    Servo1.write(45);   
    delay(offtime);
  }
  
  
  int sensorRead = analogRead(TempPin);
  float voltageOut = sensorRead * (voltage / 1024.0);
  float temp = (voltageOut - 0.5) * 100;
  
  if(temp < 36.8 || temp > 37.3){
  	Serial.print("Not Normal temperature\n");
    tone(Buzzer, 500);
  }
  else{
    Serial.print("Normal Temperature\n");
    noTone(Buzzer);
  }
  
  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.print("\n");
  
  
  
  int Moisture=analogRead(MoistPin);
  if(Moisture>0)
    tone(Buzzer, 220);
  else
    noTone(Buzzer);
  Serial.print("Moisture val : ");
  Serial.print(Moisture);
  Serial.print("\n");
}

