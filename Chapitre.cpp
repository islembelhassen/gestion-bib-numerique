#include"Chapitre.h"
#include<iostream>
#include<string>
using namespace std;

Chapitre::Chapitre(string titre, int nbrpages)
{
    this->titre=titre;
    this->nbrpages=nbrpages;
}

void Chapitre::saisir()
{
    cout<<"Donner le titre du chapitre: ";
    cin>>titre;
    cout<<"Donner le nombre de pages du chapitre: ";
    cin>>nbrpages;
}

void Chapitre::afficher()
{
    cout<<"Titre: "<<titre<<endl;
    cout<<"Nombre de pages: "<<nbrpages<<endl;
}

void Chapitre::set_titre(string titre)
{
    this->titre=titre;
}

void Chapitre::set_nbrpages(int nbrpages)
{
    this->nbrpages=nbrpages;
}

string Chapitre::get_titre()
{
    return titre;
}

int Chapitre::get_nbrpages()
{
    return nbrpages;
}

Chapitre::~Chapitre(){}

ostream& operator<<(ostream& o,Chapitre& c)
{
    o<<"Titre: "<<c.titre<<endl;
    o<<"Nombre de pages: "<<c.nbrpages<<endl;
    return o;
}

istream& operator>>(istream& i,Chapitre& c)
{
    cout<<"Donenr le titre du chapitre: ";
    i>>c.titre;
    cout<<"Donner le nombre de pages du chapitre: ";
    i>>c.nbrpages;
    return i;
}
