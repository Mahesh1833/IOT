// Define variables to hold incoming serial data and LED control pins
char receivedChar = '\0'; // for incoming serial data

const int yellowPin = 8;
const int redPin = 9;
const int greenPin = 7;


void setup() {
  // Initialize serial communication with baud rate 9600
  Serial.begin(9600);
  
  // Set LED control pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop() {
  // Check if there's data available on the serial port
  if (Serial.available() > 0) {
    // Read the incoming character
    receivedChar = Serial.read();
    
    // Print the received character
    Serial.print("Received character: ");
    Serial.println(receivedChar);
    
    // Perform actions based on the received character
    if (receivedChar == 'r') { // If 'r' is received, turn on red LED
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
    } else if (receivedChar == 'g') { // If 'g' is received, turn on green LED
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(yellowPin, LOW);
    } else if (receivedChar == 'y') { // If 'y' is received, turn on yellow LED
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
    } else if (receivedChar == 'B') { // If 'B' is received, make the green LED blink
      blinkGreen();
    } else {
      // If an unrecognized character is received, do nothing or handle as needed
    }
  }
}

// Function to make the green LED blink
void blinkGreen() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  
  for (int i = 0; i < 5; i++) {
    digitalWrite(greenPin, HIGH);
    delay(500);
    digitalWrite(greenPin, LOW);
    delay(500);
  }
}