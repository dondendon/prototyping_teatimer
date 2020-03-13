const int button_1_Pin = A2;
const int button_2_Pin = A3;
const int button_3_Pin = A4;
const int button_4_Pin = A5;
const int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divider
int LEDpin = 13;
int time_update = 0;
int button_1_State = 0;
int button_2_State = 0;
int button_3_State = 0;
int button_4_State = 0;
int button_1 = 0;
int button_2 = 0;
int button_3 = 0;
int button_4 = 0;

// Pin 2-8 is connected to the 7 segments of the display.

int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;
int digit1 = 9;
int digit2 = 10;
int digit3 = 11;
int digit4 = 12;

int start_num = 0;  // Number to countdown from
unsigned long time;

// the setup routine runs once when you press reset:
void setup() {  
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);            
  pinMode(segA, OUTPUT);     
  pinMode(segB, OUTPUT);     
  pinMode(segC, OUTPUT);     
  pinMode(segD, OUTPUT);     
  pinMode(segE, OUTPUT);     
  pinMode(segF, OUTPUT);     
  pinMode(segG, OUTPUT);   
  pinMode(digit1, OUTPUT);  
  pinMode(digit2, OUTPUT);  
  pinMode(digit3, OUTPUT);  
  pinMode(digit4, OUTPUT); 

}
//the reset function for countdown millis()
void(* resetFunc) (void) = 0;

void loop() {
  fsrReading = analogRead( fsrPin );
  button_1_State = digitalRead( button_1_Pin );
  button_2_State = digitalRead( button_2_Pin );
  button_3_State = digitalRead( button_3_Pin );
  button_4_State = digitalRead( button_4_Pin );
      if( button_1_State == HIGH ){
      button_1 = 10;
      }
      if( button_2_State == HIGH ){
      button_2 = 5;
      }    
      if( button_3_State == HIGH ){
      button_3 = 3;
      }
      if( button_4_State == HIGH ){
      button_4 = 1;
      } 
      time_update = button_1 + button_2 + button_3 + button_4;
      //if sense the pressure
      if(fsrReading > 0 ){
          digitalWrite(LEDpin, HIGH);
          start_num = time_update;
          time_update = 0;
          //countdown and display
                if((millis()/1000) < start_num){
                    displayNumber(start_num -(millis()/1000));
              }
                else {
                    // reached zero, flash the display
                    time=millis();
                    while(millis() < time+200) {
                        displayNumber(0);  // display 0 for 0.2 second
                    }
                    time=millis();    
                    while(millis() < time+200) {
                        lightNumber(10);  // Turn display off for 0.2 second
                    }
                }      
          }
      else{
            start_num = 0;
            time_update = 0;
            digitalWrite(LEDpin, LOW);
            resetFunc();
  }

}


void displayNumber(int toDisplay) {

  long beginTime = millis();

  for(int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch(digit) {
    case 1:
      digitalWrite(digit1, LOW);
      break;
    case 2:
      digitalWrite(digit2, LOW);
      break;
    case 3:
      digitalWrite(digit3, LOW);
      break;
    case 4:
      digitalWrite(digit4, LOW);
      break;
    }

    //Turn on the right segments for this digit
    lightNumber(toDisplay % 10);
    toDisplay /= 10;

    delayMicroseconds(100); 
    //Display digit for fraction of a second (1us to 5000us, 500 is pretty good)

    //Turn off all segments
    lightNumber(10); 
    //Turn off all digits
    digitalWrite(digit1, HIGH);
    digitalWrite(digit2, HIGH);
    digitalWrite(digit3, HIGH);
    digitalWrite(digit4, HIGH);
    
  }

  while( (millis() - beginTime) < 10);
  //Wait for 20ms to pass before we paint the display again
}

//Given a number, turns on those segments
//If number == 10, then turn off number
void lightNumber(int numberToDisplay) {

#define SEGMENT_ON  HIGH
#define SEGMENT_OFF LOW

  switch (numberToDisplay){

  case 0:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 1:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 2:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_OFF);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 3:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 4:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 5:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 6:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 7:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 8:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 9:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 10:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_OFF);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;
  }

}

  
