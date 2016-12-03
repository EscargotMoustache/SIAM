#include "animal.h"

Animal::Animal()
{

}
Animal::Animal(std::string _nom,float _resistance,bool _actif,float _force)
:Pion(_nom,_resistance,_actif),m_force(_force)
{

}
Animal::~Animal()
{

}
