#include "pion.h"

Pion::Pion()
{

}
Pion::Pion(std::string _nom)
{
    m_nom=_nom;
}

Pion::~Pion()
{

}

std::string Pion::getnom() const
{
    return m_nom;
}
