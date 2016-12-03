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
void Joueur::entrerAnimal(vector<Animal>& E, vector<Animal>& R, int*tour)
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
