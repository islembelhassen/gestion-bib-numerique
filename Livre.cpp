#include <iostream>
#include <string>
#include "Document.h"
#include "Livre.h"
using namespace std;

Livre::Livre(string id,string titre,float prix, string ISBN):Document(id,titre,prix)
{
    this->ISBN=ISBN;
}

void Livre::saisir()
{
    Document::saisir();
    cout<<"Donner l'ISBN: "<<endl;
    cin>>ISBN;
}

void Livre::afficher()
{
    Document::afficher();
    cout<<"L'ISBN: "<<ISBN<<endl;
}

void Livre::set_isbn(string ISBN)
{
    this->ISBN=ISBN;
}

string Livre::get_isbn()
{
    return ISBN;
}

Livre::~Livre(){}
