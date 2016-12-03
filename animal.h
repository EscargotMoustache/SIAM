#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include "includes.h"

class Animal : public Pion {
private:
    char m_direction;
    float m_force;

public:
    Animal();
    ~Animal();
    void entrer();
    void deplacer();
    void orienter();
    void pousser();
    void sortir();
};

#endif // ANIMAL_H_INCLUDED
