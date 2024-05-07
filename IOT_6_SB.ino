
const int greenLedPin = 10;
const int yellowLedPin = 8;
const int redLedPin = 9;


int counter = 0;

void setup() {
  
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  
  
  Serial.begin(9600);
}

void loop() {
  
  counter++;
  
  
  if (counter < 100) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    Serial.print("Counter: ");
    Serial.print(counter);
    Serial.println(", Green LED");
  } else if (counter >= 100 && counter <= 200) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    Serial.print("Counter: ");
    Serial.print(counter);
    Serial.println(", Yellow LED");
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    Serial.print("Counter: ");
    Serial.print(counter);
    Serial.println(", Red LED");
  }
  
  
  if (counter > 300) {
    counter = 0;
  }
  
  
  delay(50);
}