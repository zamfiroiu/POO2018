#include<iostream>
#include<string>

using namespace std;

class Makeup {
public:
	const int id;
	const int nrLuniValabilitate;
	string denumire;
	int nrProduse;
	double* preturiProduse;

	static double tva;
	static int contor;
	static int nrMakeUpUri;

	Makeup():id(contor++),nrLuniValabilitate(12) {
		denumire = "Mascara";
		nrProduse = 3;
		preturiProduse = new double[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			preturiProduse[i] = 10;
		}
		nrMakeUpUri++;
	}

	Makeup(int nrLuni, string denumire, int nrProduse, double* preturiProduse) :nrLuniValabilitate(nrLuni), id(contor++) {
		this->denumire = denumire;
		this->nrProduse = nrProduse;
		this->preturiProduse = new double[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->preturiProduse[i] = preturiProduse[i];
		}
		nrMakeUpUri++;
	}

	~Makeup() {
		delete []preturiProduse;
		nrMakeUpUri--;
	}

	void afisare() {
		cout <<id<<"."<< denumire << " are " << nrProduse << " cu preturile:";
		for (int i = 0; i < nrProduse; i++) {
			cout << preturiProduse[i] << ", ";
		}
		cout << endl;
	}
};
double Makeup::tva = 0.19;
int Makeup::contor = 1;
int Makeup::nrMakeUpUri = 0;


void main(){

	Makeup m1;
	Makeup m2(6, "Ruj", 3, new double[3]{10,12,8});

	m1.afisare();
	m2.afisare();
	cout << m1.nrMakeUpUri << endl;

	{
		Makeup m3;
		cout <<"in corp:"<< m1.nrMakeUpUri << endl;
	}

	cout << "in afara corpului:" << m1.nrMakeUpUri << endl;

	Makeup * pointerM1=&m1;

	cout << Makeup::nrMakeUpUri << endl;

	Makeup* pointerM2 = new Makeup();

	delete pointerM2;
}