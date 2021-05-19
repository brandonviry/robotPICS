//defintion des ports d'entrer
#define capteur1 A0
#define capteur2 A5

//defintion des ports sortis
#define moteur1 13
#define moteur2 2

//etat moteur
unsigned int etat1 = 1;
unsigned int etat2 = 0;

//etat robot ON / OFF 
unsigned int stop = 0;

void setup()
{

    //activer  entrer
    pinMode(capteur1, INPUT);
    pinMode(capteur2, INPUT);
    //activer sortis
    pinMode(moteur1, OUTPUT);
    pinMode(moteur2, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    /*
if (capteur1 == noir && capteur1 == noir ):
        inversion(etat1)
        inversion(etat2)
deplacement 

Si capteur 1 < 275 et capteur 2 < 275:
       inversion(etat1)
        inversion(etat2) 

deplacement 
*/

    //verifie si les capteurs dectecter une ligne noir
    if ((analogRead(capteur1) > 275) && (analogRead(capteur2) > 275))
    {
        
        Serial.println("< Detection >");
        etat1 = inversion(etat1);
        etat2 = inversion(etat2);
        
    }
    // ACTIVE on ou off
    if (Serial.available() > 0)
    {
        stop = 1;
    }

    //stop ou deplacement 
    switch (stop)
    {
    //deplacement robot
    case 0:
        
        digitalWrite(moteur1, etat1);
        digitalWrite(moteur2, etat2);
        while((analogRead(capteur1) > 275) && (analogRead(capteur2) > 275));
        break;
    //arret robot 
    case 1:
        digitalWrite(moteur1, 0);
        digitalWrite(moteur2, 0);
        break;
    }
    // indicateur de l'érat du robot 
    indicateur(etat1, etat2);
}

int inversion(unsigned int etat)
{
    /*
    Cette foncton permet de inverser une variable
    qui vaut 1 ou 0 leur inverse est 0 ou 1

    */
    switch (etat)
    {
    case 0:
        return 1;
        break;
    case 1:
        return 0;
        break;
    }
}

void indicateur(unsigned int etatMoteur1,unsigned int etatMoteur2)
{
    /*
    cette fonction permette de suivre 
    l'état de notre robot .
    */

    if ((etatMoteur1 == 0) && (etatMoteur2 == 0))
    {
        Serial.println("Robot OFF");
    }
    if ((etatMoteur1 == 1) && (etatMoteur2 == 0))
    {
        Serial.println("Robot ON > AVANCE");
    }
    if ((etatMoteur1 == 0) && (etatMoteur2 == 1))
    {
        Serial.println("Robot ON > RECULE ");
    }
}

//HIGH == 1
//LOW == 0
