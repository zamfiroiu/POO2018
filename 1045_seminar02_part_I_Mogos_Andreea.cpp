#include <iostream>
#include <string>
using namespace std;
void main()
{ string sir="Seminar 2";
sir="seminar 2"; //modifica numele
sir.append("-pointeri"); //functie de adaugare
cout <<sir<<endl;
cout<<sir.substr(sir.find('-')+1,8)<<endl;//prima funct afiseaza un subsir
//a doua functie cauta un sir
//are ca parametri de unde incepe si dimensiunea
}