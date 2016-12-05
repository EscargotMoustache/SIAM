#include "joueur.h"

using namespace std;

Joueur::Joueur()
{

}
Joueur::Joueur(string _nom)
{
    m_nom = _nom;

    for (int i=0;i<5;i++)
    {
        m_animaux.push_back(Animal(_nom, 1, false, 1));
    }

    m_victoire = false;
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

bool Joueur::get_victoire() const
{
    return m_victoire;
}

string Joueur::get_nom() const
{
    return m_nom;
}

void Joueur::orienterAnimal(Animal* animal, char orientation)
{
    animal->set_dir(orientation);
}

bool Joueur::pousserAnimal(Animal* animal, Plateau& plat)
{
    int x = animal->get_col();
    int y = animal->get_lig();
    vector<vector<Case> > cases = plat.get_plateau();
    float force = 0.f;
    float resistance = 0.f;
    int x_pousse, y_pousse;
    int x_max, y_max;
    bool pousse = false;

    switch(animal->get_dir())
    {
    case 'h':
        x_pousse = animal->get_col();
        y_pousse = animal->get_lig() - 1;
        y_max = 0;

        for (int i = animal->get_lig(); i >= 0; i--)
        {
            if (cases.at(i).at(x).get_animal() != nullptr && cases.at(i).at(x).get_animal()->get_dir() != 'b' && cases.at(i).at(x).get_montagne() == nullptr)
            {
                force += cases.at(i).at(x).get_animal()->get_force('h');
            }
            else if (cases.at(i).at(x).get_animal() == nullptr && cases.at(i).at(x).get_montagne() == nullptr)
            {
                y_max = i + 1;
                break;
            }
            else if (cases.at(i).at(x).get_montagne() != nullptr || (cases.at(i).at(x).get_animal() != nullptr && cases.at(i).at(x).get_animal()->get_dir() == 'b'))
            {
                y_pousse = i;
                y_max = i;
                break;
            }
        }

        for (int i = y_pousse; i >= y_max; i--)
        {
            if (cases.at(i).at(x).get_montagne() != nullptr)
                resistance += 0.9f;
            else if (cases.at(i).at(x).get_animal() != nullptr)
            {
                if (cases.at(i).at(x).get_animal()->get_dir() == 'b')
                    resistance += 1.0f;
            }
            else
            {
                break;
            }
        }

        if (force > resistance)
        {
            for (int i = y_max; i < 5; i++)
            {
                if (cases.at(i).at(x).get_montagne() != nullptr)
                {
                    if (i - 1 >= 0)
                    {
                        plat.set_case(i - 1, x, cases.at(i).at(x).get_montagne());
                        cases.at(i).at(x).get_montagne()->set_lig(i - 1);
                        cases.at(i).at(x).get_montagne()->set_col(x);
                    }
                    else
                    {
                        m_victoire = true;
                    }
                    plat.clear_case(y, i);
                }
                else if (cases.at(i).at(x).get_animal() != nullptr)
                {
                    if (i - 1 >= 0)
                    {
                        plat.set_case(i - 1, x, cases.at(i).at(x).get_animal());
                        cases.at(i).at(x).get_animal()->set_lig(i - 1);
                        cases.at(i).at(x).get_animal()->set_col(x);
                    }
                    else
                    {
                        m_animaux.push_back(*cases.at(i).at(x).get_animal());
                    }
                    plat.clear_case(i, x);
                }
                else
                {
                    break;
                }
            }
            pousse = true;
        }
        else
        {
            cout << "Pas assez de force pour pousser !" << endl;
        }
        break;
    case 'b':
        x_pousse = animal->get_col();
        y_pousse = animal->get_lig() + 1;
        y_max = 4;

        for (int i = animal->get_lig(); i < 5; i++)
        {
            if (cases.at(i).at(x).get_animal() != nullptr && cases.at(i).at(x).get_animal()->get_dir() != 'h' && cases.at(i).at(x).get_montagne() == nullptr)
            {
                force += cases.at(i).at(x).get_animal()->get_force('b');
            }
            else if (cases.at(i).at(x).get_animal() == nullptr && cases.at(i).at(x).get_montagne() == nullptr)
            {
                y_max = i - 1;
                break;
            }
            else if (cases.at(i).at(x).get_montagne() != nullptr || (cases.at(i).at(x).get_animal() != nullptr && cases.at(i).at(x).get_animal()->get_dir() == 'h'))
            {
                y_pousse = i;
                y_max = i;
                break;
            }
        }

        for (int i = y_pousse; i <= y_max; i++)
        {
            if (cases.at(i).at(x).get_montagne() != nullptr)
                resistance += 0.9f;
            else if (cases.at(i).at(x).get_animal() != nullptr)
            {
                if (cases.at(i).at(x).get_animal()->get_dir() == 'h')
                    resistance += 1.0f;
            }
            else
            {
                break;
            }
        }

        cout << y_max << endl << y_pousse << endl;

        if (force > resistance)
        {
            for (int i = y_max; i >= 0; i--)
            {
                if (cases.at(i).at(x).get_montagne() != nullptr)
                {
                    if (i + 1 < 5)
                    {
                        plat.set_case(i + 1, x, cases.at(i).at(x).get_montagne());
                        cases.at(i).at(x).get_montagne()->set_lig(i + 1);
                        cases.at(i).at(x).get_montagne()->set_col(x);
                    }
                    else
                    {
                        m_victoire = true;
                    }
                    plat.clear_case(y, i);
                }
                else if (cases.at(i).at(x).get_animal() != nullptr)
                {
                    if (i + 1 < 5)
                    {
                        plat.set_case(i + 1, x, cases.at(i).at(x).get_animal());
                        cases.at(i).at(x).get_animal()->set_lig(i + 1);
                        cases.at(i).at(x).get_animal()->set_col(x);
                    }
                    else
                    {
                        m_animaux.push_back(*cases.at(i).at(x).get_animal());
                    }
                    plat.clear_case(i, x);
                }
                else
                {
                    break;
                }
            }
            pousse = true;
        }
        else
        {
            cout << "Pas assez de force pour pousser !" << endl;
        }
        break;
    case 'd':
        x_pousse = animal->get_col() + 1;
        y_pousse = animal->get_lig();
        x_max = 4;

        for (int i = animal->get_col(); i < 5; i++)
        {
            if (cases.at(y).at(i).get_animal() != nullptr && cases.at(y).at(i).get_animal()->get_dir() != 'g' && cases.at(y).at(i).get_montagne() == nullptr)
            {
                force += cases.at(y).at(i).get_animal()->get_force('d');
            }
            else if (cases.at(y).at(i).get_animal() == nullptr && cases.at(y).at(i).get_montagne() == nullptr)
            {
                x_max = i - 1;
                break;
            }
            else if (cases.at(y).at(i).get_montagne() != nullptr || (cases.at(y).at(i).get_animal() != nullptr && cases.at(y).at(i).get_animal()->get_dir() == 'g'))
            {
                x_pousse = i;
                x_max = i;
                break;
            }
        }

        for (int i = x_pousse; i <= x_max; i++)
        {
            if (cases.at(y).at(i).get_montagne() != nullptr)
                resistance += 0.9f;
            else if (cases.at(y).at(i).get_animal() != nullptr)
            {
                if (cases.at(y).at(i).get_animal()->get_dir() == 'g')
                    resistance += 1.0f;
            }
            else
            {
                break;
            }
        }

        if (force > resistance)
        {
            cout << x_max << endl << x_pousse << endl;

            for (int i = x_max; i >= 0; i--)
            {
                if (cases.at(y).at(i).get_montagne() != nullptr)
                {
                    if (i + 1 < 5)
                    {
                        plat.set_case(y, i + 1, cases.at(y).at(i).get_montagne());
                        cases.at(y).at(i).get_montagne()->set_col(i + 1);
                        cases.at(y).at(i).get_montagne()->set_lig(y);
                    }
                    else
                    {
                        m_victoire = true;
                    }
                    plat.clear_case(y, i);
                }
                else if (cases.at(y).at(i).get_animal() != nullptr)
                {
                    if (i + 1 < 5)
                    {
                        plat.set_case(y, i + 1, cases.at(y).at(i).get_animal());
                        cases.at(y).at(i).get_animal()->set_lig(y);
                        cases.at(y).at(i).get_animal()->set_col(i + 1);
                    }
                    else
                    {
                        m_animaux.push_back(*cases.at(y).at(i).get_animal());
                    }
                    plat.clear_case(y, i);
                }
                else
                {
                    break;
                }
            }
            pousse = true;
        }
        else
        {
            cout << "Pas assez de force pour pousser !" << endl;
        }

        break;
    case 'g':
        x_pousse = animal->get_col() - 1;
        y_pousse = animal->get_lig();
        x_max = 0;

        for (int i = animal->get_col(); i >= 0; i--)
        {
            if (cases.at(y).at(i).get_animal() != nullptr && cases.at(y).at(i).get_animal()->get_dir() != 'd' && cases.at(y).at(i).get_montagne() == nullptr)
            {
                force += cases.at(y).at(i).get_animal()->get_force('g');
            }
            else if (cases.at(y).at(i).get_animal() == nullptr && cases.at(y).at(i).get_montagne() == nullptr)
            {
                x_max = i + 1;
                break;
            }
            else if (cases.at(y).at(i).get_montagne() != nullptr || (cases.at(y).at(i).get_animal() != nullptr && cases.at(y).at(i).get_animal()->get_dir() == 'd'))
            {
                x_pousse = i;
                x_max = i;
                break;
            }
        }

        for (int i = x_pousse; i >= x_max; i--)
        {
            if (cases.at(y).at(i).get_montagne() != nullptr)
                resistance += 0.9f;
            else if (cases.at(y).at(i).get_animal() != nullptr)
            {
                if (cases.at(y).at(i).get_animal()->get_dir() == 'd')
                    resistance += 1.0f;
            }
            else
            {
                break;
            }
        }

        if (force > resistance)
        {
            for (int i = x_max; i >= 0; i--)
            {
                if (cases.at(y).at(i).get_montagne() != nullptr)
                {
                    if (i - 1 >= 0)
                    {
                        plat.set_case(y, i - 1, cases.at(y).at(i).get_montagne());
                        cases.at(y).at(i).get_montagne()->set_col(i - 1);
                        cases.at(y).at(i).get_montagne()->set_lig(y);
                    }
                    else
                    {
                        m_victoire = true;
                    }
                    plat.clear_case(y, i);
                }
                else if (cases.at(y).at(i).get_animal() != nullptr)
                {
                    if (i - 1 >= 0)
                    {
                        plat.set_case(y, i - 1, cases.at(y).at(i).get_animal());
                        cases.at(y).at(i).get_animal()->set_lig(y);
                        cases.at(y).at(i).get_animal()->set_col(i - 1);
                    }
                    else
                    {
                        m_animaux.push_back(*cases.at(y).at(i).get_animal());
                    }
                    plat.clear_case(y, i);
                }
                else
                {
                    break;
                }
            }
            pousse = true;
        }
        else
        {
            cout << "Pas assez de force pour pousser !" << endl;
        }

        break;
    default:
        break;
    }

    return pousse;
}
