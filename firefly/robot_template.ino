#define MOTOR_A_1A 9   // right
#define MOTOR_A_1B 10   // right
#define MOTOR_B_1A 5   // left
#define MOTOR_B_1B 6   // left
#include <NewPing.h>

int left_sen = A0;  //A = left
int center_sen = A1; // B = center
int right_sen = A2; //C = right
int ValSens_A = 0;
int ValSens_B = 0;
int ValSens_C = 0;

//FRONT SENSOR
#define TRIGGER_FRONT 3
#define ECHO_FRONT 4


//LEFT SENSOR
#define TRIGGER_LEFT 12
#define ECHO_LEFT 13
#define MAX_DISTANCE 200

NewPing leftsonar (TRIGGER_LEFT, ECHO_LEFT, MAX_DISTANCE);
NewPing frontsonar (TRIGGER_FRONT, ECHO_FRONT, MAX_DISTANCE);

#define LEFTTHRESHOLD 20
#define FRONTTHRESHOLD 20

#define centerThres 200
#define leftThres 300
#define rightThres 300

void setup() {
Serial.begin(9600);

pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);


  /*
   * SET YOUR MOTORS AND YOUR SENSORS
   */
  
}

void loop(){

 
  forward();
 delay(1000);
  stop_rob();
  delay(1000);
  
 back();
  delay(1000);
  stop_rob();
  delay(1000);
  
  right();
delay(1000);
stop_rob();
delay(1000);
  
  left();
delay(1000);
stop_rob();
delay(1000);




 /*
  * CALL YOUR FUNCTIONS
  * EXAMPLE BELOW
  * 
  * // call the forward function for 1 second
  * // the delay is 1000 ms
  * 
  * forward();
  * delay(1000);
  */
}

void forward() {
  analogWrite(MOTOR_A_1A, 0);
  analogWrite(MOTOR_A_1B, 255);

  analogWrite(MOTOR_B_1A, 0);
  analogWrite(MOTOR_B_1B, 255);
 }

 void back () {
 analogWrite(MOTOR_A_1A, 255);
 analogWrite(MOTOR_A_1B, 0);

 analogWrite(MOTOR_B_1A, 255);
 analogWrite(MOTOR_B_1B, 0);
 }
 
 void stop_rob() {
  analogWrite(MOTOR_A_1A, 0);
  analogWrite(MOTOR_A_1B, 0);

  analogWrite(MOTOR_B_1A, 0);
  analogWrite(MOTOR_B_1B, 0);
}


void right() {
  analogWrite(MOTOR_A_1A, 255);
  analogWrite(MOTOR_A_1B, 0);

  analogWrite(MOTOR_B_1A, 0);
  analogWrite(MOTOR_B_1B, 255);
}

void left() {
  analogWrite(MOTOR_A_1A, 0);
  analogWrite(MOTOR_A_1B, 255);

  analogWrite(MOTOR_B_1A, 255);
  analogWrite(MOTOR_B_1B, 0);
}
/*
 *  void forward() {
          //LEFT MOTOR
          analogWrite(LEFTMOTORA, HIGH);
          analogWrite(LEFTMOTORB, LOW);
          //RIGHT MOTOR
          analogWrite(RIGHTMOTORA, HIGH);
          analogWrite(RIGHTMOTORB, LOW);
        }
 */
