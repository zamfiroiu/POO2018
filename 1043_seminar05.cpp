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


};
int Apartament::contor = 1;
double Apartament::tva = 19;
int Apartament::nrApartamenteExistente = 0;


void main() {
	Apartament a;
	cout << a.getAdresa() << endl;
	a.setAdresa("");
	cout << a.getAdresa()<<endl;
	try {

		cout << a.getSuprafataCameraData(-1) << endl;
	}
	catch (int exceptie) {

	}
	catch (const char*  mesaj) {
		cout << mesaj;
	}
	catch (...) {
		cout << "A aparut o eroare";
	}

	a.setTVA(7);
	cout << a.getTVA();
	Apartament b;
	b.setTVA(9);

	cout << a.getTVA();


	Apartament::setTVA(8);
}