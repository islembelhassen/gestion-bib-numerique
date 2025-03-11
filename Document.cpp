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

Document::Document(Document &d)
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

Magazine::Magazine(string id,string titre,float prix,string edition):Document(id,titre,prix)
{
    this->edition=edition;
}

void Magazine::saisir()
{
    Document::saisir();
    cout<<"Donner l'edition"<<endl;
    cin>>edition;
}

void Magazine::afficher()
{
    Document::afficher();
    cout<<"L'edition: "<<edition<<endl;
}

void Magazine::set_edition(string edition)
{
    this->edition=edition;
}

string Magazine::get_edition()
{
    return edition;
}

Magazine::~Magazine(){}

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

Audio::Audio(int duree, string type)
{
    this->duree=duree;
    this->type=type;
}

void Audio::saisir()
{
    cout<<"Donner la duree"<<endl;
    cin>>duree;
    cout<<"Donner le type"<<endl;
    cin>>type;
}

void Audio::afficher()
{
    cout<<"La duree: "<<duree<<endl;
    cout<<"Le type: "<<type<<endl;
}

void Audio::set_duree(int duree)
{
    this->duree=duree;
}
void Audio::set_type(string type)
{
    this->type=type;
}

int Audio::get_duree()
{
    return duree;
}

string Audio::get_type()
{
    return type;
}

Audio::~Audio(){}

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
