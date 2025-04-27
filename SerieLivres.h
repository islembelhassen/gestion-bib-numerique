#ifndef SERIELIVRES_H_INCLUDED
#define SERIELIVRES_H_INCLUDED
#include<list>
#include"Livre.h"

class SerieLivres{
list<Livre>s;
public:
    SerieLivres();
    SerieLivres(const SerieLivres&);
    void saisir();
    void afficher();
    void ajouter_livre();
    void supprimer_livre(string);
    void rechercher_par_id(const string&);

    ~SerieLivres();

};


#endif // SERIELIVRES_H_INCLUDED
