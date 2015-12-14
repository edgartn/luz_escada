int led;
int pinButton2 = 2;
int pinButton1 = 1;
int stateButton2;
int stateButton1;
int stateLED = LOW;
long time = 0;
long debounce = 200;
int previous = LOW;

void setup() {
  // OUTPUT
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  // INPUT
  pinMode(2, INPUT);
  pinMode(1, INPUT);

}

void loop() {
  stateButton2 = digitalRead(pinButton2);
  stateButton1 = digitalRead(pinButton1);
  
  if( (stateButton2 == HIGH || stateButton1 == HIGH) && previous == LOW && millis() - time > debounce) {
  
    if(stateLED == HIGH){
      
      if (stateButton1 == HIGH ) {
        desligaSeqLedBaixoCima();
      } else {
        desligaSeqLedCimaBaixo();      
      }
      stateLED = LOW; 
  
    } else {
      
       if (stateButton1 == HIGH ) {
          ligaSeqLedCimaBaixo();
       } else {
          ligaSeqLedBaixoCima();
       }
       stateLED = HIGH; 
  
    }
  
    time = millis();    

  }
  previous == stateButton2;
}

void ligaSeqLedCimaBaixo() {

  led = 6;

  while (led <= 13) {
    digitalWrite(led, HIGH);
    delay(100);

    led++;
  }

}

void ligaSeqLedBaixoCima() {

  led = 13;

  while (led >= 6) {
    digitalWrite(led, HIGH);
    delay(100);

    led--;
  }

}

void desligaSeqLedCimaBaixo() {

  led = 6;

  while (led <= 13) {
    digitalWrite(led, LOW);
    delay(100);

    led++;
  }
}

void desligaSeqLedBaixoCima() {

  led = 13;

  while (led >= 6) {
    digitalWrite(led, LOW);
    delay(100);

    led--;
  }  

}
