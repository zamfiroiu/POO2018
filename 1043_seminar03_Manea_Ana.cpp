#include<iostream>
#include<string>
using namespace std;

class Cladire   //definim o clasa
{
public:         // incepe zona publica
	int nrEtaje;
//private:     /incepe zona privata
	string  adresa;
//protected:         // incepe zona pretected
	float suprafata;

	void afisare()
	{
		cout << "O cladire cu " << nrEtaje << " etaje si o suprafata de " << suprafata << " m2 se afla in " << adresa << endl;
	}

	//Metoda ce va modifica suprafata
	void maresteSuprafata(float x)
	{
		this->suprafata += x;
	}

};

void afisare(Cladire c)
{
	cout << "La adresa " << c.adresa << " este o cladire de " << c.nrEtaje << " etaje cu o suprafata de " << c.suprafata << " metri." << endl;
}
void main()
{
	Cladire c; //am declarat o instanta a clasei Cladire
	// Cladire c2;
	c.nrEtaje = 4;
	c.adresa = "Romana";
	c.suprafata = 200;

	Cladire * pc; //pointer
	pc = new Cladire(); // se apeleaza o metoda constructor care va crea acel obiect
	(*pc).nrEtaje = 10;  // deferentiem adresa si accesam nrEtaje
	pc->adresa = "Victoriei"; // "->" = deferentiere si accesare atribut
	pc->suprafata = 400;

	//Cladire * pc2 = &pc; //adresa la care se afla pc
	//Cladire *pc2 = *c; // se duce la adresa pe care o contine c, dar acesta nu e pointer
	Cladire *pc2 = pc;
	Cladire * pc3 = &c; // obtine adresa lui c si o pune in pc

	afisare(c);
	afisare(*pc);

	c.afisare();
	pc->afisare();

	c.maresteSuprafata(20);
	c.afisare();

	Cladire *vector;
	int n = 3;
	vector = new Cladire[n]; // se va apela de n ori constructorul fara parametrii
	for (int i = 0; i < n; i++)
	{
		vector[i].adresa = "Universitate";
		vector[i].nrEtaje = (i+1)*2;
		vector[i].suprafata = 100*(i+1);
	}

	for (int i = 0; i < n; i++)
	{
		vector[i].afisare();
	}

	//trebuie sa stergem memoria alocata.

}