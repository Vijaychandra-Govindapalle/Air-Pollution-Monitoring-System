#define BLYNK_TEMPLATE_ID "TMPL31OMqpyja"
#define BLYNK_TEMPLATE_NAME "Air Pollution Monitoring"
#define BLYNK_AUTH_TOKEN "QjaiNkTNKi4haJLZeUowVGQvczBbvtrD"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// WiFi Credentials
char ssid[] = "ABC";
char pass[] = "123456789";
char auth[] = BLYNK_AUTH_TOKEN;

// Sensor Pins
#define MQ2_PIN 34  // Air Quality
#define MQ135_PIN 35  // Air Quality
#define MQ7_PIN 32  // CO Gas
#define DHT_PIN 15   // Temperature & Humidity
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Air Quality Mon.");
    delay(2000);
}

void loop() {
    Blynk.run();
    readSensors();
    delay(2000); // Update every 5 seconds
}

void readSensors() {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    int mq2_val = analogRead(MQ2_PIN);
    int mq135_val = analogRead(MQ135_PIN);
    int mq7_val = analogRead(MQ7_PIN);

    String airQualityStatus = getAirQualityStatus(mq2_val, mq135_val, mq7_val);
    
    Serial.println("\nSensor Readings:");
    Serial.print("Temp: "); Serial.print(temp); Serial.println(" C");
    Serial.print("Humidity: "); Serial.print(hum); Serial.println(" %");
    Serial.print("MQ2: "); Serial.println(mq2_val);
    Serial.print("MQ135: "); Serial.println(mq135_val);
    Serial.print("MQ7: "); Serial.println(mq7_val);
    Serial.print("Air Quality: "); Serial.println(airQualityStatus);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:"); lcd.print(temp); lcd.print("C H:"); lcd.print(hum); lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("AQ: "); lcd.print(airQualityStatus);
    
    // Send data to Blynk
    Blynk.virtualWrite(V0, temp);
    Blynk.virtualWrite(V1, hum);
    Blynk.virtualWrite(V2, mq2_val);
    Blynk.virtualWrite(V3, mq135_val);
    Blynk.virtualWrite(V4, mq7_val);
    Blynk.virtualWrite(V5, airQualityStatus);
}

String getAirQualityStatus(int mq2, int mq135, int mq7) {
    int avg = (mq2 + mq135 + mq7) / 3;
    if (avg < 1800) return "Good";
    else if (avg < 2000) return "Moderate";
    else if (avg < 2300) return "Unhealthy";
    else return "Hazardous";
}