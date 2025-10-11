#pragma once
#include <string>
#include <iostream>
#include <unordered_map> //POUR UTILISEER LES MAPS
using namespace std;

class Lexique {
    private:
    string nom_fichier; //nom du fichier source
    unordered_map<string, int> nb_occurence; //map pour stocker les mots et leur occurrence dans le texte

    public:
    //Constructeurs
    //constructeur par defaut
    Lexique();
    //constructeur avec nom de fichier
    Lexique(const string& nom_fichier);
    
    //getters
    //retourne le nom du fichier source
    const string& get_nom_fichier() const;
    //retourne la map des occurences
    const unordered_map<string, int>& get_nb_occurence() const;

    //setters
    //met a jour le nom du fichier source
    void setNomFichier(const string& nom);

    //met a jour la map des occurences
    void setNbOccurence(const unordered_map<string, int>& occurence);

    //Methodes
    //ajouter un mot dans le lexique
    void ajouter_mot(const string& mot);

    //charger le lexique a partir d'un fichier
    void load_lexique(const string& nom_fichier);

    //sauvegarder le lexique dans un fichier de sortie
    void save_lexique(const string& nom_fichier);

    //tester la presence d'un mot dans le lexique et retouner son nombre d'occurence
    const int test_presence(const string& mot) const;

    void delete_mot(const string& mot);

    //afficher le nombre de mots differents presents dans le lexique
    void display();

};