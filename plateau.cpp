#include "plateau.h"

using namespace std;

Plateau::Plateau()
{

}
Plateau::~Plateau()
{

}
void Plateau::afficherPlateau(Plateau plat,std::vector<Animal> E,std::vector<Animal> R,Console*pConsole,int i)
{
    cout << "        A B C D E   "<<endl;
    cout << "     1  - - - - -   "<< endl;
    cout << "     2  - - - - -   "<< endl;
    cout << "     3  - - - - -   "<< endl;
    cout << "     4  - - - - -   "<< endl;
    cout << "     5  - - - - -   "<< endl;
    pConsole->gotoLigCol(1,1);
    for ( auto& elem : E)
    {
        cout << elem.getnom()<< endl << " " ;
    }
    pConsole->gotoLigCol(1,20);
    for ( auto& elem : R)
    {
        cout << elem.getnom()<< endl ;
        i=i+1;
        pConsole->gotoLigCol(1+i,20);
    }
    i=0;
}
