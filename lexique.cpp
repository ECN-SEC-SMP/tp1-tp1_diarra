#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

#include "lexique.hpp"

//constructeur
Lexique::Lexique() 
{
    this->nom_fichier = "";
    this->nb_occurence = 0;
}

Lexique::Lexique(string nom_fichier) {
    this->nom_fichier = nom_fichier;
    this->nb_occurence = 0;
}


//Methodes
//sauvegarde le contenu du lexique dans un fichier de sortie
void Lexique::save_lexique(string nom_fichier) {
    ofstream fichier(nom_fichier);
    if (fichier) {
        fichier << "Nom du fichier : " << this->nom_fichier << endl;
        fichier << "Nombre d'occurences : " << this->nb_occurence << endl;
        fichier.close();
    } else {
        cerr << "Erreur lors de l'ouverture du fichier en écriture." << endl;
    }
}



bool Lexique::test_presence(string mot);

//teste la presence d'un mot dans le lexique et retourne le nombre d'occurences
int Lexique::delete_mot(string mot);

//supprime un mot du lexique
void Lexique::display_mot();

//affiche le nombre de mots differents presents dans le lexique
void Lexique::display()
