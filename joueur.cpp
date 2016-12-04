#include "joueur.h"
#include <vector>
using namespace std;

Joueur::Joueur()
{

}
Joueur::Joueur(std::string _nom,std::vector<Animal> _animaux)
{
    m_nom=_nom;
    m_animaux=_animaux;
}

Joueur::~Joueur()
{

}

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
