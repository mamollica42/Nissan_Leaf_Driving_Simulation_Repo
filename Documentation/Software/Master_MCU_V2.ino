// Master MCU UART Handling
// Capstone Team 8
// Captures Serial data from up to 4 different MCUs and send its to the main PC

int pin3 = 3;  
int pin4 = 4;  
int pin5 = 5;  
int pin6 = 6;

double Gas1;
double Gas2;
double Brake1;
int Brake2;

int steering_pins[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
bool grey_code[10];
int binary = 0;
double pos, angle;

char shifter_data;
char last_pos = 'P';

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

   // Set digital pins 3 through 6 as inputs for Headlights
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT);

  // Set Analog pins 0-3 as inputs for Gas & Brake
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  // Set Digital pins 22-31 as inputs for Steering
  for (int i = 0; i < 10; i++)    // Set all pins to INPUT
  {
    pinMode(steering_pins[i], INPUT);
  }  
}

void loop() {  
    if (Serial1.available() > 0)
  {
    shifter_data = Serial1.read();

    if (shifter_data != 'X'){
        last_pos = shifter_data;
    }
        Serial.println();
        Serial.print("Shifter Info = ");
        Serial.print(last_pos);
        Serial.println();
  }

  //if (Serial1.available() > 0)
 // {
   // shifter_data = Serial1.read();
    //Serial.print("Shifter Info = ");
    //Serial.print(shifter_data);
  //}
  
  // Steering Code
  steering();

  // Auto-Light Code
  autoLight();

  // Accelerator & Brake Code
  pedals();
}

void autoLight()
{
  // Combine digital pins 3 through 6 into a 4-bit value
  byte combinedValue = digitalRead(pin3) << 3 | digitalRead(pin4) << 2 | digitalRead(pin5) << 1 | digitalRead(pin6);

  // Print the combined value in binary format to the serial monitor
  Serial.print("\n");
  Serial.print(combinedValue, BIN);

  // Check if the combined value is equal to binary (autolight)
  if (combinedValue == B0000) {
    Serial.println(" all off!");
  }

  // Check if the combined value is equal to binary(low beam)
  if (combinedValue == B0001) {
    Serial.println(" Low beam detected!");
  }
   // Check if the combined value is equal to binary(high beam)
  if (combinedValue == B0010) {
    Serial.println(" High beam detected!");
  }

   // Check if the combined value is equal to binary(blinker)
  if (combinedValue == B0011) {
    Serial.println(" High and low beam detected!");
  }
   // Check if the combined value is equal to binary(right indicator )
  if (combinedValue == B0100) {
    Serial.println(" right indicator!");
  }
   // Check if the combined value is equal to binary(low beam and right indicator )
  if (combinedValue == B0101) {
    Serial.println(" low beam and right indicator detected!");
  }
   // Check if the combined value is equal to binary(high beam and right indicator)
  if (combinedValue == B0110) {
    Serial.println(" High beam and right indicator detected!");
  }
   // Check if the combined value is equal to binary(high beam/low beam on and right indicator)
  if (combinedValue == B0111) {
    Serial.println(" high beam/low beam and right indicator detected!");
  }
   // Check if the combined value is equal to binary(left indicator)
  if (combinedValue == B1000) {
    Serial.println(" left indicator detected!");
  }
   // Check if the combined value is equal to binary(left indicator and Low beam detected!)
  if (combinedValue == B1001) {
    Serial.println("left indicator and Low beam detected!");
  }
   // Check if the combined value is equal to binary(left indicator and high beam detected)
  if (combinedValue == B1010) {
    Serial.println(" left indicator and high beam detected!");
  } // Check if the combined value is equal to binary(high beam/low beam on and left indicator detected)
  if (combinedValue == B1011) {
    Serial.println(" high beam/low beam and left indicator detected!");
  }
   // Check if the combined value is equal to binary(hazard light)
  if (combinedValue == B1100) {
    Serial.println(" hazard light!");
  }
   // Check if the combined value is equal to binary(hazard light and low beam!)
  if (combinedValue == B1101) {
    Serial.println(" hazard light and low beam!");
  }
   // Check if the combined value is equal to binary( hazard light and high beamlow beam)
  if (combinedValue == B1110) {
    Serial.println("  hazard light and high beam!");
  }
   // Check if the combined value is equal to binary(all)
  if (combinedValue == B1111) {
    Serial.println(" all on!");
  }

  // Wait for a short time before repeating the loop
  //delay(100);
}

void pedals()
{
  Gas1 = analogRead(A0);
  // Calculate the percent of the compression based on the max & min values measured.
  Gas1 = (Gas1 - 168) / 799;
  //Serial.print("Gas 1: ");
  //Serial.println(Gas1);

  Gas2 = analogRead(A1);
  Gas2 = (Gas2 - 84) / 411;
  //Serial.print("Gas 2: ");
  //Serial.println(Gas2);

  // Print Average of Gas1 & Gas2 for redudancy.
  Serial.print("Accelerator: ");
  Serial.println((Gas1 + Gas2)/2);

  Brake1 = analogRead(A2);
  Brake1 = (Brake1 - 285) / 432;
  Serial.print("Break 1: ");
  Serial.println(Brake1);

  // Redundant and not necessary
  Brake2 = analogRead(A3);
  //Serial.print("Break 2: ");
  //Serial.println(Brake2);
}

void steering()
{
  pos = grey_to_binary();     // Capture Binary output
  // Due to systematic and instrumental error in the steering of the Nissan Leaf
  // The angle was calculated by fine tuning and testing the left and right limits.
  // The team found that the vehicle wheel rotates slighty more to the right bound than
  // the left bound, so the distance from the center is not exactly symmetrical.
  angle = ((pos/1024) * 1292) - 639; // Convert Binary to angle based on 1200 degrees of rotation
  Serial.println();
  Serial.print("Steering Angle: ");
  Serial.print(angle);
}

int grey_to_binary()
{
  // Read Active Low Grey Code
  for (int i = 0; i < 10; i++)
  {
    grey_code[i] = !digitalRead(steering_pins[i]);
  }

  // Convert Grey to Binary
  binary = grey_code[9];  // MSB is the same
  
  for (int j = 8; j >= 0; j--)
  {
    binary = (binary << 1) | (grey_code[j] ^ (binary & 0x1));   
  }

  return binary;
}
