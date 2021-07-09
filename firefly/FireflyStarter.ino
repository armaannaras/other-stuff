int ledPin = 13;
int photo1Pin = A0;
int photo2Pin = A2;
int photo3Pin = A3;

int photo1Res;
int photo2Res;
int photo3Res;

int photo1Threshold = 800;
int photo2Threshold = 800;
int photo3Threshold = 800;


unsigned long currentTime;


unsigned long nextActivation; //The time at which the next activation phase will begin
unsigned long activationDelay = 1500; //The time between the end of a blink and the next activation


unsigned long nextPrint; //The next time at which something should be printed
unsigned long printDelay = 100; //Time between print statements (feel free to change)

unsigned long onTime; //The time at which the LED will turn on
unsigned long offTime; //The time at which the LED will turn off
unsigned long onDelay = 1000; //Time between activation and the LED turning on
unsigned long offDelay = 500; //Time between LED turning on and off


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  currentTime = millis();
  nextPrint = currentTime + nextPrint;

  //TODO 1: Use currentTime and activationDelay to set the time of your first activation (theta)
  nextActivation= currentTime + activationDelay;
  
 
}


void loop() { 

  currentTime = millis();

  if (currentTime > nextActivation) // Activation Phase
  {

    onTime = currentTime + onDelay;
    offTime = onTime + offDelay;
    nextActivation = offTime + activationDelay;

    
    Serial.println("I am blinking soon");
  }
  
  //Blinking phase+
  if ((currentTime > onTime) and (currentTime < offTime)){
    digitalWrite(ledPin, HIGH);
    Serial.println("Blinking now!");
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  
  photo1Res = analogRead(photo1Pin);
  photo2Res = analogRead(photo2Pin);


  if(currentTime > nextPrint){
      Serial.print("P1: ");
      Serial.println(photo1Res);
      Serial.print("P2: ");
      Serial.println(photo2Res);
  }
  
  Perception Phase
  if (photo1Res > 1000 or photo2Res > 1000){
    nextActivation = currentTime + activationDelay;
   Serial.println("Saw another blink");
  }
}
