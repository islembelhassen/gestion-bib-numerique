#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin(string nom, string prenom, Date datenaissance, string email, int tel,
             string role, float salaire, Date datePriseFct, string id)
    : Personne(nom, prenom, datenaissance, email, tel),
      Role(role, salaire),
      date_prise_fct(datePriseFct),
      idA(id) {}


void Admin::set_idA(string id) {
    idA = id;
}

void Admin::set_date_prise_fct(Date date) {
    date_prise_fct = date;
}

string Admin::get_idA() {
    return idA;
}

Date Admin::get_date_prise_fct() {
    return date_prise_fct;
}


void Admin::ajouterLecteur(Lecteur* lecteur) {
    if (lecteur != NULL) {
        lecteurs.push_back(lecteur);
        cout << "Lecteur ajouté avec succès." << endl;
    }
}

void Admin::supprimerLecteur(string idLec) {
    for (auto it = lecteurs.begin(); it != lecteurs.end(); ++it) {
        if ((*it)->get_idLec()==idLec) {
            lecteurs.erase(it);
            cout << "Lecteur supprimé avec succès." << endl;
            return;
        }
    }
    cout << "Lecteur non trouvé." << endl;
}


void Admin::afficher() {
    cout << "\n=== Informations Administrateur ===" << endl;
    cout << "ID Admin: " << idA << endl;
    Personne::afficher();
    Role::afficher();
    cout << "Date de prise de fonction: ";
    date_prise_fct.afficher();
    cout << "\nListe des lecteurs gérés:" << endl;
    if (lecteurs.empty()) {
        cout << "Aucun lecteur géré." << endl;
    } else {
        for (const auto& lecteur : lecteurs) {
            if (lecteur != NULL) {
                lecteur->afficher();
                cout << "---------------------" << endl;
            }
        }
    }
}


void Admin::saisir() {
    cout << "Saisie des informations administrateur:" << endl;
    Personne::saisir();
    Role::saisir();
    cout << "ID Admin: ";
    cin >> idA;



    cout << "Date de prise de fonction: " << endl;
    date_prise_fct.saisir();
    char choix;
    cout << "Voulez-vous ajouter des lecteurs? (o/n): ";
    cin >> choix;

    while (tolower(choix) == 'o') {
        Lecteur* lecteur = new Lecteur();
        lecteur->saisir();
        lecteurs.push_back(lecteur);

        cout << "Ajouter un autre lecteur? (o/n): ";
        cin >> choix;
    }
}


Admin::~Admin() {
    for (auto lecteur : lecteurs) {
        if (lecteur != NULL) {
            delete lecteur;
        }
    }
    lecteurs.clear();
}



Admin& Admin::operator=(const Admin& a){
    if(this!=&a){

        Personne::operator=(a);
        Role::operator=(a);
        this->idA=a.idA;
        this->date_prise_fct=a.date_prise_fct;
        for (Lecteur* lecteur : this->lecteurs) {
            delete lecteur;
        }


        this->lecteurs.clear();
        for (Lecteur* lecteur : a.lecteurs){
            (this->lecteurs).push_back(new Lecteur(*lecteur));
        }

    }
    return *this;

}

ostream& operator<<(ostream& o,const Admin& admin){
    o << static_cast<const Personne&>(admin);
    o << static_cast<const Role&>(admin);


    o << "ID Admin: " << admin.idA << endl
       << "Date prise de fonction: " << admin.date_prise_fct <<endl
       << "Lecteurs:"<<endl;

    for (const Lecteur* lecteur : admin.lecteurs) {
        o<< "  - " << *lecteur<< endl;
    }

    return o;

}
istream& operator>>(istream& is,Admin& admin){
    is >> static_cast<Personne&>(admin);
    is >> static_cast<Role&>(admin);


    cout << "Entrez l'ID admin: ";
    is >> admin.idA;

    cout << "Entrez la date de prise de fonction: ";
    is >> admin.date_prise_fct;


    for (Lecteur* lecteur : admin.lecteurs) {
        delete lecteur;
    }
    admin.lecteurs.clear();


    char continuer;
    do {
        cout << "Ajouter un lecteur: ";

        Lecteur* lecteur = new Lecteur();
        is >> *lecteur;
        admin.lecteurs.push_back(lecteur);

        cout << "Ajouter un autre lecteur? (O/N): ";
        is >> continuer;

    } while (toupper(continuer) == 'O');

    return is;
}














void Admin::ouvrir_fichier(fstream& f) {
    f.open("admin.txt", ios::in | ios::out | ios::trunc);
    if (!f.is_open())
                        throw -1;

}

void Admin::fermer_fichier(fstream& f) {
    f.close();

}






ostream& operator<<(ostream& o, const Admin* a) {

    o << static_cast<const Personne*>(a);

    o << static_cast<const Role*>(a);


    o << "id: "<< a->idA << endl<<a->date_prise_fct
      <<"nombre lecteurs:"<< a->lecteurs.size() << endl;

    for(const Lecteur* lect : a->lecteurs) {
        o << *lect << endl;
    }
    return o;
}

istream& operator>>(istream& i, Admin* a) {

    i >> static_cast<Personne*>(a);
/*
    i >> static_cast<Role*>(a);

    i >> a->date_prise_fct;
    getline(i >> ws, a->idA);

    int nbLecteurs;
    i >> nbLecteurs;
    for(int j = 0; j < nbLecteurs; j++) {
        Lecteur* l = new Lecteur();
        i >> *l;
        a->lecteurs.push_back(l);
    }*/
    return i;
}

void Admin::ecriture_fichier(fstream& f) {
    cout << "----- ecriture Admin dans fichier -----" << endl;
    f << this << endl;
    cout<<"----- Fin ecriture Admin dans fichier -----"<<endl;
}

void Admin::lecture_fichier(fstream& f) {
    cout << "----- Lecture Admin depuis fichier -----" << endl;
    f.seekg(0);
    char str[100];
        while(1)
        {
        f.getline(str,100,'\n');
        if(f.eof()) break;
        cout<<str<<endl;
        }
    cout << "----- Fin Lecture Admin depuis fichier -----" << endl;
}
