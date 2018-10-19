#include <iostream>
#include <string>

using namespace std;

class Erou
{
public:
	string nume;
	int nivel;
	float viata;
	void CresteNivel()
	{
		this->nivel++;
	}
	void  afisare()
	{
		cout << "Eroul" << nume << "are" << viata << "puncte viata si este nivelul:" << nivel << endl;
	}
};
void afisare(Erou e)
{
	cout << e.nume << "Este nivelul" << e.nivel << "si are" << e.viata << "viata" << endl;
}

int main()
{
	Erou e;
	Erou e2; //instanta unei clase 
	e.nume = "EroulMeu";
	e.nivel = 2;
	e.viata = 89;
	Erou* pe;
	pe = new Erou(); //se apeleaza constructorul default
	(*pe).nivel = 3; //se creste prioritatea pointerului
	pe->nume = "Harap Alb";
	pe->viata = 95;
	afisare(e);
	afisare(*pe); //deferentiaza adresa
	Erou *pe2 = pe; //initializaeaza pe2 cu un obiect existent
	Erou* pe3 = &e;
	e.afisare(); //functie a clasei erou
	pe->afisare(); //metoda 
	e.CresteNivel();
	e.afisare();
	Erou *ve; //creaza un vector 
	int n = 3;
	ve = new Erou[n]; //aloca memorie pentru vector
	for (int i = 0; i < n; i++)
	{
		ve[i].nivel = i + 1;
		//ve->nivel=4; acceseaza doar primul element 
		ve[i].nume = "Prislea";
		ve[i].viata = i + 45;
	}
	for (int i = 0; i < n; i++)
	{
		ve[i].afisare; //apeleaza metoda 
	}
	Erou **vpe;//un vector de pointeri(sau pointeri la Erou)
	vpe = new Erou*[n];
	for (int i = 0; i < n; i++)
	{
		vpe[i] = new Erou();
	}
	for (int i = 0; i < n; i++)
	{
		vpe[i]->nivel = 1; //deferentiaza si acceseaza
		vpe[i]->nume = "Batman";
		vpe[i]->viata = 99;
	}
		vpe[i]->afiseaza;

		for (int i = 0; i < n; i++)
		{
			delete vpe[i];
		}
	delete[] vpe;//compilatorul urmeaza sa stearga o zona contigua de memorie
	delete[] ve;
}
