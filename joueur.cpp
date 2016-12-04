#include "joueur.h"
#include <vector>
using namespace std;

Joueur::Joueur()
{

}
Joueur::Joueur(std::string _nom)
{
    for (int i=0;i<5;i++)
    {
        m_animaux.push_back(Animal(_nom,1,false,1));
        //R_vect.push_back(Animal("R",1,false,1));
    }
}

Joueur::~Joueur()
{

}

void Joueur::entrerAnimal()
{
        this->m_animaux.pop_back();
}
std::vector<Animal> Joueur::getanimaux() const
{
    return m_animaux;
}
