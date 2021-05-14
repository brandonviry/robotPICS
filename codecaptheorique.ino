//code pour tester capteur
#define capteur1 A0
#define capteur2 A5

void setup() {

  pinMode(capteur1,INPUT);
  pinMode(capteur2,INPUT);
  Serial.begin(9600);

}

void loop() {

  /*Si capteur > 275
    surface est blanc
si capteur < 275
    surface est noir */
    
    if(analogRead (capteur2) >275)
    {
      Serial.println("surface est blanc");
      
    }
    if (analogRead(capteur2) <275)
    {
      Serial.println("surface est noir ");
    }
  Serial.println(analogRead(capteur2));

}
