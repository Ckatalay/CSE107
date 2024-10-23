#define RED 8
#define YELLOW 9
#define GREEN 10
#define BUTTON 2

void setup() {
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BUTTON, INPUT);
}

int count;
unsigned long i;
void loop() {
  i = millis();
  while (millis() - i < 2000) {
    if (digitalRead(BUTTON) == HIGH) {
      count++;
      delay(200);
    }
  }

  switch (count) {
    case 3:
      digitalWrite(RED, HIGH);
      digitalWrite(YELLOW, HIGH);
      digitalWrite(GREEN, HIGH);
      delay(5000);
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, LOW);
      break;

    case 2:
      digitalWrite(RED, HIGH);
      digitalWrite(YELLOW, HIGH);
      delay(5000);
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      break;

    case 1:
      digitalWrite(RED, HIGH);
      delay(5000);
      digitalWrite(RED, LOW);
      break;

    default:
      Serial.println("Invalid number of inputs.");
      return 1;
  }
  count = 0;
}