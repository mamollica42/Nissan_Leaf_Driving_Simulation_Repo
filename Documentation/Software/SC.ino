int pin2 = 2;  
int pin3 = 3;  
int pin7 = 4;  
int pin6 = 6; 
char ShifterPos; 

int Count = 0;

void setup() {
  // Set digital pins 3 through 5 as inputs
  pinMode(PIN2, INPUT); // Park
  pinMode(PIN3, INPUT); // Neutral
  pinMode(PIN7, INPUT); // Drive
  pinMode(PIN6, INPUT); // Reverse
  
  // Set serial monitor for output
  Serial.begin(115200);
}

void loop() {
  
  // Combine digital pins 2 through 5 into a 4-bit value
  byte combinedValue = digitalRead(PIN2) << 3 | digitalRead(PIN3) << 2 | digitalRead(PIN7) << 1 | digitalRead(PIN6);
  pin7 = digitalRead(PIN7);
  if (combinedValue == B1110) {
    ShifterPos = 'R';
    delay(100); 
  }
  else if (combinedValue == B1011) {
      ShifterPos = 'N';
  }
  else if(combinedValue == B1001) {
    ShifterPos = 'D';
    delay(100);
  }
  //else if (pin7 == 0) {
    //ShifterPos = 'D';    
  //}
  else if(combinedValue == B0111) {
    ShifterPos = 'P';
   
  }
  else{
    ShifterPos = 'X';
  }
  
 
  Serial.write(ShifterPos);
  //Serial.println(combinedValue, BIN);
  delay(20);
  

  
}