#include<iostream>
#include<string>
using namespace std;

class Cladire {
public:
	int nrEtaje;
//private:
	string adresa;
//protected:
	float suprafata;

	void afisare() {
		cout << "O cladire cu" << nrEtaje << " etaje si o sprafata de " 
			<< suprafata << "m2 se afla in " << adresa << endl;
	}
	void maresteSuprafata(float x) {
		this->suprafata += x;
	}
};

void afisare(Cladire c) {
	cout << "La adresa " << c.adresa << " este o cladire de " 
		<< c.nrEtaje << " etaje si o suprafata de " << c.suprafata << endl;
}

void main() {
	Cladire c;
	//Cladire c2;
	c.nrEtaje = 4;
	c.adresa = "Romana";
	c.suprafata = 200;

	Cladire * pc;
	pc = new Cladire();
	(*pc).nrEtaje = 10;
	pc->adresa = "Victoriei";
	pc->suprafata = 400;

	//grile cu aceste lucruri
	Cladire * pc2 = pc;
	Cladire*pc3 = &c;

	afisare(c);
	afisare(*pc);

	c.afisare();
	pc->afisare();

	c.maresteSuprafata(20);
	c.afisare();

	Cladire *vector;
	int n = 3;
	vector = new Cladire[n];
	for (int i = 0; i < n; i++) {
		vector[i].adresa = "universitate";
		vector[i].nrEtaje = (i+1)*2;
		vector[i].suprafata = (i+1)*100;
	}

	for (int i = 0; i < n; i++) {
		vector[i].afisare();
	}

	//Cladire **vectPointeri;
	//trebuie sa adaugam stergerile

}