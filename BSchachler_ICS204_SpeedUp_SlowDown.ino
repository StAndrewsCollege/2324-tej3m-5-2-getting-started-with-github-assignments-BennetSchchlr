/*the robot move backward at maximum speed and slowly come to a stop then slowly comes to maximum speed while moving forward
 * 
 * Programmer: Bennet Schachler
 * 
 * Last updated:25th Nov. 2022
 */


//giving variable names to each pin
#define SpeedLeft 5 
#define SpeedRight 6
#define DirectionLeft 7
#define DirectionRight 8 
#define PowerAll 3

void forward(int speed){
  digitalWrite(DirectionRight, HIGH);
  analogWrite(SpeedRight,speed -14);
  digitalWrite(DirectionLeft, HIGH);
  analogWrite(SpeedLeft, speed);
  pinMode(PowerAll, OUTPUT);
  digitalWrite(PowerAll, HIGH);
  Serial.println("Forward");
}
void back(int speed){
  digitalWrite(DirectionRight, LOW);
  analogWrite(SpeedRight,speed+15);
  digitalWrite(DirectionLeft, LOW);
  analogWrite(SpeedLeft, speed);
  pinMode(PowerAll, OUTPUT);
  digitalWrite(PowerAll, HIGH);
  Serial.println("back");
}
void left(int speed){
  digitalWrite(DirectionRight, LOW);
  analogWrite(SpeedRight,speed);
  digitalWrite(DirectionLeft, HIGH);
  analogWrite(SpeedLeft, speed);
  pinMode(PowerAll, OUTPUT);
  digitalWrite(PowerAll, HIGH);
  Serial.println("left");
}
void right(int speed){
  digitalWrite(DirectionRight, HIGH);
  analogWrite(SpeedRight,speed);
  digitalWrite(DirectionLeft, LOW);
  analogWrite(SpeedLeft, speed );
  pinMode(PowerAll, OUTPUT);
  digitalWrite(PowerAll, HIGH);
  Serial.println("right");
}
void stopp(){
  digitalWrite(PowerAll, LOW);
  Serial.println("stopp");
}
void SpeedUpForward(){
  //robot goes from stopped to full speed moving forward
  for(int i=0; i<255; i++){
    forward(i);
    delay(20);
    
  }
  Serial.println("Speeds up forward");
}
void SlowDownForward(){
  //robot slows down from full speed to full stop 
  for(int i=255; i>=0; i--){
    forward(i);
    delay(20);
  }
  Serial.println("Slows down forward");
}
void SpeedUpBackwards(){
  for(int i=0; i<=255; i++){  
    back(i);
    delay(20);
  }
  Serial.println("Speeds up backward");
}
void SlowdownBackwards(){
  for(int i=255; i>=0; i--){  
    back(i);
    delay(20);
  }
  Serial.println("Slows down backward");
}

void setup() {
  // put your setup code here, to run once:
//setting the motor pins as OUTPUTS
pinMode(SpeedLeft, OUTPUT);
pinMode(SpeedRight, OUTPUT);
pinMode(DirectionLeft,OUTPUT);
pinMode(DirectionRight, OUTPUT);
pinMode(PowerAll, OUTPUT);
digitalWrite(PowerAll, HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //box 0 to one
  forward(140);
  delay(5600);
  stopp();
  delay(1000);
  //actions box one to two
  left(70);
  delay(850);
  stopp();
  delay(1000);
  forward(130);
  delay(3000);
  stopp();
  delay(1000);
  //actions box two to three
  right(70);
  delay(1120);
  stopp();
  delay(1000);
  forward(100);
  delay(6000);
  stopp();
  delay(1000);
  //actions box three to four
  right(70);
  delay(800);
  stopp();
  delay(1000);
  forward(140);
  delay(6300);
  stopp();
  delay(1000);
  //actions infront of box 4 into box 4
  left(70);
  delay(1000);
  stopp();
  delay(1000);
  forward(140);
  delay(1000);
  stopp();
  delay(100000);
  
  

}
