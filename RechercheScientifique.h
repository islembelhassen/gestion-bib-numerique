#ifndef RECHERCHESCIENTIFIQUE_H_INCLUDED
#define RECHERCHESCIENTIFIQUE_H_INCLUDED

#include<string>
#include"Document.h"
using namespace std;

class RechercheScientifique: public Document{
string institut;
public:
    RechercheScientifique(string="",string="",float=0/*,Date,Auteur* */,string="");
    virtual void saisir();
    virtual void afficher();
    void set_institut(string);
    string get_institut();
    friend ostream& operator<<(ostream&,RechercheScientifique&);
    friend istream& operator>>(istream&,RechercheScientifique&);
    virtual ~RechercheScientifique();
}; ostream& operator<<(ostream&,RechercheScientifique&);
   istream& operator>>(istream&,RechercheScientifique&);

#endif // RECHERCHESCIENTIFIQUE_H_INCLUDED
