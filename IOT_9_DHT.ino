#include <DHT.h>

#define DHTPIN 2     // Pin where the DHT11/22 sensor is connected
#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // Delay between sensor readings
  
  float temperature = dht.readTemperature(); // Read temperature as Celsius
  float humidity = dht.readHumidity(); // Read humidity
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Print temperature and humidity values to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C\tHumidity: ");
  Serial.print(humidity);
  Serial.println("%");
}
