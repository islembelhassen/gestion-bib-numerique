#include "Personne.h"
#include "Date.h"

#include"Document.h"
#include"Livre.h"
#include"LivreAudio.h"
#include"Magazine.h"
#include"RechercheScientifique.h"

Personne::Personne()
    : nom(""), prenom(""), email(""), tel(0),datenaissance() {}

Personne::Personne(string n, string p, Date d, string e, int t)
    : nom(n), prenom(p), datenaissance(d), email(e), tel(t) {}

Personne::Personne(const Personne& p){
   nom=p.nom;
   prenom=p.prenom;
   email=p.email;
   tel=p.tel;
   datenaissance=p.datenaissance;

    Document* d;
    for (int i=0 ; i<p.documents.size() ; i++) {
        d=NULL;
        if(typeid(p.documents[i])==typeid(Livre)) d=new Livre( static_cast<const Livre&>(*p.documents[i]) );
        else if  (typeid(p.documents[i])==typeid(Magazine)) d=new Magazine( static_cast<const Magazine&>(*p.documents[i]) );
             else if (typeid(p.documents[i])==typeid(LivreAudio)) d=new LivreAudio( static_cast<const LivreAudio&>(*p.documents[i]) );
                  else if (typeid(p.documents[i])==typeid(RechercheScientifique)) d=new RechercheScientifique( static_cast<const RechercheScientifique&>(*p.documents[i]) );
        documents.push_back(d);
    }

}
void Personne::saisir() {
    cout << " Saisie des informations de la personne:" << endl;
    cout << "  Nom: ";
    cin>>nom;
    cout<< "  Prenom: " ;
    cin>> prenom;
    cout<< "  Date de naissance: "<<endl ;
    datenaissance.saisir();
    cout << "  Email: ";
    cin>> email;
    cout << "  Tel: ";
    cin>> tel;

    int choix=0;
    cout<<"  Les documents:"<<endl;
    while (true){
        cout<<"   choisir type document: "<<endl;
        cout << "    1 --> Livre" << endl;
        cout << "    2 --> Recherche Scientifique" << endl;
        cout << "    3 --> Magazine" << endl;
        cout << "    4 --> Livre Audio" << endl;
        cout << "    0 --> Quitter" << endl;
        cin >> choix;
        cin.ignore();
        if (choix == 0) {
            break;
        }

        Document* doc = NULL;
            switch (choix){
                case 1: doc = new Livre; break;
                case 2: doc = new RechercheScientifique; break;
                case 3: doc = new Magazine; break;
                case 4: doc = new LivreAudio; break;
                default: cout<<"choix invalide"<<endl; continue;
            }
    doc->saisir();
    documents.push_back(doc);
    }
    cout << " Fin saisie" << endl;

}

void Personne::afficher() {
    cout << "Affichage des informations de la personne:" << endl;
    cout << " Nom: " << nom<< endl;
    cout<< " Prenom: " << prenom << endl;
    cout<< " Date de naissance: "<<endl;
    datenaissance.afficher();
    cout<< " Email: " << email<< endl;
    cout<< " Tel: " << tel << endl;
    cout<<" Les documents:"<<endl;
    for (int i=0 ; i<this->documents.size() ; i++) {
            (this->documents[i])->afficher();
        }
    cout << "Fin affichage" << endl;
}

void Personne::set_nom(string n) { nom = n; }
void Personne::set_prenom(string p) { prenom = p; }
void Personne::set_email(string e) { email = e; }
void Personne::set_tel(int t) { tel = t; }
void Personne::set_datenaissance(Date d) { datenaissance = d; }

void Personne::ajouterDoc(Document* doc) { documents.push_back(doc); }
void Personne::supprimerDoc(string id) {
    for (int i = 0; i < documents.size(); i++ ) {
        if (documents[i]->get_id() == id) {
            delete documents[i];
            cout<<"document supprimme avec succes"<<endl;
            return;

        }
    }
    cout<<"document introuvable !"<<endl;

}

Personne::~Personne() {
    for (const Document* doc : documents) {
            delete doc;
        }
    documents.clear();
}




