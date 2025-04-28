#include"SerieMagazines.h"
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

SerieMagazines::SerieMagazines()
{

}

SerieMagazines::SerieMagazines(const SerieMagazines& s)
{
    sm=s.sm;
}

void SerieMagazines::saisir()
{

    char rep;
    do
    {
        Magazine m;
        cin>>m;
        sm.insert(std::pair<string,Magazine>(m.get_id(),m));
        cout<<"Voulez-vous ajouter un autre magazine? ";
        cin>>rep;
    }while(rep=='o'||rep=='O');
}

void SerieMagazines::afficher()
{
    map<string,Magazine>::iterator it;
    for(it=sm.begin();it!=sm.end();++it)
    {
        cout<<(*it).first;
        it->second.afficher();
    }
}

void SerieMagazines::ajouter_magazine()
{
    Magazine* m=new Magazine;
    m->saisir();
    m->afficher();
    map<string,Magazine>::iterator it;
    for(it=sm.begin();it!=sm.end();++it)
    {
        if((it->second.get_id())==(m->get_id()))
            {cout<<"Le magazine existe deja"<<endl;
            return;}
    }
    sm.insert(std::pair<string,Magazine>(m->get_id(),*m));

}

void SerieMagazines::supprimer_magazine(string id)
{
    bool trouv=false;
    map<string,Magazine>::iterator it;
    for(it=sm.begin();it!=sm.end();++it)
    {
        if (it->second.get_id()==id)
        {
            sm.erase(it);
            cout<<"Magazine d'id: "<<id<<" est supprime."<<endl;
            trouv=true;
            break;
        }
    }
    if (!trouv)
    {
        cout<<"Magazine d'id "<<id<<" non trouve."<<endl;
    }
}

void SerieMagazines::compter_magazines()
{
        int c = std::count_if(sm.begin(), sm.end(), [](const pair<string, Magazine>&) {
        return true;
    });
    cout << "Nombre de magazines dans la serie : " << c << endl;
}

SerieMagazines::~SerieMagazines()
{
    sm.clear();
}
