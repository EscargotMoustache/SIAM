#include "case.h"

Case::Case()
{
    m_animal = nullptr;
    m_montagne = nullptr;
}

Case::Case(int _x, int _y)
{
    m_x = _x;
    m_y = _y;
    m_animal = nullptr;
    m_montagne = nullptr;
}

Case::~Case()
{

}

void Case::set_animal(Animal *animal)
{
    m_animal = animal;
}

void Case::remove_animal()
{
    m_animal = nullptr;
}

Animal *Case::get_animal()
{
    return m_animal;
}

void Case::set_montagne(Pion *pion)
{
    m_montagne = pion;
}

void Case::remove_montagne()
{
    m_montagne = nullptr;
}

Pion *Case::get_montagne()
{
    return m_montagne;
}
