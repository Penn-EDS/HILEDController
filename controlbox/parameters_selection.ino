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


void CreateFile() {
  //put this next line *Right Before* any file open line:c
 digitalWrite(SDcs,LOW);
 
  // see if the card is present and can be initialized:
  if (!SD.begin(SDcs)) {
    
  } else {
    Serial.println("Able to select card");
  }

  // Name filename in format F###_MMDDYYNN, where MM is month, DD is day, YY is year, and NN is an incrementing number for the number of files initialized each day
  //strcpy(filename, "___.CSV");  // placeholder filename
  getFilename(filename);//getfilename is a function that generates the filename using the device number, date, and increment
  Serial.println("Past getting file name");
  Serial.println(filename);
  digitalWrite(SDcs,LOW);
  myFile = SD.open(filename, FILE_WRITE);//this creates a file with that name and assigns opening it to a variable (logfile)
  if (!myFile) {
    Serial.println("Cannot open File");
    while(1);
  }

}


void getFilename(char *filename) {
  Serial.println("Generating file name");
  //filename[3] = (device / 100) % 10 + '0';
  //filename[3] = (device / 10) % 10 + '0';
  filename[0] = 'T';
  filename[1] = 'E';
  filename[2] = 'M';
  filename[3] = 'P';
  //filename[4] = 'E';
  filename[4] = 'L';
  filename[5] = 'U';
  filename[6] = 'X';
  //filename[7] = 
  filename[8] = '.';
  filename[9] = 'C';
  filename[10] = 'S';
  filename[11] = 'V';
  for (uint8_t i = 0; i < 10; i++) {
    filename[7] = '0' + i % 10;
    // create if does not exist, do not open existing, write, sync after write
    if (! SD.exists(filename)) {
      break;
    }
  }
 }
  
