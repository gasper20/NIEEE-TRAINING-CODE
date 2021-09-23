
int LEDpin = 4;
#define LDRval A0
int SenseVal = 0;
int ThresholdVal = 400;
void setup()
{

Serial.begin(9600);
Serial.println("AUTOMATIC LIGHT CONTROL SYSTEM");
pinMode(LEDpin, OUTPUT);
pinMode(LDRval, INPUT);

}

void loop()
{
  SenseVal = analogRead(LDRval);
  if(SenseVal < ThresholdVal)
   {
      digitalWrite(LEDpin, HIGH); 
       Serial.println(SenseVal);
   }
   else
   {
     digitalWrite(LEDpin,LOW);
      Serial.println(SenseVal); 
   }}
