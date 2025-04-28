#include "Licence.h"
#include <iostream>
#include <algorithm>
#include "Livre.h"
#include "RechercheScientifique.h"
#include "Magazine.h"
#include "LivreAudio.h"

using namespace std;

Licence::Licence()
    : numL(0), titre(""), TVA(0.0f), tot(0.0f) {}

Licence::Licence(int num, string tit, float tva, float total)
    : numL(num), titre(tit), TVA(tva), tot(total) {}

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

int Licence::get_numL()  {
    return numL;
}

string Licence::get_titre()  {
    return titre;
}

float Licence::get_TVA()  {
    return TVA;
}



float Licence::calculTot() {
    tot = 0.0f;
    for (Document* doc : documents) {
        if (doc != nullptr) {
            tot += doc->get_prix() * (1 + TVA/100);
        }
    }
    return tot;
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

    char choix;
    do {
        cout << "Ajouter un document? (o/n): ";
        cin >> choix;
        if (tolower(choix) == 'o') {
            ajouterDocument("");
        }
    } while (tolower(choix) == 'o');

    tot = calculTot();
}

void Licence::afficher() {
    cout << "\n=== Informations Licence ===" << endl;
    cout << "Numéro: " << numL << endl;
    cout << "Titre: " << titre << endl;
    cout << "TVA: " << TVA << "%" << endl;

    if (!documents.empty()) {
        cout << "\nDocuments associés (" << documents.size() << "):" << endl;
        int i = 1;
        for (Document* doc : documents) {
            cout << "Document #" << i++ << ":" << endl;
            if (doc != nullptr) {
                doc->afficher();
            } else {
                cout << "Document invalide" << endl;
            }
        }
    } else {
        cout << "Aucun document associé." << endl;
    }

    cout << "Total TTC: " << tot << endl;
}

void Licence::ajouterDocument(string idDocument) {
    if (!idDocument.empty()) {
        for (Document* doc : documents) {
            if (doc != nullptr && doc->get_id() == idDocument) {
                cout << "Un document avec l'ID " << idDocument << " existe déjà." << endl;
                return;
            }
        }
    }

    cout << "Type de document:\n"
         << "1-Livre\n2-Recherche\n3-Magazine\n4-LivreAudio\nChoix: ";
    int choix;
    cin >> choix;
    cin.ignore();

    Document* newDoc = nullptr;
    switch(choix) {
        case 1: newDoc = new Livre(); break;
        case 2: newDoc = new RechercheScientifique(); break;
        case 3: newDoc = new Magazine(); break;
        case 4: newDoc = new LivreAudio(); break;
        default:
            cout << "Choix invalide." << endl;
            return;
    }


    if (!idDocument.empty()) {
        newDoc->set_id(idDocument);
    }

    newDoc->saisir();
    documents.push_back(newDoc);
    tot = calculTot();

    cout << "Document ajouté avec succès. ID: " << newDoc->get_id() << endl;
}

void Licence::supprimerDocument(string idDocument) {
    if (idDocument.empty()) {
        cout << "Veuillez spécifier un ID de document." << endl;
        return;
    }

    bool found = false;
    auto it = documents.begin();
    while (it != documents.end() && !found) {
        if (*it != nullptr && (*it)->get_id() == idDocument) {
            delete *it;
            it = documents.erase(it);
            found = true;
            cout << "Document " << idDocument << " supprimé." << endl;
        } else {
            ++it;
        }
    }

    if (!found) {
        cout << "Aucun document trouvé avec l'ID " << idDocument << endl;
    }

    tot = calculTot();
}
Licence& Licence::operator=(const Licence& licence) {
    if (this != &licence) {
        numL = licence.numL;
        titre = licence.titre;
        TVA = licence.TVA;
        tot = licence.tot;


        for (Document* doc : documents) {
            delete doc;
        }
        documents.clear();


        for (Document* doc : licence.documents) {
            if (doc != nullptr) {
                if (dynamic_cast<Livre*>(doc)) {
                    documents.push_back(new Livre(*dynamic_cast<Livre*>(doc)));
                } else if (dynamic_cast<RechercheScientifique*>(doc)) {
                    documents.push_back(new RechercheScientifique(*dynamic_cast<RechercheScientifique*>(doc)));
                } else if (dynamic_cast<Magazine*>(doc)) {
                    documents.push_back(new Magazine(*dynamic_cast<Magazine*>(doc)));
                } else if (dynamic_cast<LivreAudio*>(doc)) {
                    documents.push_back(new LivreAudio(*dynamic_cast<LivreAudio*>(doc)));
                }
            }
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const Licence& licence) {
    os << "Numero Licence: " << licence.numL << endl
       << "Titre: " << licence.titre << endl
       << "TVA: " << licence.TVA << endl
       << "Total: " << licence.tot << endl
       << "Documents associes (" << licence.documents.size() << "):" << endl;

    for (const Document* doc : licence.documents) {
        if (doc != nullptr) {
            if (typeid(*doc) == typeid(Livre)) {
            os << static_cast<const Livre*>(doc);
            }
            else if (typeid(*doc) == typeid(RechercheScientifique)) {
                os << static_cast<const RechercheScientifique*>(doc);
            }
            else if (typeid(*doc) == typeid(Magazine)) {
                os << static_cast<const Magazine*>(doc);
            }
            else if (typeid(*doc) == typeid(LivreAudio)) {
                os << static_cast<const LivreAudio*>(doc);
            }
         else {
            os << "Aucun";
        }
        }
    }
    return os;
}



istream& operator>>(istream& is, Licence& licence) {
    // Clear existing documents
    for (Document* doc : licence.documents) {
        delete doc;
    }
    licence.documents.clear();

    cout << "Entrez le numero de licence: ";
    is >> licence.numL;

    cout << "Entrez le titre: ";
    is.ignore();
    getline(is, licence.titre);

    cout << "Entrez la TVA: ";
    is >> licence.TVA;

    char addMore;
    do {
        cout << "Type de document:\n"
             << "1- Livre\n"
             << "2- Recherche Scientifique\n"
             << "3- Magazine\n"
             << "4- Livre Audio\n"
             << "0- Fin\n"
             << "Choix: ";

        int choix;
        is >> choix;

        Document* newDoc = nullptr;
        switch(choix) {
            case 1:
                newDoc = new Livre();
                is >> *dynamic_cast<Livre*>(newDoc);
                break;
            case 2:
                newDoc = new RechercheScientifique();
                is >> *dynamic_cast<RechercheScientifique*>(newDoc);
                break;
            case 3:
                newDoc = new Magazine();
                is >> *dynamic_cast<Magazine*>(newDoc);
                break;
            case 4:
                newDoc = new LivreAudio();
                is >> *dynamic_cast<LivreAudio*>(newDoc);
                break;
            case 0:
                break;
            default:
                cout << "Choix invalide" << endl;
        }

        if (newDoc != nullptr) {
            licence.documents.push_back(newDoc);
        }

        if (choix != 0) {
            cout << "Ajouter un autre document? (o/n): ";
            is >> addMore;
        } else {
            addMore = 'n';
        }
    } while (tolower(addMore) == 'o');

    licence.tot = licence.calculTot();
    return is;
}
