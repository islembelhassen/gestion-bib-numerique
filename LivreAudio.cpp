#include<iostream>
#include<string>
#include"Document.h"
#include"Audio.h"
#include"LivreAudio.h"
using namespace std;

LivreAudio::LivreAudio(string id, string titre, float prix,int duree,string type,string narrateur):Document(id,titre,prix),Audio(duree,type)
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
