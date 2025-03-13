#include<iostream>
#include<string>
#include "Audio.h"
using namespace std;


Audio::Audio(int duree, string type)
{
    this->duree=duree;
    this->type=type;
}

void Audio::saisir()
{
    cout<<"Donner la duree"<<endl;
    cin>>duree;
    cout<<"Donner le type"<<endl;
    cin>>type;
}

void Audio::afficher()
{
    cout<<"La duree: "<<duree<<endl;
    cout<<"Le type: "<<type<<endl;
}

void Audio::set_duree(int duree)
{
    this->duree=duree;
}
void Audio::set_type(string type)
{
    this->type=type;
}

int Audio::get_duree()
{
    return duree;
}

string Audio::get_type()
{
    return type;
}

Audio::~Audio(){}
