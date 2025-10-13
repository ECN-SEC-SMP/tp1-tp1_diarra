#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>
#include <ostream>

using namespace std;

#include "lexique.h"
#include "utilitaire.hpp"

// constructeur
Lexique::Lexique()
{
    this->nom_fichier = "";
    this->nb_occurence = {};
}

Lexique::Lexique(string nom_fichier)
{
    this->nom_fichier = nom_fichier;
    this->nb_occurence = {};
}

// getters
string Lexique::get_nom_fichier()
{
    return this->nom_fichier;
}
int Lexique::get_nb_occurence()
{
    return this->nb_occurence.size();
}
// setters
void Lexique::setNomFichier(const std::string &nom)
{
    nom_fichier = nom;
}

void Lexique::setNbOccurence(const std::map<std::string, int> &nouveau_map)
{
    /// copie toutes les paires mot
    nb_occurence = nouveau_map;
}

void Lexique::load_lexique()
{
    std::ifstream input_file(this->nom_fichier);
    if (!input_file)
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << nom_fichier << std::endl;
        return;
    }

    std::string mot;
    while (input_file >> mot)
    {
        ++nb_occurence[mot]; // incrémente le compteur pour chaque mot
    }

    std::cout << "Fichier " << nom_fichier << " chargé avec " << nb_occurence.size() << " mots uniques." << std::endl;
}

// Methodes

/**
 * @brief Sauvegarde le contenu du lexique dans un fichier texte.
 * 
 * Ouvre un fichier de sortie et écrit pour chaque mot de la map nb_occurence
 * une ligne contenant le mot et son nombre d'occurrences, séparés par un espace.
 * 
 * Exemple de fichier généré :
 * ```
 * amour 12
 * guerre 5
 * livre 8
 * ```
 * 
 * @param nom_fichier Nom du fichier de sortie où enregistrer le lexique.
 * @note La méthode est const : elle ne modifie pas le contenu du lexique.
 * @warning Si le fichier ne peut pas être ouvert, un message d'erreur est affiché
 *          et aucune donnée n'est écrite.
 */
void Lexique::save_lexique(const std::string &nom_fichier) const
{
    std::ofstream output_file(nom_fichier, std::ios::binary);
    if (!output_file)
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier pour écriture." << std::endl;
        return;
    }

    for (const auto &[mot, occ] : nb_occurence)
    {
        output_file << mot << " " << occ << "\n";
    }
    std::cout << "Lexique sauvegardé avec succès dans " << nom_fichier << std::endl;
}


/**
 * @brief Vérifie si un mot est présent dans le lexique.
 * 
 * Parcourt la map nb_occurence et retourne true si la clé correspondant au mot est trouvée.
 * 
 * @param mot Le mot à rechercher dans le lexique.
 * @return true si le mot est présent.
 * @return false sinon.
 */

bool Lexique::test_presence(const std::string &mot) const
{
    for (std::map<std::string, int>::const_iterator iter = this->nb_occurence.begin();
         iter != this->nb_occurence.end(); iter++)
    {
        if (iter->first == mot)
        {
            return true;
        }
    }
    return false;
}


/**
 * @brief Supprime un mot du lexique s'il est présent.
 * 
 * Recherche le mot dans nb_occurence avec find(), puis l'efface s'il existe.
 * 
 * @param mot Le mot à supprimer.
 * @return int 1 si le mot a été supprimé, 0 s'il n'était pas présent.
 */

int Lexique::delete_mot(const std::string &mot)
{
    auto it = nb_occurence.find(mot);
    if (it != nb_occurence.end())
    {
        nb_occurence.erase(it);
        return 1;
    }
    return 0;
}

/**
 * @brief Affiche le contenu complet du lexique sur la console.
 * 
 * Si le lexique est vide, un message l'indique. Sinon, la fonction
 * parcourt la map nb_occurence et affiche chaque mot avec son nombre d'occurrences.
 * 
 * Exemple d'affichage :
 * ```
 * Contenu du lexique :
 * amour : 12
 * guerre : 5
 * livre : 8
 * ```
 * @note La méthode est const : elle ne modifie pas les données du lexique.
 */

void Lexique::display() const
{
    if (nb_occurence.empty())
    {
        std::cout << "Le lexique est vide." << std::endl;
        return;
    }

    std::cout << "Contenu du lexique :" << std::endl;
    for (const auto &[mot, occ] : nb_occurence)
    {
        std::cout << mot << " : " << occ << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Lexique &lex) {
    if (lex.nb_occurence.empty()) {
        os << "Le lexique est vide." << std::endl;
        return os;
    }

    os << "Contenu du lexique :" << std::endl;
    for (const auto &[mot, occ] : lex.nb_occurence) {
        os << mot << " : " << occ << std::endl;
    }
    return os;
}

Lexique &Lexique::operator+=(const Lexique &autre) {
    for (const auto &[mot, occ] : autre.nb_occurence) {
        this->nb_occurence[mot] += occ;
    }
    return *this;
}

Lexique &Lexique::operator-=(const Lexique &autre) {
    for (const auto &[mot, _] : autre.nb_occurence) {
        this->nb_occurence.erase(mot);
    }
    return *this;
}

// Destructeur
Lexique::~Lexique()
{
    // Rien de spécial à faire ici, la map et les chaînes se détruiront automatiquement
}

int main(){
    Lexique lex("lesMiserables_A.txt");
    Lexique lex1("fichier test_2");
    Lexique lex2("fichier test");
    lex2.load_lexique();
    lex2.save_lexique("fichier test.txt");
    lex1.load_lexique();
    lex1.save_lexique("fichier test_2.txt");

    lex2 -= lex1;

    lex2.save_lexique("fichier test.txt");
}
