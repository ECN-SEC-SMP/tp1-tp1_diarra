//bibliotheques
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <sstream>
using namespace std;

//headers
#include "lexique.h"
#include "utilitaire.hpp"

//constructeur par defaut
Lexique::Lexique() 
{
    this->nom_fichier = " Aucun fichier";
    this->nb_occurence.insert({ "empty", 0 });
}

Lexique::Lexique(const string& nom_fichier) {
    this->nom_fichier = nom_fichier;
}

//getters
//En lecture seule, on utilise une reference constante pour eviter la copie inutile
// et garantir que l'appelant ne peut pas modifier la map interne.
const string& Lexique::get_nom_fichier() const {
    return nom_fichier;
}
const unordered_map<string, int>& Lexique::get_nb_occurence() const {
    return nb_occurence;
}

//setters
void Lexique::setNomFichier(const std::string& nom) {
    this->nom_fichier = nom;
}

void Lexique::setNbOccurence(const unordered_map<std::string, int>& nouveau_map) {
    this->nb_occurence = nouveau_map;
}

//Methodes
//tester la presence d'un mot dans le lexique et retouner son nombre d'occurence
//La methode find() retourne un iterateur vers l'element si trouve, ou nb_occurence.end() si non trouve
const int Lexique::test_presence(const string& mot) const {
    auto search = nb_occurence.find(mot); //l'iterateur cherche le mot dans la map
    if (search != nb_occurence.end()) { //si le mot est trouve
        return search->second; //retourne son occurrence
    }
    else {
        return 0; //mot non trouve = 0 occurence
    }
}

//ajouter un mot dans le lexique et incrementer son occurrence si il existe deja 
//et mettre son occurrence a 1 sinon
void Lexique::ajouter_mot(const string& mot){
    if (test_presence(mot) > 0) { //le mot existe deja
        //incrementer son occurrence
        nb_occurence[mot]++;
    }
    else {            //le mot n'existe pas encore
        nb_occurence[mot] = 1;
    }
}

void Lexique::delete_mot(const string& mot) {
    if (test_presence(mot) > 0) {
        nb_occurence.erase(mot);
        std::cout << "Le mot '" << mot << "' a été supprimé du lexique." << std::endl;
    } else {
        std::cout << "Le mot '" << mot << "' n'existe pas dans le lexique." << std::endl;
    }
}

//charger le lexique a partir d'un fichier
void Lexique::load_lexique(const string& nom_fichier) {
  //lire le fichier entre en parametre
    string content;
    // si la lecture echoue, on affiche un message d'erreur et on retourne
    if (!util::readFileIntoString(nom_fichier, content)) {
        cerr << "Erreur : impossible de lire le fichier " << nom_fichier << endl;
        return;
    }
    else {
        cout << "Fichier " << nom_fichier << " lu avec succès." << endl;
        // analyser le contenu du fichier et remplir le lexique
        util::remove_punctuation(content); //supprimer la ponctuation
        util::trim_punctuation(content); //supprimer la ponctuation en debut et fin de chaine
        std::istringstream iss(content);
        std::string mot;
        while (iss >> mot) {   // lit chaque mot séparé par des espaces
            if (!mot.empty()) {
                util::to_lower(mot); // mettre le mot en minuscule
                if(test_presence(mot)>0) //si le mot existe deja
                    nb_occurence[mot]++; //incremente son occurrence
                else
                nb_occurence[mot]=1;  // ajoute ou incrémente dans ta map
            }
        }
    }
}

//afficher le nombre de mots differents presents dans le lexique
void Lexique::display() {
        if (nb_occurence.empty()) {
            std::cout << "Le lexique est vide." << std::endl;
            return;
        }
        std::cout << "Contenu du lexique :" << std::endl;
        for (const auto& pair : nb_occurence) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }


//sauvegarde le contenu du lexique dans un fichier de sortie
void Lexique::save_lexique(const std::string& nom_fichier) {
    std::ofstream output_file(nom_fichier, std::ios::binary);
    if (!output_file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier pour écriture." << std::endl;
        return;
    }
    for (const auto& pair : nb_occurence) {
       output_file << pair.first << " : " << pair.second << endl;
   }
   std::cout << "Lexique sauvegardé avec succès dans " << nom_fichier << std::endl;
}





