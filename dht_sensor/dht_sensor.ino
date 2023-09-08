#define BLYNK_TEMPLATE_ID "TMPL3SikH4gO2"
#define BLYNK_TEMPLATE_NAME "DHT sensor"
#define BLYNK_AUTH_TOKEN "ghi2msLHoXfb841sUl4fqtvdabrtPAqL"
#include<DHT.h>
#include<BlynkSimpleEsp8266.h> 
#define DHTPIN 4
#define DHTTYPE DHT11
char auth[]="ghi2msLHoXfb841sUl4fqtvdabrtPAqL";
char ssid[]= "Redmi";
char pass[]= "rish1234";
DHT dht(DHTPIN,DHTTYPE);

void setup() {
    Serial.begin(9600);
    Serial.println("DHT Test Successful!");
    Blynk.begin(auth, ssid, pass);
    Serial.println("Blynk completed successfully");
    dht.begin();
  
  }
 
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println("Something not working");
    return;
  }
  Serial.println("Humidity: ");
  Serial.print(h);
  Serial.println("Temperature");
  Serial.print(t);
  Serial.print(t);
  Serial.print("degree celcius");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(2000);
}
