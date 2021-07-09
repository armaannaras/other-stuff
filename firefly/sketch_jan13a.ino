   

//Variables
int value;          

void setup(){
 Serial.begin(9600);
 pinMode(9, OUTPUT);  // 
 pinMode(A0, INPUT);//
}
void loop(){
  value = analogRead(A0);
  
  //
  if (value > 850){
    digitalWrite(9, HIGH);
  }
  else{
    digitalWrite(9, LOW); 
  }
  Serial.println (value);
}
