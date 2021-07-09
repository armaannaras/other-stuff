+
int pr0 = A0; //pr0 is photoresistor0 input A0
int pr1 = A1; //pr1 is photoresistor1 input A1
int pr2 = A2; //pr2 is photoresistor2 input A2
int pr3 = A3; //pr3 is photoresistor3 input A3 
int pr4 = A4; //pr4 is photoresistor4 input A4

int pr0reading = 0; //is the data value reading of pr0 
int pr1reading = 0; //is the data value reading of pr1 
int pr2reading = 0; //is the data value reading of pr2 
int pr3reading = 0; //is the data value reading of pr3 
int pr4reading = 0; //is the data value reading of pr4 

int output_led = 13;
int ledG = 2;
int ledR = 3;

int pr0threshold = 900; // photoresistor0's threshold
int pr1threshold = 900; // photoresistor1's threshold
int pr2threshold = 900; // photoresistor2's threshold
int pr3threshold = 700; // photoresistor3's threshold
int pr4threshold = 650; // photoresistor4's threshold


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (ledG, OUTPUT);
  pinMode (ledR, OUTPUT);

}

void loop() {
      int pr0reading = analogRead(pr0);
      int pr1reading = analogRead(pr1);
      int pr2reading = analogRead(pr2);
      int pr3reading = analogRead(pr3);
      int pr4reading = analogRead(pr4); 

      Serial.print("P0: ");
      Serial.println(pr0reading);
      Serial.print("P1: ");
      Serial.println(pr1reading);
      Serial.print("P2: ");
      Serial.println(pr2reading);
      Serial.print("P3: ");
      Serial.println(pr3reading);
      Serial.print("P4: ");
      Serial.println(pr4reading);
      delay(600);

  if (pr0reading < pr0threshold && pr1reading < pr1threshold && pr2reading < pr2threshold && pr3reading < pr3threshold && pr4reading < pr4threshold)
  { digitalWrite (ledG, HIGH);
    digitalWrite (ledR, LOW);
  }
    else
    {
      digitalWrite (ledG, LOW);
      digitalWrite (ledR, HIGH);
    }

}
