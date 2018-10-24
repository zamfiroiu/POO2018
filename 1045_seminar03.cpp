#include<iostream>
#include<string>

using namespace std;

class Erou {
public:
	string nume;
	int nivel;
	float viata;

	void cresteNivel() {
		this->nivel++;
	}

	void afisare() {
		cout << "Eroul " << nume << " are " << viata 
			<< " puncte viata si este nivelul: " << nivel << endl;
	}
};

void afisare(Erou e) {
	cout << e.nume << " este nivelul " << e.nivel 
		<< " si are " << e.viata << " viata." << endl;
}

void main() {
	Erou e;
	Erou e2;
	e.nivel = 2;
	e.nume = "EroulMeu";
	e.viata = 89;

	Erou* pe;
	pe = new Erou();
	(*pe).nivel = 3;
	pe->nume = "Harap-Alb";
	pe->viata = 95;

	afisare(e);
	afisare(*pe);

	Erou*pe2 = pe;
	Erou * pe3 = &e;

	e.afisare();
	pe->afisare();

	e.cresteNivel();

	e.afisare();

	Erou* ve;
	int n = 3;
	ve = new Erou[n];
	for (int i = 0; i < n; i++) {
		ve[i].nivel = i + 1;
		ve[i].nume = "Praslea";
		ve[i].viata = i + 45;
	}

	for (int i = 0; i< n; i++) {
		ve[i].afisare();
	}

	Erou* *vpe;
	vpe = new Erou*[n];
	for (int i = 0; i < n; i++) {
		vpe[i] = new Erou();
	}

	for (int i = 0; i < n; i++) {
		vpe[i]->nivel = i;
		vpe[i]->nume = "Batman";
		vpe[i]->viata = 99;
	}

	for (int i = 0; i < n; i++) {
		delete vpe[i];
	}
	delete[]vpe;
	delete[]ve;
	delete pe3;
}