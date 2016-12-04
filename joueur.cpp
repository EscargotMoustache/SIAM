#include "joueur.h"

using namespace std;

Joueur::Joueur()
{

}
Joueur::Joueur(string _nom)
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
    this->m_animaux.back().set_lig(x);
    this->m_animaux.back().set_col(y);

    plat.set_case(x, y, &this->m_animaux.back());

    this->m_animaux.pop_back();
}

vector<Animal> Joueur::get_animaux() const
{
    return m_animaux;
}

void Joueur::sortirAnimal(Animal* animal, Plateau& plat)
{
    plat.clear_case(animal->get_lig(), animal->get_col());

    m_animaux.push_back(*animal);
}

void Joueur::deplacerAnimal(Plateau& plat, Animal* animal, char orientation, int x, int y)
{
    plat.clear_case(animal->get_lig(), animal->get_col());
    plat.set_case(x, y, animal);
    animal->set_lig(x);
    animal->set_col(y);
}
