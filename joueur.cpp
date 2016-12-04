#include "joueur.h"

using namespace std;

Joueur::Joueur()
{

}
Joueur::Joueur(std::string _nom)
{
    for (int i=0;i<5;i++)
    {
        m_animaux.push_back(Animal(_nom, 1, false, 1));
    }
}

Joueur::~Joueur()
{

}

void Joueur::entrerAnimal(Plateau& plat, char orientation, int x, int y)
{
    this->m_animaux.back().set_dir(orientation);

    plat.set_case(x, y, &this->m_animaux.back());

    this->m_animaux.pop_back();
}

std::vector<Animal> Joueur::get_animaux() const
{
    return m_animaux;
}
