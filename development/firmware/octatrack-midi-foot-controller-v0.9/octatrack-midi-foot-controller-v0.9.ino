
const int button1Pin = 2;
const int button2Pin = 3;
const int button3Pin = 4;
const int button4Pin = 5;
const int button5Pin = 6;

int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
int button5State = 0;

int button1Was = 0;
int button2Was = 0;
int button3Was = 0;
int button4Was = 0;
int button5Was = 0;
  
void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  //  Set MIDI baud rate:
  Serial.begin(31250);
}

void loop() {
    button1State = digitalRead(button1Pin);
    button2State = digitalRead(button2Pin);
    button3State = digitalRead(button3Pin);
    button4State = digitalRead(button4Pin);
    button5State = digitalRead(button5Pin);
    
  if (button1State == HIGH && button1Was == 0) {
    button1Was = 1;
    noteOn(0x90, 0x1E, 0x45);
  } 
  else {
    if (button1State == LOW && button1Was == 1) {
      button1Was = 0;
      noteOn(0x90, 0x1E, 0);
    }
  }
  
  if (button2State == HIGH && button2Was == 0) {
    button2Was = 1;
    noteOn(0x90, 0x2E, 0x45);
  } 
  else {
    if (button2State == LOW && button2Was == 1) {
      button2Was = 0;
      noteOn(0x90, 0x2E, 0);
    }
  }
  
  if (button3State == HIGH && button3Was == 0) {
    button3Was = 1;
    noteOn(0x90, 0x3E, 0x45);
  } 
  else {
    if (button3State == LOW && button3Was == 1) {
      button3Was = 0;
      noteOn(0x90, 0x3E, 0);
    }
  }
  
  if (button4State == HIGH && button4Was == 0) {
    button4Was = 1;
    noteOn(0x90, 0x4E, 0x45);
  } 
  else {
    if (button4State == LOW && button4Was == 1) {
      button4Was = 0;
      noteOn(0x90, 0x4E, 0);
    }
  }
  
  if (button5State == HIGH && button5Was == 0) {
    button5Was = 1;
    noteOn(0x90, 0x5E, 0x45);
  } 
  else {
    if (button5State == LOW && button5Was == 1) {
      button5Was = 0;
      noteOn(0x90, 0x5E, 0);
    }
  }
  
}

// 
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
