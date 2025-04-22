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
    friend ostream& operator<<(ostream&,Audio&);
    friend istream& operator>>(istream&,Audio&);
    virtual ~Audio();
}; ostream& operator<<(ostream&,Audio&);
   istream& operator>>(istream&,Audio&);



#endif // AUDIO_H_INCLUDED
