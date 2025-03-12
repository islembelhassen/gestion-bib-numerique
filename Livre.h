#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED
#include "Document.h"
#include <string>
using namespace std;

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

#endif // LIVRE_H_INCLUDED
