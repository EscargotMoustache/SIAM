#include "case.h"

Case::Case()
{
    m_animal = nullptr;
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
