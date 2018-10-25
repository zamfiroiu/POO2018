#include<iostream>
#include<string>

using namespace std;

class Apartament {

private:

	static double tva;
public:
	const int id;
	const int etaj;
	int nrCamere;
	float *suprafataCamera;
	string adresa;
	static int contor;
	static int nrApartamenteExistente;

	Apartament():id(contor++),etaj(3) {
		nrCamere = 3;
		suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			suprafataCamera[i] = 10;
		}
		adresa = "piata Romana";
		nrApartamenteExistente++;
	}
	Apartament(string adresa, int nrCamere, float* suprafataCamera, int etajPrimit) :id(contor++), etaj(etajPrimit) {
		this->nrCamere = nrCamere;
		this->suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->suprafataCamera[i] = suprafataCamera[i];
		}
		this->adresa = adresa;
		nrApartamenteExistente++;
	}

	~Apartament() {
		delete[]suprafataCamera;
		nrApartamenteExistente--;
	}

	void afisare() {
		cout << id << ". In " << adresa << " se afla un apartament cu " << nrCamere << " la etajul "
			<< etaj <<" cu suprafetele ";
		for (int i = 0; i < nrCamere; i++) {
			cout << suprafataCamera[i] << ", ";
		}
		cout << endl;
	}
};
int Apartament::contor = 1;
double Apartament::tva = 19;
int Apartament::nrApartamenteExistente = 0;


void main() {
	Apartament a1;
	Apartament a2("Victoriei", 2, new float[2]{ 23,34 },2);
	a1.afisare();
	a2.afisare();
	{
		Apartament a3;

		cout <<"In corp"<< a1.nrApartamenteExistente << endl;
	}
	cout <<"In afara corpului"<< a1.nrApartamenteExistente<<endl;
	Apartament *pa1 = &a1;
	cout << pa1->nrApartamenteExistente << endl;
	Apartament* pa2 = new Apartament("Universitate", 4, new float[4]{ 8,12,9,11 }, 5);

	cout << Apartament::nrApartamenteExistente << endl;

	//tema
	//de ce da eroare urmatorul apel:
	//Apartament a5("Victoriei", 5);

	delete pa2;
}