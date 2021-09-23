
#define LEDpin 4
char input;

void setup() 
{
  
Serial.begin(9600);
Serial.println("HOME AUTOMATION SYSTEM");
pinMode(LEDpin,OUTPUT);
digitalWrite(LEDpin,LOW);

}

void loop() 
{
   if(Serial.available() > 0)
   {
      input = Serial.read();
      if(input == '1')
       {
          digitalWrite(LEDpin, HIGH);
       }

      else if(input == '0')
       {
         digitalWrite(LEDpin, LOW); 
       }
   }
   }
