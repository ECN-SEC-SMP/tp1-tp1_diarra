# 🧠 TP – Programmation Orientée Objet : Manipulation de fichier en C++

## 📘 Description du projet
Ce projet a été réalisé dans le cadre du **TP de Programmation Orientée Objet (POO)**.  
L’objectif est d’implémenter une classe `Lexique` permettant de :

- 📂 Lire un fichier texte ;
- 🧮 Construire un dictionnaire des mots distincts et compter leurs occurrences ;
- 🔍 Tester la présence d’un mot ;
- 🗑️ Supprimer un mot du lexique ;
- 💾 Sauvegarder le lexique dans un fichier de sortie.

Le but est de manipuler les **concepts de la POO en C++** : classes, encapsulation, méthodes, et structures de données (`std::map`) et 
de mener un choix pertinent quant à la manipulation de ces structures de données.

---

## 🧩 Fonctionnalités principales
- Lecture d’un fichier texte source ;
- Comptage des occurrences des mots distincts ;
- Suppression ou recherche d’un mot donné ;
- Sauvegarde du lexique dans un fichier texte ;
- Nettoyage automatique du texte (ponctuation, casse) en utilisant les fonctions utilitaires.
  

---

## 🧱 Structure du projet
TP1-Lexique:
- main.cpp # Fichier principal contenant les tests
- lexique.h # Déclaration de la classe Lexique
- lexique.cpp # Implémentation de la classe Lexique et surcharge des opérateurs
- fichier pour mon.txt # Exemple de fichier d’entrée
- fichier sauvegarde.txt # Exemple de fichier de sortie généré
- README.md # Présent document comportant aussi le diagramme de classe
- Les fichiers de tests

## 🧱 Diagramme de classe de la classe Lexique
<img width="535" height="604" alt="image" src="https://github.com/user-attachments/assets/d4cfa568-4a10-4928-853f-1ca7cac8d5b7" /> <img width="600" height="400" alt="image" src="https://github.com/user-attachments/assets/9a014b0c-a33d-4163-a646-1c15b211799d" />




## 🧪 Tests réalisés

✅ Création d'instances de la classe ;
✅ Chargement d’un fichier texte réel ;
✅ Suppression de mots existants et inexistants ;
✅ Gestion d’un fichier vide ou inexistant ;
✅ Sauvegarde du lexique et vérification du contenu généré ;
✅ Affichage du contenu du lexique ;
✅ Fonctionnement structure map ;


---

## ⚙️ Compilation et exécution

### 🧰 Compilation
Utiliser **g++** (ou tout compilateur compatible C++17 ou supérieur) :

```bash
g++ lexique.cpp utilitaire.cpp main.cpp -o monprog
```
Makefile
Lancer la commande make pour les deux cpp: lexique et main puis lancer l'exécutable.
PS: il faut changer le chemin du fichier source dans le makefile.

### 🧰 Exécution
```bash
./monprog
```

## 📘 Auteurs

### Noms : Mame Diarra DIOP & Eugénie Roquain;
### Filière : SEC;
### Université : Ecole Centrale de Nantes;

📅 TP réalisé en octobre 2025

