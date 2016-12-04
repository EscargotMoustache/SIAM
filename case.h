#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

// Headers du projet
#include "animal.h"

class Case
{
private:
    int m_x;
    int m_y;
    Animal*m_animal;
public:
    Case();
    ~Case();
};

#endif // CASE_H_INCLUDED
