#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"

#define BLYNK_TEMPLATE_ID "TMPL6fPiwPgvq"
#define BLYNK_TEMPLATE_NAME "Button"
#define BLYNK_AUTH_TOKEN "7p-XwO71xSJ-rHxJpjabJJvuow8LkUUh"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "7p-XwO71xSJ-rHxJpjabJJvuow8LkUUh";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "...";
char pass[] = "laudaitinhai";

#define led D2
#define fan D1
#define buttonLED D3
#define buttonFAN D4
boolean bt_stateLED=LOW;
boolean bt_stateFAN=LOW;
void setup()
{
  Serial.begin(9600);
  delay(100);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led,LOW);
  pinMode(fan, OUTPUT);
  digitalWrite(fan,LOW);
  pinMode(buttonLED,INPUT_PULLUP);
  pinMode(buttonFAN,INPUT_PULLUP);
  Blynk.begin(auth, ssid, pass);  
}
// 00: LED off,FAN off | 01: LED off, FAN on | 10:LED on, FAN off | 11 LED on, FAN on
void loop()
{
  Blynk.run();
  if(digitalRead(D5)==HIGH)
  {
    if(digitalRead(D6)==LOW)
    {
      digitalWrite(led,LOW);
      Blynk.virtualWrite(V1,digitalRead(led));
    }
    else
    {
      digitalWrite(led,HIGH);
      Blynk.virtualWrite(V1,digitalRead(led));
    }
    if(digitalRead(D7)==LOW)
    {
      digitalWrite(fan,LOW);
      Blynk.virtualWrite(V2,digitalRead(fan));
    }
    else 
    {
      digitalWrite(fan,HIGH);
      Blynk.virtualWrite(V2,digitalRead(fan));
    }
  }
  

  check_buttonLED();
  check_buttonFAN();
}
BLYNK_WRITE(V1)
{
  int p = param.asInt();
  digitalWrite(led, p);
}

BLYNK_WRITE(V2)
{
  int q = param.asInt();
  digitalWrite(fan, q);
}

void check_buttonLED()
{
  if(digitalRead(buttonLED)==LOW)
  {
    if(bt_stateLED==HIGH)
    {
      digitalWrite(led,!digitalRead(led));
      Blynk.virtualWrite(V1,digitalRead(led));
      bt_stateLED=LOW;
      delay(10);
    }
  }
  else
  {
    bt_stateLED=HIGH;
  }
}

void check_buttonFAN()
{
  if(digitalRead(buttonFAN)==LOW)
  {
    if(bt_stateFAN==HIGH)
    {
      digitalWrite(fan,!digitalRead(fan));
      Blynk.virtualWrite(V2,digitalRead(fan));
      bt_stateFAN=LOW;
      delay(10);
    }
  }
  else
  {
    bt_stateFAN=HIGH;
  }
}