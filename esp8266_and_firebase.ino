//loading the library files
#include <FirebaseArduino.h>
#include<ESP8266Wifi.h>

//connection parameters
#define SSID_WIFI "kela"
#define SSID_PASSWRD "kaushikkela"
#define FIREBASE_HOST "espuno-b072a.firebaseio.com"
#define FIREBASE_AUTH "eDmqUL5bZpS7C07AudS9j09QWm1gP8pKge5WEE50"


#define ledPin = 13

void setup()
{
  //starting to make connection to board
  Serial.begin(115200);
  Wifi.begin(SSID_WIFI, SSID_PASSWRD);
  Serial.print("coneccting");
  while (Wifi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print(" ");
  Serial.println("connected");
  Serial.println(Wifi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //till here connection are being made

  pinMode(ledPin, OUTPUT);

}

void loop()
{
  int ledStatus = Firebase.getInt("ledStatus");
  Serial.println("ledStatus");
  if (ledStatus == 1)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }


}
