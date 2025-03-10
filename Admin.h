#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "Personne.h"
#include "Role.h"

class Admin : public Personne , public Role {
    private:
        DATE date_prise_fct;
        string idA;
        vector<Lecteur*> lecteurs;
    public:
        Admin(string, string, DATE, string,string, DATE,string);
        void set_idA(string);
        void set_date_prise_fct(DATE);
        string get_idA();
        DATE get_date_prise_fct();
        void ajouterLecteur(Lecteur*);
        void supprimerLecteur(Lecteur*);
        virtual void afficher();
        virtual void saisir();
        virtual ~Admin();
};



#endif // ADMIN_H_INCLUDED
