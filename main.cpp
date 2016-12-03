#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include "plateau.h"
#include "animal.h"
using namespace std;

void affichage (Plateau plat,vector<Pion> E, vector<Pion> R, Console*Console,int i)
{
    plat.afficherPlateau();

    Console->gotoLigCol(1,1);
    for ( auto& elem : E)
    {
        cout << elem.getnom()<< endl << " " ;
    }
    Console->gotoLigCol(1,20);
    for ( auto& elem : R)
    {
        cout << elem.getnom()<< endl ;
        i=i+1;
        Console->gotoLigCol(1+i,20);
    }
    i=0;
}
int main()
{
    vector <Pion> E_vect;
    vector <Pion> R_vect;
    Console*pConsole;
    int i=0;
    char choix;
    Plateau plat;
    for (int i=0;i<5;i++)
    {
        E_vect.push_back(Animal("E"));
        R_vect.push_back(Animal("R"));
    }

    affichage(plat,E_vect,R_vect,pConsole,i);
    pConsole->gotoLigCol(7,0);
    cout << "Hello world!" << endl;
    cin >> choix;

    if (choix=='a')
    {
        E_vect.pop_back();
        system("cls");
    }
    affichage(plat,E_vect,R_vect,pConsole,i);
    return 0;
}
