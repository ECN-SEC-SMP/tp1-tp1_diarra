#include "lexique.h"
#include "utilitaire.hpp"


int main() {
    // //Test des constructeurs, getters
    Lexique lex; // Utilisation du constructeur par défaut
    // Lexique lex2("mon_fichier.txt"); // Utilisation du constructeur avec nom de fichier
    // cout << "Nom du fichier par défaut : " << lex.get_nom_fichier() << endl;
    // cout << "Nom du fichier : " << lex2.get_nom_fichier() << endl;
    // for (const auto& pair : lex.get_nb_occurence()) {
    //     cout << pair.first << " : " << pair.second << endl;
    // }

    // //Test des setters
    // lex.setNomFichier("nouveau_fichier.txt");

    // //Test de la méthode load_lexique
    // string fichier_test= "notreDameDeParis_A.txt";
    // lex.load_lexique(fichier_test);
    // cout << "Après chargement du fichier " << fichier_test << " :" << endl;
    // cout << "Nom du fichier par défaut : " << lex.get_nom_fichier() << endl;
    // for (const auto& pair : lex.get_nb_occurence()) {
    //     cout << pair.first << " : " << pair.second << endl;
    // }
    //Test de la méthode test_presence
    string mot1 = "empty";
    string mot2 = "non-existent";
    lex.test_presence(mot2);
    lex.test_presence(mot1);
    // // Test de la méthode delete_mot
    // cout << "Contenu du lexique par defaut :" << endl;
    // lex.display();
    // cout << "----------------------------------" << endl;

    // cout << "Suppression du mot 'empty' par defaut :" << endl;
    // const string& mot_init= "empty";
    // lex.delete_mot(mot_init);
    // lex.display();
    // cout << "----------------------------------" << endl;
    
    // cout << "Chargement du fichier test..." << endl;
    // lex.load_lexique("fichier test pour.txt");
    // cout << "----------------------------------" << endl;
    string mot_a_supprimer = "texte";
    lex.test_presence(mot_a_supprimer);
    // lex.display();
    // lex.delete_mot(mot_a_supprimer);
    // lex.display();
    // cout << "----------------------------------" << endl;
    // for (const auto& pair : lex.get_nb_occurence()) {
    // //     cout << pair.first << " : " << pair.second << endl;
    // // }
    // // return 0;
    // // Test de la méthode display
    // lex.display();
    lex.save_lexique("lexique_sauvegarde.txt");
    return 0;
}