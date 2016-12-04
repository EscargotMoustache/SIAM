#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include "plateau.h"
#include "animal.h"
#include "joueur.h"
#include "partie.h"
using namespace std;


int main()
{
    vector <Animal> E_vect;
    vector <Animal> R_vect;
    Console*pConsole;
    Joueur jou;
    Partie part;
    int j=0;
    int tour=1;
    int* adresse_tour=&tour;
    int i=0;
    char x=0;
    int* choix;
    Plateau plat;
    for (int i=0;i<5;i++)
    {
        E_vect.push_back(Animal("E",1,false,1));
        R_vect.push_back(Animal("R",1,false,1));
    }

    part.menu(choix);
    //affichage(plat,E_vect,R_vect,pConsole,j);
   /* plat.afficherPlateau(plat,E_vect,R_vect,pConsole,i);
    pConsole->gotoLigCol(7,0);
    ///faut dire bonjour quand meme
    cout << "Hello world!" << endl;
*/
    do
    {
        cin >> x;
       /* cin >> choix;

        jou.entrerAnimal(E_vect,R_vect,adresse_tour);
        system("cls");
        plat.afficherPlateau(plat,E_vect,R_vect,pConsole,i);
        pConsole->gotoLigCol(7,0);*/
    }while(x!='o');

    pConsole->gotoLigCol(10,0);
    return 0;
}
