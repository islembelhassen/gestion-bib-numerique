#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED
#include<string>
#include<vector>
using namespace std;

class Document{
protected:
    string id;
    string titre;
    float prix;
    //vector<Auteur*> auteurs;
    //Date datepub;
public:
    Document(string="",string="",float=0/*,Date*/);
    Document(const Document&);
    virtual void saisir()=0;
    virtual void afficher();
    void set_id(string);
    void set_titre(string);
    void set_prix(float);
    //
    //void set_datepub(Date);
    string get_id();
    string get_titre();
    float get_prix();
    //
    //Date get_datepub();
    virtual ~Document();
};


class Magazine: public Document{
string edition;
public:
    Magazine(string,string,float/*,Date */,string="");
    virtual void saisir();
    virtual void afficher();
    void set_edition(string);
    string get_edition();
    virtual ~Magazine();
};

class Livre: public Document{
string ISBN;
public:
    Livre(string,string,float/*,Date,Auteur* */,string="");
    virtual void saisir();
    virtual void afficher();
    void set_isbn(string);
    string get_isbn();
    virtual ~Livre();
};

class RechercheScientifique: public Document{
string institut;
public:
    RechercheScientifique(string,string,float/*,Date,Auteur* */,string="");
    virtual void saisir();
    virtual void afficher();
    void set_institut(string);
    string get_institut();
    virtual ~RechercheScientifique();
};

class Audio{
protected:
    int duree;
    string type;
public:
    Audio(int=0,string="");
    virtual void saisir()=0;
    virtual void afficher();
    void set_duree(int);
    void set_type(string);
    int get_duree();
    string get_type();
    virtual ~Audio();
};

class LivreAudio: public Document, public Audio{
string narrateur;
public:
    LivreAudio(string,string,float/*,Date,Auteur* */,int,string,string);
    virtual void saisir();
    virtual void afficher();
    void set_narrateur(string);
    string get_narrateur();
    virtual ~LivreAudio();
};



#endif // DOCUMENT_H_INCLUDED
