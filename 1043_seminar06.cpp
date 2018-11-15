#include<iostream>
#include<string>

using namespace std;

class Apartament {

private:

	static double tva;

	const int id;
	const int etaj;
	int nrCamere;
	float *suprafataCamera;
	string adresa;
	static int contor;
	static int nrApartamenteExistente;

public:
	


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

	void setAdresa(string nouaAdresa) {
		if(nouaAdresa.length()>2)
			this->adresa = nouaAdresa;
	}

	string getAdresa() {
		return this->adresa;
	}
	void setNrCamere(int nrCamere,float* suprafete) {
		this->nrCamere = nrCamere;
		delete []this->suprafataCamera;
		this->suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->suprafataCamera[i] = suprafete[i];
		}
	}

	int getNrCamere() {
		return nrCamere;
	}

	float* getSuprafeteCamere() {
		return this->suprafataCamera;
	}

	float getSuprafataCameraData(int index) {
		if (index < nrCamere && index >= 0) {
			return this->suprafataCamera[index];
		}
		else {
			throw "index incorect";
		}
	}

	static void setTVA(double tvaNou) {
		tva = tvaNou;
	}

	static double getTVA() {
		return tva;
	}

	Apartament(const Apartament &a) :id(contor++), etaj(a.etaj) {
		this->nrCamere = a.nrCamere;
		this->suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->suprafataCamera[i] = a.suprafataCamera[i];
		}
		this->adresa = a.adresa;
		nrApartamenteExistente++;		
	}

	Apartament operator=(const Apartament &a) {
		this->nrCamere = a.nrCamere;
		if (this->suprafataCamera != NULL) {
			delete[]this->suprafataCamera;//evit aparitia de memory leaks;
		}
		this->suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->suprafataCamera[i] = a.suprafataCamera[i];
		}
		this->adresa = a.adresa;

		return *this;
	}

	Apartament operator+(const Apartament &a) {
		Apartament b;
		b.adresa = this->adresa;
		b.nrCamere = this->nrCamere + a.nrCamere;
		b.suprafataCamera = new float[b.nrCamere];
		for (int i = 0; i < this->nrCamere; i++) {
			b.suprafataCamera[i] = this->suprafataCamera[i];
		}
		for (int i = this->nrCamere; i < b.nrCamere; i++) {
			b.suprafataCamera[i] = a.suprafataCamera[i-this->nrCamere];
		}

		return b;
	}

};
int Apartament::contor = 1;
double Apartament::tva = 19;
int Apartament::nrApartamenteExistente = 0;


void afisareAdresa(Apartament a) {
	cout << a.getAdresa();
}

void main() {

	//float * v = new float[3]{ 30,20,40 };
	//Apartament a("Romana", 3, v, 3);
	////Apartament b = a;
	///*Apartament c;
	//c = a;*/

	//afisareAdresa(a);



	//delete[]v;
}