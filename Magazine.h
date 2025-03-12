#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED

#include "Document.h"
#include<string>
using namespace std;

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

#endif // MAGAZINE_H_INCLUDED
