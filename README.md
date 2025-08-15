# robotPICS

Un projet de robot suiveur de ligne développé avec Arduino, capable de détecter et suivre des lignes noires sur une surface blanche à l'aide de capteurs optiques.

## Auteur

**VIRY Brandon**

## Description

Ce projet implémente un robot autonome capable de suivre une ligne noire tracée au sol. Le robot utilise deux capteurs optiques pour détecter la présence d'une ligne et ajuste automatiquement sa trajectoire en contrôlant deux moteurs.

## Fonctionnalités

- **Détection de ligne** : Utilisation de deux capteurs analogiques pour détecter les surfaces noires et blanches
- **Navigation autonome** : Le robot suit automatiquement une ligne noire
- **Contrôle des moteurs** : Gestion de deux moteurs pour les mouvements avant/arrière et les virages
- **Interface série** : Monitoring en temps réel via le port série
- **Contrôle d'arrêt** : Possibilité d'arrêter le robot via la communication série

## Matériel requis

- 1x Arduino (Uno, Nano, ou compatible)
- 2x Capteurs optiques/photodiodes (connectés aux ports A0 et A5)
- 2x Moteurs DC avec driver
- Châssis de robot
- Alimentation appropriée
- Câbles de connexion

## Schéma de connexion

### Capteurs
- **Capteur 1** : Port analogique A0
- **Capteur 2** : Port analogique A5

### Moteurs
- **Moteur 1** (Gauche) : Port digital 13
- **Moteur 2** (Droite) : Port digital 2

## Structure du projet

Le projet est organisé en plusieurs fichiers Arduino (.ino) :

### `main.ino`
Fichier principal contenant la logique complète du robot :
- Configuration des ports d'entrée et de sortie
- Boucle principale de détection et de mouvement
- Fonctions d'inversion d'état des moteurs
- Système d'indicateurs d'état via le port série

### `codecaptheorique.ino`
Code de test pour la calibration des capteurs :
- Test de détection des surfaces blanches et noires
- Seuil de détection fixé à 275
- Affichage des valeurs des capteurs

### `gestionCapteur.ino`
Logique de gestion des capteurs :
- Détection des différentes combinaisons de capteurs
- Logique de décision pour les mouvements (avancer, arrêter, tourner)

### `gestionMoteur2.ino`
Gestion avancée des moteurs avec capteurs :
- Fonctions de mouvement (avant, arrière, arrêt)
- Intégration avec la lecture des capteurs

### `gestionMoteurBase.ino`
Fonctions de base pour le contrôle des moteurs :
- Mouvements élémentaires (avancer, tourner à droite, tourner à gauche)
- Tests de fonctionnement des moteurs

## Logique de fonctionnement

### Seuil de détection
- **Surface blanche** : Valeur analogique > 275
- **Surface noire** : Valeur analogique < 275

### Comportements du robot
1. **Les deux capteurs détectent du blanc** : Le robot avance
2. **Les deux capteurs détectent du noir** : Le robot s'arrête ou inverse sa direction
3. **Capteur gauche sur noir, capteur droit sur blanc** : Virage à droite
4. **Capteur gauche sur blanc, capteur droit sur noir** : Virage à gauche

### États des moteurs
- **Robot OFF** : Les deux moteurs arrêtés (0,0)
- **Robot AVANCE** : Moteur1=1, Moteur2=0
- **Robot RECULE** : Moteur1=0, Moteur2=1

## Installation et utilisation

1. **Préparation du matériel** :
   - Assemblez le châssis du robot
   - Connectez les capteurs aux ports A0 et A5
   - Connectez les moteurs aux ports 13 et 2

2. **Programmation** :
   - Ouvrez l'IDE Arduino
   - Chargez le fichier `main.ino`
   - Téléversez le code sur votre Arduino

3. **Calibration** :
   - Utilisez `codecaptheorique.ino` pour tester vos capteurs
   - Ajustez le seuil de détection si nécessaire (actuellement 275)

4. **Test** :
   - Placez le robot sur une surface blanche avec une ligne noire
   - Ouvrez le moniteur série (9600 bauds) pour suivre l'état du robot
   - Le robot devrait automatiquement suivre la ligne

## Contrôles

- **Démarrage automatique** : Le robot démarre dès la mise sous tension
- **Arrêt d'urgence** : Envoyez n'importe quel caractère via le port série pour arrêter le robot
- **Monitoring** : Le port série affiche l'état du robot en temps réel

## Développement

Ce projet a été développé de manière modulaire pour faciliter les tests et la maintenance :
- Chaque fichier peut être testé indépendamment
- Les fonctions sont réutilisables entre les différents modules
- Le code est commenté en français pour faciliter la compréhension

## Améliorations possibles

- Ajout de capteurs supplémentaires pour une meilleure précision
- Implémentation d'un contrôle PID pour des mouvements plus fluides
- Ajout d'un écran LCD pour l'affichage d'informations
- Intégration de capteurs de distance pour éviter les obstacles
- Contrôle à distance via Bluetooth ou WiFi

## Dépannage

### Le robot ne suit pas la ligne
- Vérifiez les connexions des capteurs
- Calibrez le seuil de détection avec `codecaptheorique.ino`
- Assurez-vous que la ligne est suffisamment contrastée

### Les moteurs ne fonctionnent pas
- Vérifiez l'alimentation des moteurs
- Testez avec `gestionMoteurBase.ino`
- Vérifiez les connexions aux ports 13 et 2

### Pas de communication série
- Vérifiez que le débit est réglé sur 9600 bauds
- Assurez-vous que le câble USB est bien connecté

## Licence

Ce projet n'est sous aucune licence spécifique.
