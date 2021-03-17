// Please use old bootloader
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



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

void setup() {
  
Serial.begin(9600);
  
pinMode(BA, INPUT_PULLUP); // button A
pinMode(BB, INPUT_PULLUP); // button B
pinMode(BC, INPUT_PULLUP); // button C
pinMode(RELAY, OUTPUT);
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
  

}





void loop() {

 Timervalues();
 starttime=millis();
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
    goto Start;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("PRESS A TO CANCEL");
  display.setCursor(0,20);
  display.print("REMAINING TIME IN"); 
  display.setCursor(0,30);
  display.print("MILLISECONDS:");
  display.setCursor(0,45);
  display.print((String)(SessionLengthInMiliseconds-millis()+starttime));
  display.display();
  
  
 }
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
