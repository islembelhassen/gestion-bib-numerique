#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<typeinfo>
#include<fstream>
#include<algorithm>
#include"BibNum.h"
#include"Document.h"
#include"Livre.h"
#include"Magazine.h"
#include"RechercheScientifique.h"
#include"LivreAudio.h"
#include"Chapitre.h"
#include"SerieLivres.h"
#include<limits>
#include"Date.h"
#include"Personne.h"
#include"Lecteur.h"
#include"Admin.h"
#include"Role.h"
#include"Licence.h"
#include"SerieMagazines.h"
using namespace std;

void gestionDocuments()
{
    BibNum b;
    cout<<"------------------------- 1.Gestion des documents -------------------------"<<endl;
    cout<<"------------Remplissage des donnees de la bibliotheque------------"<<endl;
    cin>>b;
    cout<<"------------Affichage des donnees de la bibliotheque--------------"<<endl;
    cout<<b;
    cout<<"-----------------------------------------------"<<endl;
    char rep;
    cout<<"Voulez-vous ajouter un document? ";
    cin>>rep;
    if(rep=='o'||rep=='O')
    {
        do
            {
                b.ajouter_doc();
                cout<<"Document ajoute!"<<endl;
                cout<<"Voulez-vous ajouter un autre document? ";
                cin>>rep;
            }while(rep=='o'||rep=='O');
    }
    cout<<"----Affichage des donnees de la bibliotheque apres ajout des documents-----"<<endl;
    cout<<b;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Voulez-vous supprimer un document? ";
    cin>>rep;
    if(rep=='o'||rep=='O')
    {
        do
            {
                string id;
                cout<<"Donner l'id du document a supprimer ";
                cin>>id;
                b.supprimer_doc(id);
                cout<<"Voulez-vous supprimer un autre document? ";
                cin>>rep;
            }while(rep=='o'||rep=='O');
    }
    cout<<"----Affichage des donnees de la bibliotheque apres suppression des documents-----"<<endl;
    cout<<b;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Voulez-vous enregistrer les donnees d'une bibliotheque dans un fichier? ";
    cin>>rep;
    if(rep=='o'||rep=='O')
    {
        BibNum b1;
        fstream f;

        b1.ecriture_fichier(f);
        b1.lecture_fichier(f);
    }
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Voulez-vous enregistrer les donnees d'un livre dans un fichier? ";
    cin>>rep;
    if(rep=='o'||rep=='O')
    {
        Livre l;
        fstream f;
        try{
        l.ecriture_fichier(f);
        l.lecture_fichier(f);}
        catch(Erreur)
        {
            cerr<<"Ouverture echouee"<<endl;
        }
    }
    cout<<"------------------------------------------------"<<endl;
    cout<<"Voulez-vous saisir une serie de livres? ";
    cin>>rep;
    if(rep=='o'||rep=='O')
    {
        SerieLivres s;
        cout<<"--------------Saisie d'une serie de livres-----------------"<<endl;
        s.saisir();
        cout<<"--------------Affichage d'une serie de livres--------------"<<endl;
        s.afficher();
        cout<<"Voulez-vous ajouter un livre? ";
        char rep1;
        cin>>rep1;
        if(rep1=='O'||rep1=='o')
        {
            s.ajouter_livre();
            cout<<"--------------Affichage d'une serie de livres apres ajout--------------"<<endl;
            s.afficher();
        }
        cout<<"Voulez-vous supprimer un livre? ";
        cin>>rep1;
        if(rep1=='O'||rep1=='o')
        {
            string id;
            cout<<"Donner l'id du livre a supprimer: ";
            cin>>id;
            s.supprimer_livre(id);
            cout<<"--------------Affichage d'une serie de livres apres suppression--------------"<<endl;
            s.afficher();
        }
        cout<<"Voulez-vous chercher un livre dans la serie? ";
        cin>>rep1;
        if(rep1=='O'||rep1=='o')
        {
            cout<<"Donner l'id du livre que vous cherchez: ";
            string id;
            cin>>id;
            s.rechercher_par_id(id);
        }
    }
    cout<<"------------------------------------------------"<<endl;
    cout<<"Voulez-vous saisir une serie de magazines? ";
    cin>>rep;
    if(rep=='o'||rep=='O')
    {
        SerieMagazines sm;
        cout<<"--------------Saisie d'une serie de magazines-----------------"<<endl;
        sm.saisir();
        cout<<"--------------Affichage d'une serie de magazines--------------"<<endl;
        sm.afficher();
        cout<<"------------------------------------------------"<<endl;
        sm.compter_magazines();
        cout<<endl;
        sm.ajouter_magazine();
        sm.afficher();
        sm.compter_magazines();
        cout<<endl;
        string t;
        cout<<"Donner l'id du magazine a supprimer: ";
        cin>>t;
        sm.supprimer_magazine(t);
        sm.afficher();
        sm.compter_magazines();
        cout<<endl;
    }
    cout<<"------------------------------------------------"<<endl;
    cout<<"Voulez-vous concatener deux chapitres? ";
    cin>>rep;
    if(rep=='o'||rep=='O')
    {
        Chapitre c1,c2;
        cout<<"Saisie du chapitre 1"<<endl;
        cin>>c1;
        cout<<"Saisie du chapitre 2"<<endl;
        cin>>c2;
        cout<<"Chapitre 1: "<<endl;
        cout<<c1;
        cout<<endl;
        cout<<"Chapitre 2: "<<endl;
        cout<<c2;
        cout<<endl;
        cout<<"Chapitre 3(concatenation des chapitres 1 et 2): "<<endl;
        cout<<c1+c2;
        cout<<endl;
    }

}

