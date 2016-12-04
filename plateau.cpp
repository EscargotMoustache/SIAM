#include "plateau.h"

using namespace std;

Plateau::Plateau()
{
    for (int i=0;i<5;i++)
    {
        std::vector <Case> ligne;
        for (int j=0;j<5;j++)
        {
            ligne.push_back(Case());
        }
        m_case.push_back(ligne);
    }
}

Plateau::~Plateau()
{

}

void Plateau::set_case(int x, int y, Animal *animal)
{
    this->m_case.at(x).at(y).set_animal(animal);
}

std::vector<std::vector<Case> > Plateau::get_plateau() const
{
    return m_case;
}
