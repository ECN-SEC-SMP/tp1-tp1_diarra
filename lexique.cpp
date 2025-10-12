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
    this->nb_occurence = {};
}

Lexique::Lexique(string nom_fichier) {
    this->nom_fichier = nom_fichier;
    this->nb_occurence = {};
}

//getters
string Lexique::get_nom_fichier() {
    return this->nom_fichier;
}
int Lexique::get_nb_occurence() {
    return this->nb_occurence.size();
}
//setters
void Lexique::setNomFichier(const std::string& nom) {
    nom_fichier = nom;
}

void Lexique::setNbOccurence(const std::map<std::string, int>& nouveau_map) {
    nb_occurence = nouveau_map;
}

void Lexique::load_lexique() {
    std::ifstream input_file(this->nom_fichier);
    if (!input_file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << nom_fichier << std::endl;
        return;
    }

    std::string mot;
    while (input_file >> mot) {
        ++nb_occurence[mot]; // incrémente le compteur pour chaque mot
    }

    std::cout << "Fichier " << nom_fichier << " chargé avec " << nb_occurence.size() << " mots uniques." << std::endl;
}

//Methodes
//sauvegarde le contenu du lexique dans un fichier de sortie
void Lexique::save_lexique(const std::string& nom_fichier) const {
    std::ofstream output_file(nom_fichier, std::ios::binary);
    if (!output_file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier pour écriture." << std::endl;
        return;
    }

    for (const auto& [mot, occ] : nb_occurence) {
        output_file << mot << " " << occ << "\n";
        std::cout << "1" << std::endl;
    }
    std::cout << "Lexique sauvegardé avec succès dans " << nom_fichier << std::endl;
}


bool Lexique::test_presence(const std::string& mot) const {
    return nb_occurence.find(mot) != nb_occurence.end();
}

int Lexique::delete_mot(const std::string& mot) {
    auto it = nb_occurence.find(mot);
    if (it != nb_occurence.end()) {
        nb_occurence.erase(it);
        return 1;
        }
        return 0;
    }
void Lexique::display() const {
        if (nb_occurence.empty()) {
            std::cout << "Le lexique est vide." << std::endl;
            return;
        }

        std::cout << "Contenu du lexique :" << std::endl;
        for (const auto& [mot, occ] : nb_occurence) {
            std::cout << mot << " : " << occ << std::endl;
        }
    }

// Destructeur
Lexique::~Lexique() {
    // Rien de spécial à faire ici, la map et les chaînes se détruiront automatiquement
}

int main() {
    Lexique lex("lesMiserables_A.txt");
    
    lex.load_lexique();

    lex.save_lexique("fichier test pour.txt");
    return 0;

}