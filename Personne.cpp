#include "Personne.h"
#include "Date.h"

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


    for (Document* doc : p.documents) {
        Document documentaux(*doc);
        documents.push_back(&documentaux);
    }

}
void Personne::saisir() {
    cout << "Saisie des informations de la personne:" << endl;
    cout << " Nom: ";
    cin>>nom;
    cout<< " Prenom: " ;
    cin>> prenom;
    cout<< " Date de naissance: "<<endl ;
    datenaissance.saisir();
    cout << " Email: ";
    cin>> email;
    cout << " Tel: ";
    cin>> tel;

    int choix=0;
    cout<<" Les documents:"<<endl;
    while (true){
        cout<<"  choisir type document: "<<endl;
        cout << "   1 --> Livre" << sendl;
        cout << "   2 --> Recherche Scientifique" << endl;
        cout << "   3 --> Magazine" << endl;
        cout << "   4 --> Livre Audio" << endl;
        cout << "   0 --> Quitter" << endl;
        cin >> choix;
        cin.ignore();
        if (choix == 0) {
            break;
        }

        Document* doc = NULL;
            switch (choix){
                case 1: doc = new Livre(); break;
                case 2: doc = new RechercheScientifique(); break;
                case 3: doc = new Magazine(); break;
                case 4: doc = new LivreAudio(); break;
                default: cout<<"choix invalide"<<endl; continue;
            }
    doc->saisir();
    documents.push_back(doc);
    }
    cout << "Fin saisie" << endl;

}

void Personne::afficher() {
    cout << "Affichage des informations de la personne:" << endl;
    cout << " Nom: " << nom<< endl;
    cout<< " Prenom: " << prenom << endl;
    cout<< " Date de naissance: "<<;
    datenaissance.afficher();
    cout<< " Email: " << email<< endl;
    cout<< " Tel: " << tel << endl;
    cout<<" Les documents:"<<endl;
    for (const Document* doc : documents) {
            doc->afficher();
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
    for (size_t i = 0; i < documents.size(); ) {
        if (documents[i]->get_id() == id) {
            delete documents[i];
            documents.erase(documents.begin() + i);
            cout<<"document supprimme avec succes"<<endl;
        } else {
             i++;
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
