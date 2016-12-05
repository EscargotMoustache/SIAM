#include "plateau.h"

using namespace std;

Plateau::Plateau()
{
    for (int i=0;i<5;i++)
    {
        vector <Case> ligne;
        for (int j=0;j<5;j++)
        {
            ligne.push_back(Case(j, i));
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

void Plateau::set_case(int x, int y, Pion *pion)
{
    this->m_case.at(x).at(y).set_montagne(pion);
}

void Plateau::clear_case(int x, int y)
{
    this->m_case.at(x).at(y).remove_animal();
    this->m_case.at(x).at(y).remove_montagne();
}

vector<vector<Case> > Plateau::get_plateau() const
{
    return m_case;
}

bool Plateau::is_case_surrounded(int x, int y)
{
    bool surrounded = false;

    if (y > 0 && (this->m_case.at(y - 1).at(x).get_animal() != nullptr || this->m_case.at(y - 1).at(x).get_montagne() != nullptr))
    {
        surrounded = true;
    }
    if (y < 4 && (this->m_case.at(y + 1).at(x).get_animal() != nullptr || this->m_case.at(y + 1).at(x).get_montagne() != nullptr))
    {
        surrounded = true;
    }
    if (x > 0 && (this->m_case.at(y).at(x - 1).get_animal() != nullptr || this->m_case.at(y).at(x - 1).get_montagne() != nullptr))
    {
        surrounded = true;
    }
    if (x < 4 && (this->m_case.at(y).at(x + 1).get_animal() != nullptr || this->m_case.at(y).at(x + 1).get_montagne() != nullptr))
    {
        surrounded = true;
    }

    return surrounded;
}
