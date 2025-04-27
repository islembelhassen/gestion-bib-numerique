#include"Auteur.h"

Auteur::Auteur():Personne(),idAut(""){}

Auteur::Auteur(string n, string p, Date d, string e, int t, string id):Personne(n,p,d,e,t),idAut(id){}

Auteur::Auteur(const Auteur& a)
    :Personne(a){
        idAut=a.idAut;
}
void Auteur::afficher(){
    cout<<"id auteur : "<<idAut<<endl;
    Personne::afficher();
}

void Auteur::saisir(){
    Personne::saisir();
    cout<<"donner id auteur: ";
    cin>>idAut;
}

void Auteur::set_idAut(string id){
    idAut=id;
}

string Auteur::get_idAut(){
    return idAut;
}

Auteur& Auteur::operator=(const Auteur& auteur) {
    if (this != &auteur) {
        Personne::operator=(auteur);
        idAut = auteur.idAut;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Auteur& auteur) {
    os << static_cast<const Personne&>(auteur)
       << "ID Auteur: " << auteur.idAut <<endl;
    return os;
}

istream& operator>>(istream& is, Auteur& auteur) {
    is >> static_cast<Personne&>(auteur);

    cout << "Entrez l'ID auteur: ";
    is >> auteur.idAut;

    return is;
}
