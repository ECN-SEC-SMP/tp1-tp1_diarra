#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

#include "utilitaire.hpp"
class Lexique {
    private:

    string nom_fichier;
    int nb_occurence;

    public:

    //Constructeur
    Lexique();
    Lexique(string nom_fichier);
    
    //Methodes
    void save_lexique(string nom_fichier);
    bool test_presence(string mot);
    int delete_mot(string mot);
    void display();

    //Destructeur
    ~Lexique();
};