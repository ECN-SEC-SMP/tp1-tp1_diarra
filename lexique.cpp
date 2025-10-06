#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

#include "lexique.h"
#include "utilitaire.hpp"

//constructeur
Lexique::Lexique() 
{
    this->nom_fichier = "";
    this->nb_occurence = 
}

Lexique::Lexique(string nom_fichier) {
    this->nom_fichier = nom_fichier;
    this->nb_occurence = 
}

//getters
string Lexique::get_nom_fichier() {
    return this->nom_fichier;
}
int Lexique::get_nb_occurence() {
    return this->nb_occurence;
}
//setters
void setNomFichier(const std::string& nom) {
    nom_fichier = nom;
}

void setNbOccurence(const std::map<std::string, int>& nouveau_map) {
    nb_occurence = nouveau_map;
}
//Methodes
//sauvegarde le contenu du lexique dans un fichier de sortie
void save_lexique(const std::string& nom_fichier) const {
    std::ofstream output_file(nom_fichier, std::ios::binary);
    if (!output_file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier pour écriture." << std::endl;
        return;
    }

    for (const auto& [mot, occ] : nb_occurence) {
        output_file << mot << " " << occ << "\n";
    }
    std::cout << "Lexique sauvegardé avec succès dans " << nom_fichier << std::endl;
}


bool test_presence(const std::string& mot) const {
    return nb_occurence.find(mot) != nb_occurence.end();
}

int delete_mot(const std::string& mot) {
    auto it = nb_occurence.find(mot);
    if (it != nb_occurence.end()) {
        nb_occurence.erase(it);
        return 1;
        }
        return 0;
    }
void display() const {
        if (nb_occurence.empty()) {
            std::cout << "Le lexique est vide." << std::endl;
            return;
        }

        std::cout << "Contenu du lexique :" << std::endl;
        for (const auto& [mot, occ] : nb_occurence) {
            std::cout << mot << " : " << occ << std::endl;
        }
    }

int main() {
    Lexique lex("fichier test pour.txt");
    lex.save_lexique("fichier test pour.txt");
    
    return 0;

}