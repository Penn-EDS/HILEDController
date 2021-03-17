void checkbuttonACstate() {
  
  if ((digitalRead(BA) == LOW) && (digitalRead(BB) == HIGH) && (digitalRead(BC) == LOW)) {
    delay(150);
    ButtonACstate = !ButtonACstate; //state start in 0
    if (ButtonACstate == LOW) {
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.print("Session Length");
        display.setTextColor(BLACK,WHITE);
        display.setCursor(1, 9);
        display.print((String)"Hrs:"+SessionLengthHours);
        display.setTextColor(WHITE);
        display.setCursor(50, 9);
        display.print((String)"Min:"+SessionLengthMinutes);
        display.setCursor(0, 20);
        display.print("PRESS:");
        display.setCursor(5, 29);
        display.print("A(+) B(-)");
        display.setCursor(5, 38);
        display.print("C+A for Hrs or Min");
        display.setCursor(5, 47);
        display.print("C+B for OK");
        display.display();
    }

    if (ButtonACstate == HIGH) {
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.print("Session Length");
        display.setCursor(1, 9);
        display.print((String)"Hrs:"+SessionLengthHours);
        display.setTextColor(BLACK,WHITE);
        display.setCursor(50, 9);
        display.print((String)"Min:"+SessionLengthMinutes);
        display.setTextColor(WHITE);
        display.setCursor(0, 20);
        display.print("PRESS:");
        display.setCursor(5, 29);
        display.print("A(+) B(-)");
        display.setCursor(5, 38);
        display.print("C+A for Hrs or Min");
        display.setCursor(5, 47);
        display.print("C+B for OK");
        display.display();
    }
  }
}


void Timervalues(){
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Session Length");
  display.setTextColor(BLACK,WHITE);
  display.setCursor(1, 9);
  display.print((String)"Hrs:"+SessionLengthHours);
  display.setTextColor(WHITE);
  display.setCursor(50, 9);
  display.print((String)"Min:"+SessionLengthMinutes);
  display.setCursor(0, 20);
  display.print("PRESS:");
  display.setCursor(5, 29);
  display.print("A(+) B(-)");
  display.setCursor(5, 38);
  display.print("C+A for Hrs or Min");
  display.setCursor(5, 47);
  display.print("C+B for OK");
  display.display();


  //while ((digitalRead(BB) == HIGH) && (digitalRead(BC) == HIGH)) {   // select Active session Length time loop
  while(1){

    if ( (digitalRead(BA) == HIGH) && (digitalRead(BB) == LOW) && (digitalRead(BC) == LOW)) {
      goto Here;
    }

    checkbuttonACstate();
    while (ButtonACstate == LOW) {  // selecting session length hours
      delay(90);
      
      
      checkbuttonACstate();
      if ( (digitalRead(BA) == LOW) && (digitalRead(BB) == HIGH) && (digitalRead(BC) == HIGH)) {
        SessionLengthHours = SessionLengthHours + 1;
        if ( SessionLengthHours >= 24) {
          SessionLengthHours = 24; 
        }
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.print("Session Length");
        display.setTextColor(BLACK,WHITE);
        display.setCursor(1, 9);
        display.print((String)"Hrs:"+SessionLengthHours);
        display.setTextColor(WHITE);
        display.setCursor(50, 9);
        display.print((String)"Min:"+SessionLengthMinutes);
        display.setCursor(0, 20);
        display.print("PRESS:");
        display.setCursor(5, 29);
        display.print("A(+) B(-)");
        display.setCursor(5, 38);
        display.print("C+A for Hrs or Min");
        display.setCursor(5, 47);
        display.print("C+B for OK");
        display.display();
        // putt a maximum value here hours
        
      }
      checkbuttonACstate();
      if ( (digitalRead(BA) == HIGH) && (digitalRead(BB) == LOW) && (digitalRead(BC) == HIGH)) {
        SessionLengthHours = SessionLengthHours - 1;
        if (SessionLengthHours == 4294967295) {
          SessionLengthHours = 0;
        }
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.print("Session Length");
        display.setTextColor(BLACK,WHITE);
        display.setCursor(1, 9);
        display.print((String)"Hrs:"+SessionLengthHours);
        display.setTextColor(WHITE);
        display.setCursor(50, 9);
        display.print((String)"Min:"+SessionLengthMinutes);
        display.setCursor(0, 20);
        display.print("PRESS:");
        display.setCursor(5, 29);
        display.print("A(+) B(-)");
        display.setCursor(5, 38);
        display.print("C+A for Hrs or Min");
        display.setCursor(5, 47);
        display.print("C+B for OK");
        display.display();
        
      }
      checkbuttonACstate();


      if ( (digitalRead(BA) == HIGH) && (digitalRead(BB) == LOW) && (digitalRead(BC) == LOW)) {
        goto Here;
      }
    }
    checkbuttonACstate();
    while (ButtonACstate == HIGH) { // selecting session Length Minutes
      delay(90);
      
      
      checkbuttonACstate();
      if ( (digitalRead(BA) == LOW) && (digitalRead(BB) == HIGH) && (digitalRead(BC) == HIGH)) {
        SessionLengthMinutes = SessionLengthMinutes + 1;
        if ( SessionLengthMinutes >= 60) {
          SessionLengthMinutes = 60;
        }
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.print("Session Length");
        display.setCursor(1, 9);
        display.print((String)"Hrs:"+SessionLengthHours);
        display.setTextColor(BLACK,WHITE);
        display.setCursor(50, 9);
        display.print((String)"Min:"+SessionLengthMinutes);
        display.setTextColor(WHITE);
        display.setCursor(0, 20);
        display.print("PRESS:");
        display.setCursor(5, 29);
        display.print("A(+) B(-)");
        display.setCursor(5, 38);
        display.print("C+A for Hrs or Min");
        display.setCursor(5, 47);
        display.print("C+B for OK");
        display.display();

      }
      
      checkbuttonACstate();
      if ( (digitalRead(BA) == HIGH) && (digitalRead(BB) == LOW) && (digitalRead(BC) == HIGH)) {

        SessionLengthMinutes = SessionLengthMinutes - 1;
        if ( SessionLengthMinutes == 4294967295) {
          SessionLengthMinutes = 0;
        }
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.print("Session Length");
        display.setCursor(1, 9);
        display.print((String)"Hrs:"+SessionLengthHours);
        display.setTextColor(BLACK,WHITE);
        display.setCursor(50, 9);
        display.print((String)"Min:"+SessionLengthMinutes);
        display.setTextColor(WHITE);
        display.setCursor(0, 20);
        display.print("PRESS:");
        display.setCursor(5, 29);
        display.print("A(+) B(-)");
        display.setCursor(5, 38);
        display.print("C+A for Hrs or Min");
        display.setCursor(5, 47);
        display.print("C+B for OK");
        display.display();
        
        
      }
      checkbuttonACstate();

      
      if ( (digitalRead(BA) == HIGH) && (digitalRead(BB) == LOW) && (digitalRead(BC) == LOW)) {
        goto Here;
      }
    }
  }
  
Here:
SessionLengthInMiliseconds = (SessionLengthMinutes*60000) + (SessionLengthHours*3600000);
  delay(100);
}
