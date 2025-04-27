#include"SerieLivres.h"
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

SerieLivres::SerieLivres(){}

SerieLivres::SerieLivres(const SerieLivres& sl)
{
    list<Livre>::const_iterator it;
    for(it=sl.s.begin();it!=sl.s.end();it++)
    {
        s.push_back(*it);
    }
}


void SerieLivres::saisir()
{
    int nbrl;
    cout<<"Combien de livres voulez-vous ajouter? "<<endl;
    cin>>nbrl;
    Livre l;
    for(int i=0;i<nbrl;i++)
    {
        cout<<"--------Saisie du livre------------"<<endl;
        cin>>l;
        s.push_back(l);
    }
    cout<<"Saisie de serie de livres terminee"<<endl;
}

void SerieLivres::afficher()
{
    if(s.empty())
    {
        cout<<"Serie de livres vide"<<endl;
        return;
    }
    cout<<"-------Affichage de la serie de livres---------"<<endl;
    list<Livre>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
}


void SerieLivres::ajouter_livre()
{
    cout<<"----------Ajout d'un livre-----------"<<endl;
    Livre l;
    cin>>l;
    s.push_back(l);
    cout<<"Livre ajoute!"<<endl;
}

void SerieLivres::supprimer_livre(string id)
{
    if(s.empty())
    {
        cout<<"Serie vide"<<endl;
        return;
    }
    list<Livre>::iterator it;
    for(it=s.begin();it!=s.end();)
    {
        if(it->get_id()==id)
        {
            it=s.erase(it);
            cout<<"Livre supprime"<<endl;
            return;
        }
        else ++it;
    }
}


void SerieLivres::rechercher_par_id(const string& id)
{
    auto it=find_if(s.begin(),s.end(),[&id](const Livre& l) {
        return l.get_id()==id;
    });

    if (it != s.end())
    {
        cout << "Livre trouve :\n" << *it << endl;
    }
    else
    {
        cout << "Aucun livre avec l'ID \"" << id << "\" n'a ete trouve." << endl;
    }
}

SerieLivres::~SerieLivres()
{
    s.clear();
}
