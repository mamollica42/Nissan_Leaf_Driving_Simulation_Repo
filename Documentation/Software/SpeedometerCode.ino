#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"
#include "SPI.h" 
#include <SoftwareSerial.h>

// define color
#define BLACK 0x0000
#define NAVY 0x0004
#define DARKGREEN 0x03E0
#define DARKCYAN 0x03EF
#define MAROON 0x7800
#define PURPLE 0x780F
#define OLIVE 0x7BE0
#define LIGHTGREY 0xC618
#define DARKGREY 0x7BEF
#define BLUE 0x001F
#define GREEN 0x07E0
#define CYAN 0x07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define ORANGE 0xFD20
#define GREENYELLOW 0xAFE5
#define PINK 0xF81F
#define RX 10
#define TX 11

int character_location;
unsigned int speed = 0;
unsigned int curSpeed;
int store = 0;
int CS=A3;
int RS=A2;
int WR=A1;
int RD=A0;
int RST=A4;
MCUFRIEND_kbv tft(A3, A2, A1, A0, A4);
//Variables


const int buffer_size=16; //buffer size and buffer used to recieve the
byte buf[buffer_size]; //data from Simulink

float output;
float output_current;

#define RX 10
#define TX 11



SoftwareSerial esp8mod(RX,TX);


void setup() {
  uint16_t ID = tft.readID(); 
  tft.begin(ID); 
  tft.setRotation(1);
  tft.fillScreen(NAVY);
  tft.fillRect(170, 120, 220, 90, NAVY);
  tft.setTextColor(WHITE);
  Serial.begin(9600);
  esp8mod.begin(115200);
}

void loop() {
      
    if (Serial.available() > 0 ){
      speed = Serial.read();
          
    }
    
      tft.setCursor(122, 120);
      tft.setTextSize(14);
      tft.print(speed);
      delay(500);
      tft.fillRect(122, 120, 250 , 100, NAVY);
          
    
}



