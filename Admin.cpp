#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin(string nom, string prenom, Date datenaissance, string email, int tel,
             string role, float salaire, Date datePriseFct, string id)
    : Personne(nom, prenom, datenaissance, email, tel),
      Role(role, salaire),
      date_prise_fct(datePriseFct),
      idA(id) {}


void Admin::set_idA(string id) {
    idA = id;
}

void Admin::set_date_prise_fct(Date date) {
    date_prise_fct = date;
}

string Admin::get_idA() {
    return idA;
}

Date Admin::get_date_prise_fct() {
    return date_prise_fct;
}


void Admin::ajouterLecteur(Lecteur* lecteur) {
    if (lecteur != NULL) {
        lecteurs.push_back(lecteur);
        cout << "Lecteur ajouté avec succès." << endl;
    }
}

void Admin::supprimerLecteur(Lecteur* lecteur) {
    for (auto it = lecteurs.begin(); it != lecteurs.end(); ++it) {
        if (*it == lecteur) {
            lecteurs.erase(it);
            cout << "Lecteur supprimé avec succès." << endl;
            return;
        }
    }
    cout << "Lecteur non trouvé." << endl;
}


void Admin::afficher() {
    cout << "\n=== Informations Administrateur ===" << endl;
    cout << "ID Admin: " << idA << endl;
    Personne::afficher();
    Role::afficher();
    cout << "Date de prise de fonction: ";
    date_prise_fct.afficher();
    cout << "\nListe des lecteurs gérés:" << endl;
    if (lecteurs.empty()) {
        cout << "Aucun lecteur géré." << endl;
    } else {
        for (const auto& lecteur : lecteurs) {
            if (lecteur != NULL) {
                lecteur->afficher();
                cout << "---------------------" << endl;
            }
        }
    }
}


void Admin::saisir() {
    cout << "\nSaisie des informations administrateur:" << endl;
    cout << "ID Admin: ";
    cin >> idA;

    Personne::saisir();
    Role::saisir();

    cout << "Date de prise de fonction: " << endl;
    date_prise_fct.saisir();
    char choix;
    cout << "Voulez-vous ajouter des lecteurs? (o/n): ";
    cin >> choix;

    while (tolower(choix) == 'o') {
        Lecteur* lecteur = new Lecteur();
        lecteur->saisir();
        lecteurs.push_back(lecteur);

        cout << "Ajouter un autre lecteur? (o/n): ";
        cin >> choix;
    }
}


Admin::~Admin() {
    for (auto lecteur : lecteurs) {
        if (lecteur != NULL) {
            delete lecteur;
        }
    }
    lecteurs.clear();
}



/////////////////////////////////////////////////////////////////////////////////////////////////////


void Admin::ecrireDansFichier(char file[20])  {

    ofstream fout(file);
    if (!fout) {
        cout << "Impossible d'ouvrir " << file << endl;
        return;
    }


    fout << "=== Donnees Administrateur ===" << endl;
    fout << "ID Admin: " << idA << endl;
    fout << "Date prise de fonction: " << date_prise_fct.toString() << endl;

    fout << "Nom: " << getNom() << endl;
    fout << "Prenom: " << getPrenom() << endl;
    fout << "Email: " << getEmail() << endl;


    fout.close();
    cout << "Donnees enregistrees dans " << file << endl;
}

void Admin::lireDepuisFichier( char file[20]) {

    ifstream fin(file);
    if (!fin) {
        cout << "Impossible d'ouvrir " << file << " en lecture" << endl;
        return;
    }

    cout << "\nContenu du fichier " << file << ":\n";
    cout << "----------------------------------------\n";

    string ligne;
    while (getline(fin, ligne)) {
        if (ligne.find("ID Admin: ") != string::npos) {
            idA = ligne.substr(10); // Extrait tout après "ID Admin: "
        }
        else if (ligne.find("Date prise de fonction: ") != string::npos) {
            string dateStr = ligne.substr(23);
            // Convertir dateStr en objet Date (à implémenter)
            date_prise_fct = parseDate(dateStr);
        }
        else if (ligne.find("Nom: ") != string::npos) {
            setNom(ligne.substr(5)); // Méthode héritée de Personne
        }
        else if (ligne.find("Prenom: ") != string::npos) {
            setPrenom(ligne.substr(8));
        }
        else if (ligne.find("Email: ") != string::npos) {
            setEmail(ligne.substr(7));
        }

        cout << ligne << endl; // Affichage du contenu
    }

    fin.close();
    cout << "----------------------------------------\n";
    cout << "Données admin chargées avec succès!\n";
}


