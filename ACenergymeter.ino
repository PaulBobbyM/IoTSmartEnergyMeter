#define BLYNK_TEMPLATE_ID "TMPL3HwUCtOSA"
#define BLYNK_TEMPLATE_NAME "New Template"
#define BLYNK_AUTH_TOKEN "fDamVHGLbUXJKk_22CEKXfhFDx-s54nc"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <PZEM004Tv30.h>

#define RX_PIN 16
#define TX_PIN 17

HardwareSerial pzemSerial(2);
PZEM004Tv30 pzem(pzemSerial,RX_PIN,TX_PIN);

// Wifi credentials
char ssid[] = "iPhone";
char pass[] = "nopassword";

BlynkTimer timer;

void myTimerEvent()
{

  Blynk.virtualWrite(V5, millis() / 1000);
}

void SensorReadings(){

  Serial.print("Custom Address:");
  Serial.println(pzem.readAddress(), HEX);

  // Read the data from the sensor
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();

    // Check if the data is valid
    if(isnan(voltage)){
        Serial.println("Error reading voltage");
    }if (isnan(current)) {
        Serial.println("Error reading current");
    }if (isnan(power)) {
        Serial.println("Error reading power");
    }if (isnan(energy)) {
        Serial.println("Error reading energy");
    }if (isnan(frequency)) {
        Serial.println("Error reading frequency");
    }if (isnan(pf)) {
        Serial.println("Error reading power factor");
    } else {

        Blynk.virtualWrite(V0,voltage);
        Blynk.virtualWrite(V1,current);
        Blynk.virtualWrite(V2,power);
        Blynk.virtualWrite(V3,energy);
        Blynk.virtualWrite(V4,frequency);
        Blynk.virtualWrite(V6,pf);

        // Print the values to the Serial console
        Serial.print("Voltage: ");      Serial.print(voltage);      Serial.println("V");
        Serial.print("Current: ");      Serial.print(current);      Serial.println("A");
        Serial.print("Power: ");        Serial.print(power);        Serial.println("W");
        Serial.print("Energy: ");       Serial.print(energy,3);     Serial.println("kWh");
        Serial.print("Frequency: ");    Serial.print(frequency, 1); Serial.println("Hz");
        Serial.print("PF: ");           Serial.println(pf);

    }


}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
  pzemSerial.begin(9600,SERIAL_8N1,RX_PIN,TX_PIN);
}

void loop()
{
  SensorReadings();
  Blynk.run();
  timer.run();
}
