#include"MotCle.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<limits>
using namespace std;

MotCle::MotCle(string libelle,string categorie, string langue)
{
    this->libelle=libelle;
    this->categorie=categorie;
    this->langue=langue;
}

void MotCle::saisir()
{
    cout<<"Donner le libelle du mot cle: ";
    cin>>libelle;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout<<"Donner la categorie du mot cle: ";
    cin>>categorie;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout<<"Donner la langue: ";
    cin>>langue;

}

void MotCle::afficher()
{
    cout<<"Libelle: "<<libelle<<endl;
    cout<<"Categorie: "<<categorie<<endl;
    cout<<"Langue: "<<langue<<endl;
}

void MotCle::set_libelle(string libelle)
{
    this->libelle=libelle;
}

void MotCle::set_categorie(string categorie)
{
    this->categorie=categorie;
}

void MotCle::set_langue(string langue)
{
    this->langue=langue;
}

string MotCle::get_libelle()
{
    return libelle;
}

string MotCle::get_categorie()
{
    return categorie;
}

string MotCle::get_langue()
{
    return langue;
}

MotCle::~MotCle(){}


ostream& operator<<(ostream& o, MotCle& m)
{
    o<<"Libelle: "<<m.libelle<<endl;
    o<<"Categorie: "<<m.categorie<<endl;
    o<<"Langue: "<<m.langue<<endl;
    return o;
}

ostream& operator<<(ostream& o,MotCle* m)
{
    o<<"Libelle: "<<m->libelle<<endl;
    o<<"Categorie: "<<m->categorie<<endl;
    o<<"Langue: "<<m->langue<<endl;
    return o;
}

istream& operator>>(istream& i, MotCle& m)
{
    cout<<"Donner le libelle: "<<endl;;
    i>>m.libelle;
    i.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Donner la categorie: "<<endl;;
    i>>m.categorie;
    i.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Donner la langue: "<<endl;
    i>>m.langue;
    i.ignore(numeric_limits<streamsize>::max(), '\n');
    return i;
}

istream& operator>>(istream& i, MotCle* m)
{
    i>>m->libelle;
    i>>m->categorie;
    i>>m->langue;
    return i;
}