void gestionLicenses(map<int,Licence>& mesLicenses){
    int choix;
    char flag='o';
    do{
        cout<<"------------------------- 3.Gestion des licenses -------------------------"<<endl;
        cout<<"Veuillez selectionner une option parmi les suivantes :"<<endl;
        cout<<" 1.Ajouter licenses"<<endl;
        cout<<" 2.Supprimer licenses"<<endl;
        cout<<" 3.afficher les licenses"<<endl;
        cout<<" 4.rechercher une licence"<<endl;
        cout<<" 5.quitter"<<endl;
        cout<<"Votre choix : "<<endl;
        cin>>choix;
        switch(choix){
            case 1 :{
                      do{

                        Licence licence;
                        licence.saisir();
                        mesLicenses.emplace(licence.get_numL(), licence);

                        cout << "Ajouter une autre licence? (o/n): ";
                        cin >> flag;
                    }while (tolower(flag) == 'o');
                  break;
                }

            case 2 :{

                      int numl;
                      do{
                        cout<<"donner numero licence a supprimer: ";
                        cin>>numl;

                        mesLicenses.erase(numl);

                        cout << "supprimer une autre licence? (o/n): ";
                        cin >> flag;
                    }while (tolower(flag) == 'o');
                  break;
                }
            case 3:{
                cout<<"map de licenses ordonnée: "<<endl;
                map<int,Licence>::iterator it;
                for(it=mesLicenses.begin();it!=mesLicenses.end();it++) {
                    cout<<it->first;
                    (it->second).afficher();
                }
                break;

            }
            case 4: {
                int id;
                cout << "Donner l'ID de la licence: ";
                cin >> id;

                auto it = find_if(mesLicenses.begin(), mesLicenses.end(),
                    [&id](auto& pair) {
                        return pair.second.get_numL() == id;});

                if (it != mesLicenses.end()) {
                    cout << "Licence trouvee: ";
                    it->second.afficher();
                }
                else {
                    cout << "Licence non trouvee" << endl;
                }
                break;
            }
            case 5 : cout<<"quitter......"<<endl; break;
            default: cout<<"choix invalide !!"<<endl; break;

        }

    }while(choix!=5);

}



