const int sensor = A1; // Assigning analog pin A1 to variable 'sensor'
float tempc;           // variable to store temperature in degree Celsius
float tempf;           // variable to store temperature in Fahrenheit
float vout;            // temporary variable to hold sensor reading
int time = 0;          // variable to keep track of time

void setup()
{
  pinMode(sensor, INPUT); // Configuring pin A1 as input
  Serial.begin(9600);
}

void loop()
{
  vout = analogRead(sensor);
  vout = (vout * 500) / 1023;
  tempc = vout;               // Storing value in Degree Celsius
  tempf = (vout * 1.8) + 32;  // Converting to Fahrenheit
  
  Serial.print(time);  // Print current time
  Serial.print(",");   // Print comma as delimiter
  Serial.println(tempc); // Send temperature in Celsius to Tinkercad
  
  time++;  // Increment time

  delay(1000); // Delay of 1 second for ease of viewing
}
