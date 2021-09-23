#define LEDpin 4
#define REDpin 5
#define Buzzer 3
#define SensorPin A0
int SenseVal = 0;
int ThresholdVal = 130;
void setup()
{
Serial.begin(9600);
Serial.println("SMOKE ALERT SYSTEM");
pinMode(LEDpin, OUTPUT);
pinMode(Buzzer, OUTPUT);
pinMode(SensorPin, INPUT);
}
void loop()
{
SenseVal = analogRead(SensorPin);
  Serial.println(SenseVal);
  delay(1000); 
  if(SenseVal > ThresholdVal)
   {  digitalWrite(REDpin, HIGH); 
      digitalWrite(Buzzer, HIGH); 
       Serial.println(SenseVal);
   }
else
   {
     Serial.println(SenseVal);
   digitalWrite(REDpin, LOW); 
    digitalWrite(Buzzer, LOW); }}
