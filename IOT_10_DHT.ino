#include <DHT.h>

#define DHTPIN 2     // Pin where the DHT11/22 sensor is connected
#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

float maxTemperature = -1000; // Initial value for max temperature
float minTemperature = 1000; // Initial value for min temperature

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // Delay between sensor readings
  
  float temperatureCelsius = dht.readTemperature(); // Read temperature as Celsius
  float temperatureFahrenheit = (temperatureCelsius * 9 / 5) + 32; // Convert Celsius to Fahrenheit
  float humidity = dht.readHumidity(); // Read humidity
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(temperatureCelsius) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Update max and min temperatures
  if (temperatureCelsius > maxTemperature) {
    maxTemperature = temperatureCelsius;
  }
  if (temperatureCelsius < minTemperature) {
    minTemperature = temperatureCelsius;
  }
  
  // Print temperature in Celsius and Fahrenheit, humidity, and max/min temperatures
  Serial.print("Temperature: ");
  Serial.print(temperatureCelsius);
  Serial.print("°C / ");
  Serial.print(temperatureFahrenheit);
  Serial.print("°F\tHumidity: ");
  Serial.print(humidity);
  Serial.print("%\tMax: ");
  Serial.print(maxTemperature);
  Serial.print("°C / ");
  Serial.print((maxTemperature * 9 / 5) + 32);
  Serial.print("°F\tMin: ");
  Serial.print(minTemperature);
  Serial.print("°C / ");
  Serial.print((minTemperature * 9 / 5) + 32);
  Serial.println("°F");
}
