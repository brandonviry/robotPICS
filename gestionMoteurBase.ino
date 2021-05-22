void setup()
{
  //active les port sortis 13 et 2 
  pinMode(13, OUTPUT); // port moteurG
  pinMode(2, OUTPUT); // port moteurD

   Serial.begin(9600);
}
void loop()
{
moteurX2(); //activation de moteur droit et gauche
//moteurD(); //activation du moteur droit 
//moteurG(); //activation du moteur gauche 
  
  delay(10); 
}
//activation de moteur droit et gauche pour avancer 
void moteurX2 ()
{
    digitalWrite(13, HIGH);
    digitalWrite(2, HIGH);
    Serial.println("avancer");
}
//activation du moteur droit  pour tourner a gauche 
void moteurD()
{
    digitalWrite(13, LOW);
    digitalWrite(2, HIGH);
    Serial.println("droite");
}
//activation du moteur gauche  pour tourner a droite 
void moteurG()
{
digitalWrite(13, HIGH);
digitalWrite(2, LOW);
Serial.println("gauche");
}
    
