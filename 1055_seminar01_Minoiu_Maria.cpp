// 04 octombrie 2018
#include<iostream> //include biblioteca iostream
using namespace std; //incarca libraria std in codul sursa

struct profesor
{
	char* nume;  //char* retine adresa sirului de caractere
	int varsta;
	float salariu;

};
void afisare(profesor prof)
{
	cout << "Profesorul " << prof.nume << " are varsta de " << prof.varsta << " ani si un salariu de " << prof.salariu <<" euro"<< endl;
}
void functie(int* p)
{
	*p = 4;
}
void main()
{
	int var = 7;

	cout << var << endl;
	int* b = &var;
	cout << var << endl;
	cout << *b << endl; //* este operatorul de dereferentiere
	//b afiseaza o adresa si *b afiseaza valoarea lui var

	functie(&var);
	cout << "Dupa apel: " << var << endl;

	profesor prof;

	//prof.nume = (char*)malloc(sizeof(char)*(strlen("Ion")+1));  //se adauga 1 pt \0
	//se pune (char*) pt a transforma tipul de data returnata de malloc


	prof.nume = new char[strlen("Ion") + 1];
	//nu se mai pune (char*) pt ca new deja stie tipul

	strcpy(prof.nume, "Ion");
	prof.varsta = 45;
	prof.salariu = 1200;


	afisare(prof);//apelarea functiei





}
