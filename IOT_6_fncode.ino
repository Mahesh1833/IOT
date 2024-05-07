int counter = 50;
void setup()
{
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}
void loop() {
if(counter == 300)
{
  counter=50;
}
if(counter < 300)
{
  Serial.println(counter);
}
counter = counter + 1;
delay(100);
if(counter > 0 && counter < 100 )
{
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}
if(counter > 101 && counter < 200 )
{
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
}
if(counter >= 200)
{
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}
}