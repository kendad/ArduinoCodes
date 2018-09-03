#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include<ESP8266WiFi.h>

#define ssid "kela"
#define password "kaushikkela"
#define FIREBASE_HOST "espuno-b072a.firebaseio.com"
#define FIREBASE_AUTH "eDmqUL5bZpS7C07AudS9j09QWm1gP8pKge5WEE50"

void setup()
{
 Serial.begin(9600);
 Serial.print("connecting");
 WiFi.begin(ssid,password);
 while(WiFi.status()!=WL_CONNECTED)
 {
  Serial.print(".");
  delay(500);
  }
  Serial.print(" ");
  Serial.print("connected");
  Serial.print(WiFi.localIP());
   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }
void loop()
{
  int ledStatus = Firebase.getInt("ledStatus");
  Serial.print(ledStatus);
  Serial.println("ledStatus");
  if (ledStatus == 1)
  {
    digitalWrite(13, HIGH);
    Serial.println("on");
  }
  else if(ledStatus==0)
  {
    digitalWrite(13, LOW);
    Serial.println("off");
  }

  }
