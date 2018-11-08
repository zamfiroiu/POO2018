#include<iostream>
#include<string>

using namespace std;

class Telefon {
private:
	const int cod;//nu este unic
	static int tva;
	string model;
	int nrSenzori;
	double * pretSenzori;
public:
	Telefon():cod(0), nrSenzori(2) {
		model = "Samsung";
		pretSenzori = new double[nrSenzori];
		pretSenzori[0] = 100;
		pretSenzori[1] = 130;
	}

	Telefon(string model, int nrSenzori, double *pretSenzori, 
		int codNou) :cod(codNou) {
		
		this->model = model;
		this->nrSenzori = nrSenzori;
		this->pretSenzori = new double[nrSenzori];
		for (int i = 0; i < nrSenzori; i++) {
			this->pretSenzori[i] = pretSenzori[i];
		}
	}
	~Telefon() {
		delete []pretSenzori;
	}

	string getModel() {
		return model;
	}
	void setModel(string model) {
		if (model.length() > 0) {
			this->model = model;
		}
	}

	void setNrSenzori(int nrSenzori, double *pretSenzori) {
		this->nrSenzori = nrSenzori;
		delete[] this->pretSenzori;
		this->pretSenzori = new double[nrSenzori];
		for (int i = 0; i < nrSenzori; i++) {
			this->pretSenzori[i] = pretSenzori[i];
		}
	}

	int getNrSenzori() {
		return nrSenzori;
	}
	double* getPretSenzori() {
		return pretSenzori;
	}

	double getPretSenzorPozitie(int index) {
		if (index >= 0 && index < nrSenzori) {
			return this->pretSenzori[index];
		}
		else {
			throw "index incorect";
		}
	}

	static int getTVA() {
		return tva;
	}

};

int Telefon::tva = 19;

void main() {
	Telefon t;
	cout << t.getModel()<<endl;
	t.setModel("S9");
	cout << t.getModel() << endl;

	cout << t.getPretSenzorPozitie(0) << endl;

	try {

		cout << t.getPretSenzorPozitie(-1) << endl;
	}
	catch (int a) {

	}
	catch (const char* mesaj) {
		cout << mesaj;
	}
	catch (...) {
		cout << "Am intampinat o eroare";
	}


	cout << t.getTVA()<<endl;
	cout << Telefon::getTVA() << endl;
}
