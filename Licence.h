#ifndef LICENCE_H_INCLUDED
#define LICENCE_H_INCLUDED

#include"Document.h"

class Licence{
    private:
        int numL;
        string titre;
        Document* doc;
        float TVA;
        float tot;

    public:
        Licence();
        Licence(int,string,Document*,float,float);
        float calculTot();
        void saisir();
        void afficher();
        void set_numL(int);
        void set_titre(string);
        void set_TVA(float);
        int get_numL();
        string get_titre();
        float get_TVA();
};

#endif // LICENCE_H_INCLUDED
