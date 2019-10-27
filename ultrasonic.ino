//#include <LiquidCrystal.h>

#include <LiquidCrystal.h>

//#include <LiquidCrystal.h>
LiquidCrystal lcd(11,12,1,2,3,4);
const int trigPin = 7;
const int echoPin = 6;
long duration;
long distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.0342/2;

  Serial.println("Distance: ");
  Serial.println(distance);
  lcd.setCursor(0,0);
  lcd.print("distance:");
  lcd.print(distance);
  
}
