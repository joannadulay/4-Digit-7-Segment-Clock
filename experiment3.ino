int btn1pin = 13;
int btn2pin = 0;

int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, p = 8;
int d4 = 9, d3 = 10, d2 = 11, d1 = 12;

int hours = 0;
int minutes = 0;
unsigned long previousMillis = 0;
const long interval = 60000; 
bool clockStarted = false;

void setup() {
  pinMode(btn1pin, INPUT_PULLUP);
  pinMode(btn2pin, INPUT_PULLUP);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
}

void loop() {
  if (!clockStarted) {
    if (digitalRead(btn1pin) == LOW && digitalRead(btn2pin) == LOW) {
      delay(200);
      if (digitalRead(btn1pin) == LOW && digitalRead(btn2pin) == LOW) {
        clockStarted = true;
        previousMillis = millis(); 
      }
    }
  } else {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      minutes++;
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        if (hours >= 24) {
          hours = 0;
        }
      }
    }

    if (digitalRead(btn1pin) == LOW) {
      delay(200);
      if (digitalRead(btn1pin) == LOW) {
        hours++;
        if (hours >= 24) hours = 0;
      }
    }

    if (digitalRead(btn2pin) == LOW) {
      delay(200);
      if (digitalRead(btn2pin) == LOW) {
        minutes++;
        if (minutes >= 60) minutes = 0;
      }
    }

    int d1 = hours / 10;
    int d2 = hours % 10;
    int d3 = minutes / 10;
    int d4 = minutes % 10;

    for (int m = 0; m < 80; m++) {
      clearLEDs();
      pickDigit(1);
      pickNumber(d1);
      delayMicroseconds(200);

      clearLEDs();
      pickDigit(2);
      pickNumber(d2);
      delayMicroseconds(200);

      // Light up the decimal point
      digitalWrite(p, HIGH);
      delayMicroseconds(100);
      digitalWrite(p, LOW);

      clearLEDs();
      pickDigit(3);
      pickNumber(d3);
      delayMicroseconds(200);

      clearLEDs();
      pickDigit(4);
      pickNumber(d4);
      delayMicroseconds(200);
    }
  }
}

void pickDigit(int x) {
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
  switch (x) {
    case 1: digitalWrite(d1, LOW); break;
    case 2: digitalWrite(d2, LOW); break;
    case 3: digitalWrite(d3, LOW); break;
    default: digitalWrite(d4, LOW); break;
  }
}

void pickNumber(int x) {
  switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    default: zero(); break;
  }
}

void dispDec(int x) {
  digitalWrite(p, HIGH);
}

void clearLEDs() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(p, LOW);
}

void zero() { digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, LOW); }
void one() { digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); }
void two() { digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, HIGH); }
void three() { digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH); }
void four() { digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH); }
void five() { digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH); }
void six() { digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); }
void seven() { digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); }
void eight() { digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); }
void nine() { digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH); }
