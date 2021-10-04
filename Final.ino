 //Multilevel Smart Home Security System
#include<SoftwareSerial.h> // This is pre-processor direactive, SoftwareSerial is library function and .h means its an header file
const int trigPin = 8;
const int echoPin = 9;
const int buzzer = 10;
const int pirPin=11;
const int ledPin = 13;
#define variables // define the variables to be use
long duration; 
int distance;
int safetyDistance;  
int pirCheck;

void setup() 
{
// setting which pin is use for input and output using pinMode command
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(pirPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // baud rate of serial monitor (arduino)
}

void loop()
{
//clears the trigger pin in case it was high before
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
//set the trigger pin on high state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
//reads the echoPin returns the sound wave travel time in micro seconds
duration = pulseIn(echoPin, HIGH);
//calculating the distance in centimeter
distance= duration*0.034/2; // distance=time*speed/2
safetyDistance = distance;
pirCheck=digitalRead(pirPin);

    if((safetyDistance <= 80) && (pirCheck==HIGH))
    {
    // prints the distance on serial monitor
    Serial.println("Intruder Detected");
    Serial.print("Safety Distance: ");
    Serial.println(distance);
    digitalWrite(ledPin, HIGH);
    tone(buzzer,1050,2000); // pinNumber, hrz, delay
    delay(2000);
    Serial.println("ATD+917086829946;"); 
    tone(buzzer,3050,2000);
    delay(2000);
    tone(buzzer,1050,2000);
    delay(2000);
    tone(buzzer,3050,2000);
    delay(2000);
    tone(buzzer,1050,2000); 
    delay(2000);
    tone(buzzer,3050,2000); 
    delay(2000);
    tone(buzzer,1050,2000);
    delay(2000); 
    tone(buzzer,3050,2000); 
    delay(2000);
    tone(buzzer,1050,2000); 
    delay(2000);
    tone(buzzer,3050,2000); 
    delay(2000);
    tone(buzzer,1050,2000); 
    delay(2000);
    Serial.println("ATH");
    delay(500);
    Serial.println("AT+CMGF=1"); //gsm enters into the text mode
    delay(500);
    Serial.println("AT+CMGS=\"+917086829946\"\r");//enter the number you want to alert ("AT+CMGS=\"x\"\r");
    delay(500);
    Serial.println("ALERT...!!!!Someone peeked into your house...!!!!"); // enter the message you want to send
    delay(500);
    Serial.println(char(26)); // ASCII code ctrl z, gsm comes out of text mode
    delay(500); 
    }
    else
    {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
    }
// prints the distance on serial monitor
Serial.print("Safety Distance: ");
Serial.println(distance);
}
