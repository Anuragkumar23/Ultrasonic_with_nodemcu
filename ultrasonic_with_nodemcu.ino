#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


// Set these to run example.
#define FIREBASE_HOST "anurag-9e040-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "dPKQbONcQnxglHjxv6cr5Di4W58GLyqlMv4b2Pez"
#define WIFI_SSID "Shivam"
#define WIFI_PASSWORD "12345678"

long duration;
long distance;
void setup() {
Serial.begin(9600);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);


}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Serial.begin(9600);
  pinMode(D7,INPUT);
  pinMode(D8,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
     
}

void loop() 
{
  
  digitalWrite(D8,LOW);
  delayMicroseconds(2);
  digitalWrite(D8,HIGH);
  delayMicroseconds(10);
  digitalWrite(D8,LOW);

  duration = pulseIn(D7,HIGH);

  distance = duration/58.2;

  Serial.println(distance);
  Firebase.set("ultrasonic distance  : ",distance);

    
  }
