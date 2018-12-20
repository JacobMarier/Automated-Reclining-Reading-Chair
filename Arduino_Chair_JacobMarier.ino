#include <Servo.h>
Servo top_hinge;//top half of chair
Servo bottom_hinge;  //bottom half of chair

int td; //top degree of rotation
int bd;  //bottom degree of rotation

int LEDpin=10;
int LEDpinTwo=5;
int LightSensor=A3;

int echopin=11;
int trigpin=12;

float distance;
int ctr=0;


void setup() { 
     //set for servo motors
     top_hinge.attach(7);
     bottom_hinge.attach(8);
    
     top_hinge.write(160);//beginning angle of top of chair
     bottom_hinge.write(58);//beginning angle of bottom of chair
    
    //set for Ultrasonic sensor
     pinMode(trigpin, OUTPUT);
     pinMode(echopin, INPUT);
    
    //Setup for Light
    pinMode(LEDpin, OUTPUT);
    pinMode(LEDpinTwo, OUTPUT);
    
    Serial.begin(9600);
    
    }



float Distance_Measure()
      {
      float c=345; //assuiming m/s
      float duration; // time in microsec
             
          digitalWrite(trigpin, LOW);
          delayMicroseconds(2);
          digitalWrite(trigpin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigpin, LOW);
      
      duration = pulseIn(echopin, HIGH);
      
      distance= duration*0.0345/2; //distance in cm
       
          Serial.print("\nThe Distance is ");
          Serial.print(distance);
      
      return distance;
      }




void loop()
      {delay(200);
       Distance_Measure();
       delay(250);
      
          if(10>distance)
             {ctr++;}
                    delay(100);
      
           if(ctr>2)ctr=0;
                     delay(100);
                     
                    if(ctr==0)
                        {top_hinge.write(160);//beginning angle of top of chair
                         bottom_hinge.write(58);}//beginning angle of bottom of chair
                                            
                    if(ctr==1)//
                      {top_hinge.write(125);
                       bottom_hinge.write(70);}
                                     
                    if(ctr==2) 
                       {top_hinge.write(93);
                       bottom_hinge.write(100);}

       //For Light
      int sensorValue = analogRead(LightSensor);
          Serial.print("\nThe Light Intensity is ");
          Serial.println(sensorValue);
          Serial.print("\n ");
          delay(250);
                
                if (sensorValue < 500 && sensorValue>=100)
                  {
                    digitalWrite(LEDpin, HIGH);
                                      }
                    else if (sensorValue < 100)
                    {
                      digitalWrite(LEDpin, HIGH);
                      digitalWrite(LEDpinTwo, HIGH);} 
                        else
                          {digitalWrite(LEDpin, LOW);
                          digitalWrite(LEDpinTwo, LOW);}}
            
    
      
