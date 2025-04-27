#include"Role.h"
#include <iostream>

using namespace std;

Role::Role() : role(""), salaire(0.0f) {}

Role::Role(string r, float s) : role(r), salaire(s) {}

void Role::set_role(string r) {
    role = r;
}

void Role::set_salaire(float s) {
    salaire = s;
}

string Role::get_role() {
    return role;
}

float Role::get_salaire() {
    return salaire;
}

void Role::afficher() {
    cout << "Role: " << role << endl;
    cout << "Salaire: " << salaire << endl;
}

void Role::saisir() {
    cout << "Saisie des informations du role:" << endl;
    cout << " Role: ";
    cin >> role;
    cout << " Salaire: ";
    cin >> salaire;
}

Role::~Role() {
    // vide
}


Role& Role::operator=(const Role& r) {
    if (this != &r) {
        role = r.role;
        salaire = r.salaire;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Role& r) {
    os << "Role: " << r.role << "\n"
       << "Salaire: " << r.salaire << " €\n";
    return os;
}

istream& operator>>(istream& is, Role& r) {
    cout << "Entrez le role: ";
    getline(is, r.role);
    cout << "Entrez le salaire: ";
    is >> r.salaire;
    is.ignore();
    return is;
}



ostream& operator<<(ostream& o, const Role* r) {
    if(r != nullptr) {
        o << "role: " << r->role << endl<<"salaire: " << r->salaire << endl;
    }
    return o;
}

istream& operator>>(istream& i, Role* r) {
    i>>r->role;
    i >> r->salaire;

    return i;
}
