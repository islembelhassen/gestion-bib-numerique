#include<iostream>
#include<string>
#include"Document.h"
#include"Audio.h"
#include"LivreAudio.h"
#include<iomanip>
using namespace std;

LivreAudio::LivreAudio(string id, string titre, float prix,Date datepub,int duree,string type,string narrateur):Document(id,titre,prix,datepub),Audio(duree,type)
{
    this->narrateur=narrateur;
}

void LivreAudio::saisir()
{
    Document::saisir();
    Audio::saisir();
    cout<<"Donner le narrateur"<<endl;
    cin>>narrateur;
}

void LivreAudio::afficher()
{
    Document::afficher();
    Audio::afficher();
    cout<<"Le narrateur: "<<narrateur<<endl;
}

void LivreAudio::set_narrateur(string narrateur)
{
    this->narrateur=narrateur;
}

string LivreAudio::get_narrateur()
{
    return narrateur;
}

LivreAudio::~LivreAudio(){}

ostream& operator<<(ostream& o,LivreAudio& la)
{
    Document* d=&la;
    o<<*d;
    Audio* au=&la;
    o<<*au;
    o<<"Narrateur: "<<la.narrateur<<endl;
    return o;
}

istream& operator>>(istream& i,LivreAudio& la)
{
    Document* d=&la;
    i>>*d;
    Audio* au=&la;
    i>>*au;
    cout<<"Donner le narrateur: ";
    i>>la.narrateur;
    return i;
}

ostream& operator<<(ostream& o, LivreAudio* la)
{
    o<<"ID: "<<setw(10)<<la->id<<endl;
    o<<"Titre: "<<setw(10)<<la->titre<<endl;
    o<<"Prix: "<<setw(10)<<la->prix<<endl;
    o<<"Date de publication: "<<setw(10)<<la->datepub<<endl;
    for(int i=0;i<la->description.size();i++)
        o<<la->description[i]<<endl;
    o<<setw(10)<<la->type<<endl;
    o<<setw(10)<<la->duree<<endl;
    return o;
}