Personne& Personne::operator=(const Personne& p) {
    if (this != &p) {
        nom = p.nom;
        prenom = p.prenom;
        email = p.email;
        tel = p.tel;
        datenaissance = p.datenaissance;

        for (Document* doc : documents) {
            delete doc;
        }
        documents.clear();

        for (Document* doc : p.documents) {
            if (doc) {
                if (typeid(*doc) == typeid(Livre)) {
                    documents.push_back(new Livre(*static_cast<const Livre*>(doc)));
                }
                else if (typeid(*doc) == typeid(RechercheScientifique)) {
                    documents.push_back(new RechercheScientifique(*static_cast<const RechercheScientifique*>(doc)));
                }
                else if (typeid(*doc) == typeid(Magazine)) {
                    documents.push_back(new Magazine(*static_cast<const Magazine*>(doc)));
                }
                else if (typeid(*doc) == typeid(LivreAudio)) {
                    documents.push_back(new LivreAudio(*static_cast<const LivreAudio*>(doc)));
                }
            }
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const Personne& p) {
    os << "Nom: " << p.nom << "\n"
       << "Prenom: " << p.prenom << "\n"
       << "Email: " << p.email << "\n"
       << "Telephone: " << p.tel << "\n"
       << "Date naissance: " << p.datenaissance
       << p.documents.size() << "\n";

    for ( Document* doc : p.documents) {
        if (doc) {
            if(typeid(*doc) == typeid(Livre)) {
                os << "1" << endl << static_cast<Livre&>(*doc);
            }
            else if(typeid(*doc) == typeid(Magazine)) {
                os << "2" << endl << static_cast< Magazine&>(*doc);
            }

            else if (typeid(*doc) == typeid(RechercheScientifique)) {
                os << "3" << endl << static_cast< RechercheScientifique&>(*doc);
            }
            else if (typeid(*doc) == typeid(LivreAudio)) {
                os << "4" << endl << static_cast< LivreAudio&>(*doc);
            }
        }
    }
    return os;
}

istream& operator>>(istream& is, Personne& p) {
    for (Document* doc : p.documents) {
        delete doc;
    }
    p.documents.clear();

    cout << "Nom: ";
    getline(is, p.nom);

    cout << "Prenom: ";
    getline(is, p.prenom);

    cout << "Email: ";
    getline(is, p.email);

    cout << "Telephone: ";
    is >> p.tel;
    is.ignore();

    cout << "Date naissance: ";
    is >> p.datenaissance;


    char choix;
    do {
        cout << "Ajouter un document? (O/N): ";
        is >> choix;
        is.ignore();

        if (toupper(choix) == 'O') {
            cout << "Type de document:\n"
                 << "1- Livre\n"
                 << "2- Recherche Scientifique\n"
                 << "3- Magazine\n"
                 << "4- Livre Audio\n"
                 << "Choix: ";

            int typeDoc;
            is >> typeDoc;
            is.ignore();

            Document* doc = nullptr;
            switch(typeDoc) {
                case 1: doc = new Livre(); break;
                case 2: doc = new RechercheScientifique(); break;
                case 3: doc = new Magazine(); break;
                case 4: doc = new LivreAudio(); break;
                default: cout << "Type invalide!\n";
            }

            if (doc) {
                is >> *doc;
                p.documents.push_back(doc);
            }
        }
    } while (toupper(choix) == 'O');

    return is;
}




ostream& operator<<(ostream& o, const Personne* p) {
    o <<"nom: "<< p->nom << endl <<"prenom: "<< p->prenom << endl
      <<"date de naissance: " <<p->datenaissance <<"email: "<<  p->email << endl
      <<"tel: "<<  p->tel << endl << "nombre des documents: " <<p->documents.size() << endl;

    for( Document* doc : p->documents) {
        if(typeid(*doc) == typeid(Livre)) {
            o << "-livre" << endl << static_cast<Livre&>(*doc);
        }
        else if(typeid(*doc) == typeid(Magazine)) {
            o << "-magazine" << endl << static_cast< Magazine&>(*doc);
        }

        else if (typeid(*doc) == typeid(RechercheScientifique)) {
            o << "-recherche" << endl << static_cast< RechercheScientifique&>(*doc);
        }
        else if (typeid(*doc) == typeid(LivreAudio)) {
            o << "-livre audio" << endl << static_cast< LivreAudio&>(*doc);
        }
    }
    return o;
}

istream& operator>>(istream& i, Personne* p) {
    getline(i >> ws, p->nom);
    getline(i >> ws, p->prenom);
    i >> p->datenaissance;
    getline(i >> ws, p->email);
    i >> p->tel;

    int nbrDocuments;
    i>>nbrDocuments;

    int choix;
    while(nbrDocuments>0){
        i>>choix;
        if(i.eof()) break;
        if(choix==1)
        {
            Livre* l=new Livre();
            i>>*l;
            p->documents.push_back(l);
        }
        else if(choix==2)
        {
            Magazine* m=new Magazine();
            i>>*m;
            p->documents.push_back(m);
        }
        else if(choix==3)
        {
            LivreAudio* la=new LivreAudio();
            i>>*la;
            p->documents.push_back(la);
        }
        else if (choix==4)
        {
            RechercheScientifique* rs=new RechercheScientifique();
            i>>*rs;
            p->documents.push_back(rs);
        }
        nbrDocuments--;

    }
    return i;
}


