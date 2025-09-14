// Blink Timing Game

uint8_t count = 5;
uint8_t up = 1;
uint8_t speed = 50;
uint8_t button = 0;
uint8_t wins = 0;

void setup() {
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), press, RISING);

}

void loop() {
  
  if(count >= 14) {
    count = 12;
    up = 0;
  } 
  if(count <= 4) {
    count = 6;
    up = 1;
  } 
  
  for(int i = 5; i < 14 ; i++) {
    digitalWrite(i, LOW);
  }

  delay(3);
  digitalWrite(count, HIGH);
  delay(speed);

  if(button) {
    if(count == 9) {
      wins++;
      if((wins >= 1)&&(speed > 9)) {
        speed = 50 - (wins * 10);
      } else speed = 50;
      for(int j = 0;j < 3;j++) {
        for(int i = 5; i < 14 ; i++) {
          digitalWrite(i, LOW);
        }
        delay(300);
        for(int i = 5; i < 14 ; i++) {
          digitalWrite(i, HIGH);
        }
        delay(300);
      }
    } else {
      wins = 0;
      speed = 50;
      for(int j = 0;j < 4;j++) {
        digitalWrite(count, LOW);
        delay(300);
        digitalWrite(count, HIGH);
        delay(300);
      }
    }
    button = 0;
  }
  if(up) {
    count++;
  } else count--;
}

void press() {
  button = 1;
}
