#ifndef SERIEMAGAZINES_H_INCLUDED
#define SERIEMAGAZINES_H_INCLUDED
#include<map>
#include"Magazine.h"

class SerieMagazines{
map<string,Magazine> sm;
public:
    SerieMagazines();
    SerieMagazines(const SerieMagazines&);
    void saisir();
    void afficher();
    void ajouter_magazine();
    void supprimer_magazine(string);
    void compter_magazines();
    ~SerieMagazines();
};

#endif // SERIEMAGAZINES_H_INCLUDED
