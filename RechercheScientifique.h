#ifndef RECHERCHESCIENTIFIQUE_H_INCLUDED
#define RECHERCHESCIENTIFIQUE_H_INCLUDED

#include<string>
#include"Document.h"
using namespace std;

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

#endif // RECHERCHESCIENTIFIQUE_H_INCLUDED
