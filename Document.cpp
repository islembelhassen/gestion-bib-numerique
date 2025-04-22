#include"Document.h"
#include"Magazine.h"
#include"Livre.h"
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

Document::Document(string id,string titre, float prix/*,Date d*/)
{
    this->id=id;
    this->titre=titre;
    this->prix=prix;
    //
    //date=d;

}

Document::Document(const Document &d)
{
    id=d.id;
    titre=d.titre;
    prix=d.prix;
}

void Document::saisir()
{
    cout<<"Donner l'id: "<<endl;
    cin>>id;
    cout<<"Donner le titre: "<<endl;
    cin>>titre;
    cout<<"Donner le prix: "<<endl;
    cin>>prix;
    //auteur.saisir();
    //datepub.saisir();
}

void Document::afficher()
{
    cout<<"L'id: "<<id<<endl;
    cout<<"Le titre: "<<titre<<endl;
    cout<<"Le prix: "<<prix<<endl;
    //auteur.afficher();
    //datepub.afficher();
}

void Document::set_id(string id)
{
    this->id=id;
}

void Document::set_titre(string titre)
{
    this->titre=titre;
}

void Document::set_prix(float prix)
{
    this->prix=prix;
}

string Document::get_id()
{
    return id;
}

string Document::get_titre()
{
    return titre;
}

float Document::get_prix()
{
    return prix;
}


Document::~Document(){}

ostream& operator<<(ostream& o,Document& d)
{
    o<<"ID: "<<d.id<<endl;
    o<<"Titre: "<<d.titre<<endl;
    o<<"Prix: "<<d.prix<<endl;
    return o;
}

istream& operator>>(istream& i,Document& d)
{
    cout<<"Donner l'id: ";
    i>>d.id;
    cout<<"Donner le titre: ";
    i>>d.titre;
    cout<<"Donner le prix: ";
    i>>d.prix;
    return i;
}

ostream& operator<<(ostream& o,Document* d)
{
    o<<setw(10)<<d->id<<endl;
    o<<setw(10)<<d->titre<<endl;
    o<<setw(10)<<d->prix<<endl;
    Magazine* magazinePtr = dynamic_cast<Magazine*>(d);
    if (magazinePtr != nullptr)
    {
        o << "Edition: " <<setw(10) << magazinePtr->get_edition()<<endl;
    }
    Livre* livptr=dynamic_cast<Livre*>(d);
    if (livptr != nullptr)
    {
        o << "ISBN: " <<setw(10) << livptr->get_isbn()<<endl;
        o << "nbrchaps: " <<setw(10) << livptr->get_nbrchaps()<<endl;
    }
    return o;
}
/* fstream f;
    Livre l;
    f.open("C:\\Users\\Ons\\Desktop\\enicar\\1ère année\\semestre 2\\Programmation orienté objet\\projet vf\\ficherlivre.txt",ios::in|ios::out|ios::trunc);
    if(!f.is_open()) exit(-1);
    cin>>l;
    f<<l<<endl;
    cout<<l;
    f.close();*/
