#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED

#include "Document.h"
#include<string>
#include<fstream>
using namespace std;

class Magazine: public Document{
string edition;
public:
    Magazine(string="",string="",float=0,Date=Date(),string="");
    virtual void saisir()override;
    virtual void afficher()override;
    void set_edition(string);
    string get_edition();
    friend ostream& operator<<(ostream&,Magazine&);
    friend ostream& operator<<(ostream&,Magazine*);
    friend istream& operator>>(istream&,Magazine&);
    friend istream& operator>>(istream&,Magazine*);
    virtual ~Magazine();
}; ostream& operator<<(ostream&,Magazine&);
   istream& operator>>(istream&,Magazine&);

#endif // MAGAZINE_H_INCLUDED
