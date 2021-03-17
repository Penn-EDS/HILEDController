// Please use old bootloader
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_Si7021.h"
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);
Adafruit_Si7021 sensor = Adafruit_Si7021();
#include <SPI.h>
#include <SD.h>
File myFile;
char filename[15];//array for the file name
const int SDcs = 10;  //SD slave pin
int SDcounter = 0;



#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#define BA 2
#define BB 4
#define BC 3
#define RELAY 7



int ButtonACstate=LOW;
unsigned long starttime=0;
unsigned long SessionLengthMinutes = 2;
unsigned long SessionLengthHours = 0;
unsigned long SessionLengthInMiliseconds = 0;

float temp=0.0;
float lux=0.0;
  
void setup() {
  
Serial.begin(9600);

while (!Serial) {
    delay(10);
  }
  
pinMode(BA, INPUT_PULLUP); // button A
pinMode(BB, INPUT_PULLUP); // button B
pinMode(BC, INPUT_PULLUP); // button C
pinMode(RELAY, OUTPUT);
pinMode(SDcs, OUTPUT);
digitalWrite(SDcs,HIGH);


display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)

display.clearDisplay();




//    display.clearDisplay();
//    display.setTextSize(1);
//  display.setTextColor(WHITE);
//  display.setCursor(0,0);
//  display.print("Valve Open");
//  display.setCursor(25,50);
//  display.print("4");
//  display.println("%");
//  display.display();

  //delay(2000);

  
  if (!sensor.begin()) {
    Serial.println("Did not find Si7021 sensor!");
    while (!sensor.begin()){
      
    }
    Serial.println("Found Si7021 sensor!");
  }

  if (!tsl.begin()) {
    Serial.println("Did not find TSL2591 sensor!");
    while (!tsl.begin()){
      
    }
    Serial.println("Found TSL2591 sensor!");
  }

  configureSensor();

  
//------SD card initialization------------
 digitalWrite(SDcs, LOW);
 display.clearDisplay();
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(0,0);
 display.print("SDcard Scanning");
 display.display();
 SDcounter = millis(); 
  while (!SD.begin(SDcs)) {

    if (millis() - SDcounter >= 4000) {
      SDcounter = millis();
     display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.print("SD failed!");
      display.setCursor(0,20);
      display.print("Re-insert SD Card");
      display.setCursor(0,35);
      display.print("SDcard Scanning");
      display.display();
      
    }

  }

  //LCDclear();
  //LCDHome();
  //lcd.print("SD Done.");
  //delay(2000);

  //digitalWrite(SDcs, HIGH);
  //digitalWrite(USBcs, LOW);
  //------SD card initialization DONE------------
  

}





void loop() {

 Timervalues();
 CreateFile();
 starttime=millis();
 myFile.println((String)"Session Duration(h:m):,"+SessionLengthHours+":"+SessionLengthMinutes);
 myFile.println((String)"Started time(ms):,"+ starttime);
 myFile.println("TIME(ms), TEMP, LUX");
 digitalWrite(RELAY,HIGH);
 while (millis()-starttime<SessionLengthInMiliseconds){
  
  
  if(digitalRead(BA)==LOW){
    digitalWrite(RELAY,LOW);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("CANCELED");
    display.setCursor(0,20);
    display.print("PRESS C TO");
    //display.setTextSize(1);
    display.setCursor(0,40);
    display.print("RE-START");
    display.display();
    myFile.println((String) millis()+", Session canceled");
    myFile.close();
    goto Start;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("PRESS A TO CANCEL");
  display.setCursor(0,9);
  display.print("REMAINING TIME IN"); 
  display.setCursor(0,18);
  display.print("MILLISECONDS:");
  display.setCursor(0,27);
  display.print((String)(SessionLengthInMiliseconds-millis()+starttime));
  luxtempRead();
  display.setCursor(0,38);
  display.print("TEMP(C): ");
  display.print(temp,2);
  display.setCursor(0,49);
  display.print("LUX: ");
  display.print(lux,2);
  display.display();
  myFile.println((String) millis()+","+temp+","+lux);

  if(temp>25.00){
    digitalWrite(RELAY,LOW);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("HIGH TEMP");
    display.setCursor(0,20);
    display.print("PRESS C TO");
    //display.setTextSize(1);
    display.setCursor(0,40);
    display.print("RE-START");
    display.display();
    myFile.println((String) millis()+", Session Canceled (HIGH TEMPERATURE)");
    myFile.close();
    goto Start;
  }
  
 }
    myFile.println((String) millis()+", Session Completed");
    myFile.close();
  digitalWrite(RELAY,LOW);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("COMPLETED");
  display.setCursor(0,20);
  display.print("PRESS C TO");
  //display.setTextSize(1);
  display.setCursor(0,40);
  display.print("RE-START");
  display.display();
Start:
 while(digitalRead(BC)==HIGH){
  
 }


  

}
