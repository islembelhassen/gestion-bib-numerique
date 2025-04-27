#include "Lecteur.h"
#include"Document.h"
#include"Livre.h"
#include"LivreAudio.h"
#include"Magazine.h"
#include"RechercheScientifique.h"

using namespace std;

Lecteur::Lecteur()
    : Personne(), idLec(""), date_adhes(), nbrdoc(0) {}

Lecteur::Lecteur(string nom, string prenom, Date datenaissance, string email, int tel,
                 string id, Date dateAdhesion, int nbDoc)
    : Personne(nom, prenom, datenaissance, email, tel),
      idLec(id), date_adhes(dateAdhesion), nbrdoc(nbDoc) {}

Lecteur::Lecteur(const Lecteur& l):Personne(l){
    this->idLec=l.idLec;
    this->date_adhes=l.date_adhes;
    this->nbrdoc=l.nbrdoc;
}

void Lecteur::acheter_doc() {
    string idDoc;
    cout << "donner id document: "<< endl;
    cin>>idDoc;
    nbrdoc++;

    int type;
    cout << "quelle type de document: 1-Livre 2-Recherche 3-Magazine 4-LivreAudio"<<endl<<"Choix: ";
    cin>>type;

     if(type==1){ Livre d(idDoc); d.saisir(); documents.push_back(&d);}
        else if  (type==3){ Magazine d( idDoc ); d.saisir(); documents.push_back(&d);}
             else if (type==4){ LivreAudio d(idDoc); d.saisir(); documents.push_back(&d);}
                  else if (type==2){ RechercheScientifique d(idDoc); d.saisir(); documents.push_back(&d);}
                        else {Document* d=NULL; documents.push_back(d);}

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



Lecteur& Lecteur::operator=(const Lecteur& lecteur) {
    if (this != &lecteur) {
        Personne::operator=(lecteur);
        idLec = lecteur.idLec;
        date_adhes = lecteur.date_adhes;
        nbrdoc = lecteur.nbrdoc;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Lecteur& lecteur) {
    os << static_cast<const Personne&>(lecteur)
       << "ID Lecteur: " << lecteur.idLec << endl
       << "Date adhesion: " << lecteur.date_adhes
       <<"nombre des documents: "<< lecteur.nbrdoc << endl;
    return os;
}

istream& operator>>(istream& is, Lecteur& lecteur) {
    is >> static_cast<Personne&>(lecteur);

    cout << "Entrez l'ID lecteur: ";
    is >> lecteur.idLec;

    cout << "Entrez la date d'adhesion: ";
    is >> lecteur.date_adhes;

    cout << "Entrez le nombre de documents: ";
    is >> lecteur.nbrdoc;

    return is;
}



ostream& operator<<(ostream& o, const Lecteur* l) {
    o << static_cast<const Personne*>(l);
    o <<"id: "<<l->idLec << endl << "Date adhesion: "<<l->date_adhes <<"nbr documents: "<< l->nbrdoc << endl;

    return o;
}

istream& operator>>(istream& i, Lecteur* l) {
    i >> static_cast<Personne*>(l);
    getline(i >> ws, l->idLec);
    i >> l->date_adhes;
    i >> l->nbrdoc;

    return i;
}
