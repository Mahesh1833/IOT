int out;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available()>0)
  {
    int num=Serial.readString().toInt();
    Serial.print("I received: ");
    Serial.println(num);
    out=num*num;
    Serial.print("Sq of no : ");
    Serial.println(out);
  }
}