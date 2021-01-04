// Includes the Servo library
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;

int v[180]={0},v1[180]={0},j,ban=0,a[180]={0},a1[180]={0};
// Variables for the duration and the distance
long duration;
int distance;

Servo myServo; // Creates a servo object for controlling the servo motor
void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
}
 
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  /*for(j=0;j<=180;j++)
  {
  v[j]=0;
  v1[j]=0;  
  a[j]=0;
  a1[j]=0; 
  }*/
  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(50);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
 
  if(ban<3)
  {
      v[i]=distance; 
     a[i]=i; 
     if(v[i]==v1[i]&&a[i]==a1[i])
     {
      ban=ban+1;
     }
   Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
 Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }else
  {
    distance=100;
    Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);
  Serial.print(".");
  ban=0 ; 
  }
  }
  
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(50);
  distance = calculateDistance();
    
  if(ban<=9)
  {
     v1[i]=distance;
      a1[i]=i;  
     if(v[i]==v1[i]&&a[i]==a1[i])
     {
      ban=ban+1;
     }
     Serial.print(i);
  Serial.print(",");
  Serial.print(distance); 
  Serial.print("."); 
  }else
  {
    distance=100;
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print("."); 
  }
  }
  
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance()
{ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);   
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  
  distance= duration*0.034/2;

  return distance;
}
