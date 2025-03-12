#include<iostream>
#include<string>
#include "Document.h"
#include"RechercheScientifique.h"
using namespace std;


RechercheScientifique::RechercheScientifique(string id,string titre,float prix,string institut):Document(id,titre,prix)
{
    this->institut=institut;
}

void RechercheScientifique::saisir()
{
    Document::saisir();
    cout<<"Donner l'institut"<<endl;
    cin>>institut;
}

void RechercheScientifique::afficher()
{
    Document::afficher();
    cout<<"L'institut: "<<institut<<endl;
}

void RechercheScientifique::set_institut(string institut)
{
    this->institut=institut;
}

string RechercheScientifique::get_institut()
{
    return institut;
}

RechercheScientifique::~RechercheScientifique(){}
