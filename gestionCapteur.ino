//code mise en application 
/*
Ce code nous permet  de
gérer les données des capteurs
pour activer les moteurs 
*/
#define capteur1 A0
#define capteur2 A5

void setup() {
  pinMode(capteur1,INPUT);
  pinMode(capteur2,INPUT);
  Serial.begin(9600);

}

void loop() {

    //Si capteur 1 == blanc et capteur 2== blanc : avancer 
    //Si capteur 1 > 275 et capteur 2 > 275 :avancer 

    if((analogRead (capteur1) >275 )&& (analogRead (capteur2) >275 ))
    {
      Serial.println("avancer");
      
      
    }
    //Si capteur 1 == noir et capteur 2== noir:s'arrêter
    //Si capteur 1 < 275 et capteur 2 < 275:s'arrêter
        if((analogRead (capteur1) < 275) && (analogRead (capteur2) < 275 ))
    {
      Serial.println("arret");
      
      
    }
    //Si capteur1 == Noir et capteur 2 ==blanc :Moteurdroite
    //Si capteur1 < 275 et capteur 2 > 275 :Moteurdroite

        if((analogRead (capteur1) < 275) && (analogRead (capteur2) >275 ))
    {
      Serial.println("MoteurDroit");
      
      
    }
    //Si capteur1 == Blanc et capteur 2 ==noir  :Moteurgauche
    //Si capteur1 > 275 et capteur 2 < 275  :Moteurgauche

        if((analogRead (capteur1) >275) && (analogRead (capteur2) <275 ))
    {
      Serial.println("MoteurGauche");
    
      
    }

    delay(10);

}