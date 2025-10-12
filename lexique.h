#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;
#include <map>

#include "utilitaire.hpp"

class Lexique {
    private:
    string nom_fichier;
/*     map<string, int> content; */
    map<string, int> nb_occurence;

    public:
    //Constructeur
    Lexique();
    Lexique(string nom_fichier);

    // Getters
    string get_nom_fichier();
    int get_nb_occurence();

    // Setters
    void setNomFichier(const string& nom_fichier);
    void setNbOccurence(const map<string, int>& nouveau_map);
    
    //Methodes
    void save_lexique(const std::string& nom_fichier) const;
    bool test_presence(const std::string& mot) const;
    int delete_mot(const std::string& mot);
    void display(void) const;
    void load_lexique();

    //Destructeur
    ~Lexique();
};