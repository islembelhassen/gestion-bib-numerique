#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED
#include<string>
using namespace std;

class Audio{
protected:
    int duree;
    string type;
public:
    Audio(int=0,string="");
    virtual void saisir()=0;
    virtual void afficher();
    void set_duree(int);
    void set_type(string);
    int get_duree();
    string get_type();
    virtual ~Audio();
};

#endif // AUDIO_H_INCLUDED
