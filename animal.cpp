#include "animal.h"

Animal::Animal()
{

}

Animal::Animal(std::string _nom, float _resistance, bool _actif, float _force)
    : Pion(_nom, _resistance, _actif), m_force(_force)
{

}

Animal::~Animal()
{

}

char Animal::get_dir() const
{
    return m_direction;
}

void Animal::set_dir(char direction)
{
    m_direction = direction;
}

float Animal::get_force(char direction) const
{
    if (direction == get_dir())
        return m_force;
    else
        return 0.f;
}

