
#include <dht.h>
dht DHT;
#define DHT11_PIN 5
int FAN = 8;
int alert = 2;

void setup()
{
  Serial.begin(115200);
  pinMode(FAN,OUTPUT);
 Serial.println("Temperature (C)");
}
void loop()
{
    int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
   case DHTLIB_OK:  
    //Serial.print("OK,\t"); 
    break;  
    case DHTLIB_ERROR_CHECKSUM: 
    //Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }

  if(DHT.temperature > 31 )
   {
      digitalWrite(FAN,HIGH);
      digitalWrite(alert,HIGH);
       Serial.println(DHT.temperature, 1);

   }

   else
     {
       Serial.println(DHT.temperature, 1);
        digitalWrite(FAN,LOW);
         digitalWrite(alert,LOW);
     }
 delay(2000);   
}
