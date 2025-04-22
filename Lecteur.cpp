#include "Lecteur.h"

using namespace std;

Lecteur::Lecteur()
    : Personne(), idLec(""), date_adhes(), nbrdoc(0) {}

Lecteur::Lecteur(string nom, string prenom, Date datenaissance, string email, int tel,
                 string id, Date dateAdhesion, int nbDoc)
    : Personne(nom, prenom, datenaissance, email, tel),
      idLec(id), date_adhes(dateAdhesion), nbrdoc(nbDoc) {}


void Lecteur::acheter_doc(string idDoc) {
    cout << "Document " << idDoc << " acheté par le lecteur " << idLec << endl;
    nbrdoc++;
    this->documents.push_back(new Document(idDoc));
}


void Lecteur::set_idLec(string id) {
    idLec = id;
}

void Lecteur::set_date_adhes(Date date) {
    date_adhes = date;
}

void Lecteur::set_nbrdoc(int nb) {
    nbrdoc = nb;
}


string Lecteur::get_idLec() {
    return idLec;
}

Date Lecteur::get_date_adhes() {
    return date_adhes;
}

int Lecteur::get_nbrdoc() {
    return nbrdoc;
}


void Lecteur::afficher() {
    cout << "=== Informations du Lecteur ===" << endl;
    cout << "ID Lecteur: " << idLec << endl;
    Personne::afficher();
    cout << "Date d'adhesion: ";
    date_adhes.afficher();
    cout << "Nombre de documents: " << nbrdoc << endl;
}


void Lecteur::saisir() {
    cout << "\nSaisie des informations du lecteur:" << endl;
    cout << "ID Lecteur: ";
    cin >> idLec;


    Personne::saisir();

    cout << "Date d'adhesion: " << endl;
    date_adhes.saisir();

    cout << "Nombre de documents: ";
    cin >> nbrdoc;
}


Lecteur::~Lecteur() {
    //vide
}




