#define RED 8
#define YELLOW 9
#define GREEN 10

int buttonDelay = 0; // Delay when button is pressed

void setup() {
  Serial.begin(9600); 
  pinMode(RED, OUTPUT); 
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), buttonPressed, RISING); // Checks if the button is pressed continiously and when it detects a button press it runs a function called buttonPressed()
}

void loop() {
  digitalWrite(RED, HIGH); // Turns the red light on
  delay(3000);
  delay(buttonDelay);
  buttonDelay = 0; // Resets the button delay
  digitalWrite(RED, LOW); // Turns the red light off

  digitalWrite(YELLOW, HIGH); // Turns the yellow light on
  delay(2000);
  digitalWrite(YELLOW, LOW); // Turns the yellow light off

  digitalWrite(GREEN, HIGH); // Turns the green light on
  delay(3000);
  digitalWrite(GREEN, LOW); // Turns the green light off
}

void buttonPressed() {
  buttonDelay = 2000; // Adds two seconds delay
}
