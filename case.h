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
    Animal *m_animal;
public:
    Case();
    ~Case();
    void set_animal(Animal *animal);
    Animal *get_animal();
    void remove_animal();
};

#endif // CASE_H_INCLUDED
