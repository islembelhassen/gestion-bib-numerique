#include "Licence.h"
#include <iostream>
#include "Livre.h"
#include "RechercheScientifique.h"
#include "Magazine.h"
#include "LivreAudio.h"

using namespace std;


Licence::Licence()
    : numL(0), titre(""), doc(NULL), TVA(0.0f), tot(0.0f) {}


Licence::Licence(int num, string tit, Document* document, float tva, float total)
    : numL(num), titre(tit), doc(document), TVA(tva), tot(total) {}


float Licence::calculTot() {
    if (doc != NULL) {
        tot = doc->get_prix() * (1 + TVA/100);
        return tot;
    }
    return 0.0f;
}


void Licence::saisir() {
    cout << "\nSaisie des informations de la licence:" << endl;
    cout << "Numéro de licence: ";
    cin >> numL;
    cin.ignore();

    cout << "Titre: ";
    getline(cin, titre);

    cout << "TVA (%): ";
    cin >> TVA;


    cout << "\nSaisie du document associé:" << endl;
    int choix;
    do {
        cout << "Type de document:\n"
             << "1-Livre\n2-Recherche\n3-Magazine\n4-LivreAudio\nChoix: ";
        cin >> choix;
        cin.ignore();

        switch(choix) {
            case 1: doc = new Livre(); break;
            case 2: doc = new RechercheScientifique(); break;
            case 3: doc = new Magazine(); break;
            case 4: doc = new LivreAudio(); break;
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
                choix = 0;
        }
    } while (choix < 1 || choix > 4);

    doc->saisir();
    tot = calculTot();
}


void Licence::afficher() {
    cout << "\n=== Informations Licence ===" << endl;
    cout << "Numéro: " << numL << endl;
    cout << "Titre: " << titre << endl;
    cout << "TVA: " << TVA << "%" << endl;

    if (doc != NULL) {
        cout << "\nDocument associé:" << endl;
        doc->afficher();
    } else {
        cout << "Aucun document associé." << endl;
    }

    cout << "Total TTC: " << tot << endl;
}


void Licence::set_numL(int num) {
    numL = num;
}

void Licence::set_titre(string tit) {
    titre = tit;
}

void Licence::set_TVA(float tva) {
    TVA = tva;
    tot = calculTot();
    }

int Licence::get_numL() {
    return numL;
}

string Licence::get_titre() {
    return titre;
}

float Licence::get_TVA() {
    return TVA;
}
