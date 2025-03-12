#include "Personne.h"
#include "Date.h"

Personne::Personne()
    : nom(""), prenom(""), email(""), tel(0) {}

Personne::Personne(string n, string p, Date d, string e, int t)
    : nom(n), prenom(p), datenaissance(d), email(e), tel(t) {}

void Personne::saisir() {
    cout << "Saisie des informations de la personne:" << endl;
    cout << " Nom: ";
    cin>>nom;
    cout<< " Prenom: " ;
    cin>> prenom;
    cout<< " Date de naissance: "<<endl ;
    datenaissance.saisir();
    cout << " Email: ";
    cin>> email;
    cout << " Tel: ";
    cin>> tel;
    cout << "Fin saisie" << endl;

}

void Personne::afficher() {
    cout << "Affichage des informations de la personne:" << endl;
    cout << " Nom: " << nom<< endl;
    cout<< " Prenom: " << prenom << endl;
    cout<< " Date de naissance: "<<;
    datenaissance.afficher();
    cout<< " Email: " << email<< endl;
    cout<< " Tel: " << tel << endl;
    cout << "Fin affichage" << endl;
}

void Personne::set_nom(string n) { nom = n; }
void Personne::set_prenom(string p) { prenom = p; }
void Personne::set_email(string e) { email = e; }
void Personne::set_tel(int t) { tel = t; }
void Personne::set_datenaissance(Date d) { datenaissance = d; }

void Personne::ajouterDoc(Document* doc) { documents.push_back(doc); }
void Personne::supprimerDoc(Document* doc) {
    documents.erase(remove(documents.begin(), documents.end(), doc), documents.end());
}

Personne::~Personne() {

}
