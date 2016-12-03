#include "pion.h"

Pion::Pion()
{

}
Pion::Pion(std::string _nom,float _resistance, bool _actif)
{
    m_nom=_nom;
    m_resistance=_resistance;
    m_actif=_actif;
}

Pion::~Pion()
{

}

std::string Pion::getnom() const
{
    return m_nom;
}
