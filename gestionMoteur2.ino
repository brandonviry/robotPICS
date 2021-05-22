//definiton port
#define capteur1 A0
#define capteur2 A5



void setup() {
  //activation des entrers
  pinMode(capteur1, INPUT);
  pinMode(capteur2, INPUT);
  //activation des sortis
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  //dectection noir au capteur 1 et  capteur 2 noir 
  if ((analogRead (capteur1) > 275 ) && (analogRead (capteur2) > 275 ))
  {
    Serial.println("s'arrêter ");
    aret();

  }
  //dectection blanc  au capteur 1 et  capteur 2  noir
  if ((analogRead (capteur1) < 275) && (analogRead (capteur2) < 275 ))
  {

    Serial.println("avancer ");
    moteurX2();

  }


  delay(10);

}
//activation moteur1 et moteur2 dans le sens de tension >  1,0 = 5volt , 0 volt
// qui fait que les moteur tourne dans le sens avant
void moteurX2 ()
{
  digitalWrite(13, HIGH);
  digitalWrite(2, LOW);
  Serial.println("avancer");
}

//activation moteur1 et moteur2 dans le sens de tension >  0,1 = 0volt , 5volt
// qui fait que les moteur tourne dans le sens inverse (arriere )
void arriere()
{
  digitalWrite(13, LOW);
  digitalWrite(2, HIGH);
  Serial.println("arriere");
}
//coupure  moteur1 et moteur2 dans le sens de tension >  0,0 = 0volt , 0volt
// qui fait que les moteur ne tourne plus  (ni avant ou ni arriere  )
void aret()
{
  digitalWrite(13, LOW);
  digitalWrite(2, LOW);
  Serial.println("stop");
}
