#include"Document.h"
#include<string>
#include<vector>
#include<iostream>
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









