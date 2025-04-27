#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "Personne.h"
#include "Role.h"
#include"Lecteur.h"
#include <fstream>

class Admin : public Personne , public Role {
    private:
        Date date_prise_fct;
        string idA;
        vector<Lecteur*> lecteurs;
    public:
        Admin(string="",string="", Date=Date(),string="",int=0,string="", float=0.0,Date=Date(),string="");
        void set_idA(string);
        void set_date_prise_fct(Date);
        string get_idA();
        Date get_date_prise_fct();
        void ajouterLecteur(Lecteur*);
        void supprimerLecteur(string);
        virtual void afficher();
        virtual void saisir();
        virtual ~Admin();

        Admin& operator=(const Admin&);
        friend ostream& operator<<(ostream&,const Admin&);
        friend istream& operator>>(istream&,Admin&);

        static void ouvrir_fichier(fstream&);
        static void fermer_fichier(fstream&);
        void ecriture_fichier(fstream&);
        void lecture_fichier(fstream&);
        friend ostream& operator<<(ostream&, const Admin*);
        friend istream& operator>>(istream&, Admin*);
};



#endif // ADMIN_H_INCLUDED
