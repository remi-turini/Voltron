#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
#include <NewPing.h>
#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <SPI.h>
#include <ArduinoJson.h>
#include "SoftwareSerial.h"

#ifndef HAVE_HWSERIAL1
  SoftwareSerial Serial1(RX1, TX1); // Declaration de l'esp8266
#endif

const char ssid[] = "My iphone"; //SSID et PSWD wifi
const char pass[] = "denisssss";
int status = WL_IDLE_STATUS;
IPAddress server(172,20,10,2); //IP de l'api

WiFiEspClient client; // initialisation de la librairie

#define POWER_PIN  7
#define SIGNAL_PIN A5

int humidityValue = 0;
int newHumidityValue = 0;     

void setup() {
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  
  Serial.begin(115200);
  Serial1.begin(115200);
  WiFi.init(&Serial1);
  
  Serial.println("Tentative de connexion..."); //Connexion de l'esp au wifi
  Serial.print("SSID: ");
  Serial.println(ssid);
  status = WiFi.begin(ssid, pass);

  if(status == 1)
  {
    Serial.println("Connexion reussie");
  }
  delay(500);
}

void readHumidity() {
  
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  newHumidityValue = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("Capteur d'umidité: ");
  Serial.println(newHumidityValue);

  if(newHumidityValue != humidityValue){
    api("humidity", newHumidityValue);
   }

  delay(1000);
  humidityValue = newHumidityValue;
}

void loop() {
  readHumidity();
  delay(2000);
}

void api(String sensorType,int value)
{
    // if you get a connection, report back via serial:
    Serial.println("Connecté à l'api");
    if (client.connect(server, 3001))
    {
      Serial.println("Envoi de la requete ");
      client.println("POST /sensors?type="+String(sensorType)+"&value="+String(value)+" HTTP/1.1");
      
      if (client.println() != 0) {
        Serial.println("Erreur de la requete l'api");
      }
      else
      {
        Serial.println("Succés de la requete api");
      }

      if(!client.connected())
      {
        // if the server's disconnected, stop the client:
        client.stop();
      }
    }
    else
    {
      Serial.println("connection failed");
    }
}
