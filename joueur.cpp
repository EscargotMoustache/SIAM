#include "joueur.h"
#include <vector>
using namespace std;

Joueur::Joueur()
{

}

Joueur::~Joueur()
{

}

///ça marche pas donc je RQ :)
void Joueur::entrerAnimal(vector<Pion> E, vector<Pion> R, int*tour)
{
    if (*tour==1)
    {
        E.pop_back();
    }
    else
    {
        R.pop_back();
    }

}