void gestionPersonnes(Admin& a){
    int choix;
    char flag='o';
    do{
        cout<<"------------------------- 2.Gestion des personnes -------------------------"<<endl;
        cout<<"Veuillez selectionner une option parmi les suivantes :"<<endl;
        cout<<" 1.Gestion ADMIN"<<endl;
        cout<<" 2.Gestion des lecteurs"<<endl;
        cout<<" 3.Ecriture et lecture depuis fichier administration"<<endl;
        cout<<" 4.quitter"<<endl;
        cout<<"Votre choix : "<<endl;
        cin>>choix;
        switch(choix){
            case 1 :{
                 if(a.get_idA()=="") a.saisir();

                 cout<<"Ajouter des nouveaux documents ? (o/n):"<<endl;
                 cin>>flag;
                         while (tolower(flag) == 'o') {
                                cout<<"  choisir type document: "<<endl;
                                cout << "   1 --> Livre" << endl;
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
                                        case 1: doc = new Livre; break;
                                        case 2: doc = new RechercheScientifique; break;
                                        case 3: doc = new Magazine; break;
                                        case 4: doc = new LivreAudio; break;
                                        default: cout<<"choix invalide"<<endl; continue;
                                    }
                                    doc->saisir();
                                    a.ajouterDoc(doc);

                            cout << "Ajouter un autre document? (o/n): ";
                            cin >> flag;
                        }


                 cout<<"Supprimer des documents ? (o/n):"<<endl;
                 cin>>flag;
                 string idDocument;
                     while (tolower(flag) == 'o') {
                        cout<<"donner id document a supprimer: "<<endl;
                        cin>>idDocument;
                        a.supprimerDoc(idDocument);

                     cout << "Supprimer un autre document? (o/n): ";
                     cin >> flag;
                     }


                 break;
                }

            case 2 :{
                 if(a.get_idA()=="") a.saisir();

                 cout<<"Ajouter des nouvelles lecteurs ? (o/n):"<<endl;
                 cin>>flag;
                         while (tolower(flag) == 'o') {
                            Lecteur* lecteur=new Lecteur();
                            lecteur->saisir();
                            a.ajouterLecteur(lecteur);

                            cout << "Ajouter un autre lecteur? (o/n): ";
                            cin >> flag;
                        }


                 cout<<"Supprimer des lecteurs ? (o/n):"<<endl;
                 cin>>flag;
                 string idLec;
                     while (tolower(flag) == 'o') {
                        cout<<"donner id lecteur a supprimer: "<<endl;
                        cin>>idLec;
                        a.supprimerLecteur(idLec);

                     cout << "Supprimer un autre lecteur? (o/n): ";
                     cin >> flag;
                     }


                 break;
                }
            case 3 :{
                    if(a.get_idA()=="") a.saisir();


                    fstream f;
                    try{
                        a.ouvrir_fichier(f);
                        a.ecriture_fichier(f);
                        a.lecture_fichier(f);
                        a.fermer_fichier(f);
                    }
                    catch(Erreur)
                    {
                        cerr<<"Ouverture echouee"<<endl;
                    }


                break;
            }
            case 4 : cout<<"quitter......"<<endl;break;
            default: cout<<"choix invalide !!"<<endl; break;
        }

    }while(choix!=4);


}


void menu()
{
    cout<<"Choisir l'une des options suivantes:"<<endl;
    cout<<"1. Gestion des documents de la bibliotheque numerique"<<endl;
    cout<<"2. Gestion des personnes"<<endl;
    cout<<"3. Gestion des licences"<<endl;
    cout<<"4. Quitter"<<endl;
}

int main()
{
    int choix;
    Admin a;
    map<int,Licence> mesLicenses;
    do
        {
            menu();
            cin>>choix;
            switch(choix)
            {
                case 1: gestionDocuments(); break;
                case 2: gestionPersonnes(a); break;
                case 3 : gestionLicenses(mesLicenses); break;
                case 4: cout<<"Quitter le programme..."<<endl;break;
                default: cout<<"Choic invalide!"<<endl;break;
            }
        }while(choix!=4);


    return 0;
}
