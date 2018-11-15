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
	Telefon() :cod(0), nrSenzori(2) {
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
		delete[]pretSenzori;
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

	Telefon(const Telefon& t):cod(t.cod) {
		this->model = t.model;
		this->nrSenzori = t.nrSenzori;
		this->pretSenzori = new double[t.nrSenzori];
		for (int i = 0; i < nrSenzori; i++) {
			this->pretSenzori[i] = t.pretSenzori[i];
		}
	}

	Telefon operator=(const Telefon &t) {
		this->model = t.model;
		this->nrSenzori = t.nrSenzori;

		if (this->pretSenzori != NULL) {
			delete[]this->pretSenzori;//evit apartia de memory leaks
		}
		this->pretSenzori = new double[t.nrSenzori];
		for (int i = 0; i < nrSenzori; i++) {
			this->pretSenzori[i] = t.pretSenzori[i];
		}
		return *this;
	}

};

int Telefon::tva = 19;

void afisareModel(Telefon t) {
	cout << t.getModel()<<endl;
}

void main() {
	double * v = new double[3]{ 30,40,50 };
	Telefon t("Samsung", 3, v, 1);
	/*Telefon m = t;
	Telefon a;
	a = t;*/
	afisareModel(t);

	delete[]v;
}