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
