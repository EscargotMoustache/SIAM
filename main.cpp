#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include "plateau.h"
#include "animal.h"
#include "joueur.h"
using namespace std;

///sous programme pour afficher le plateau avec les pions
///je sais pas s'il faut le faire directement avec la méthode
/// le i sert juste à les afficher les uns en dessous des autres
void affichage (Plateau plat,vector<Animal> E, vector<Animal> R, Console*Console,int i)
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
    vector <Animal> E_vect;
    vector <Animal> R_vect;
    Console*pConsole;
    Joueur jou;
    int j=0;
    int tour=1;
    int* adresse_tour=&tour;
    int i=0;
    char choix;
    Plateau plat;
    for (int i=0;i<5;i++)
    {
        E_vect.push_back(Animal("E",1,false,1));
        R_vect.push_back(Animal("R",1,false,1));
    }

    affichage(plat,E_vect,R_vect,pConsole,j);
    pConsole->gotoLigCol(7,0);
    ///faut dire bonjour quand meme
    cout << "Hello world!" << endl;

    do
    {
        cin >> choix;
        /// là je comprend pas pourquoi quand je le fais avec la méthode
        ///ça marche pas, alors que si je si pop direct, ça marche
        jou.entrerAnimal(E_vect,R_vect,adresse_tour);
        //E_vect.pop_back();

        ///on clear la console et on réaffiche le plateau +pions
        /// qui ont dégagés du vecteur
        system("cls");
        affichage(plat,E_vect,R_vect,pConsole,j);
        pConsole->gotoLigCol(7,0);
    }while(choix!='1');

    pConsole->gotoLigCol(10,0);
    return 0;
}
