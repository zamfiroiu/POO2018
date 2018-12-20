#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Ferma {
	string numeFerma;
	int nrAnimale;
	float* greutateAnimale;

public:
	Ferma() {
		numeFerma = "necunoscut";
		nrAnimale = 0;
		greutateAnimale = NULL;
	}
	Ferma(string numeFerma, int nrAnimale, float* greutateAnimale) {
		this->numeFerma = numeFerma;
		this->nrAnimale = nrAnimale;
		this->greutateAnimale = new float[nrAnimale];
		for (int i = 0; i < nrAnimale; i++) {
			this->greutateAnimale[i] = greutateAnimale[i];
		}
	}
	Ferma(const Ferma &f) {
		this->numeFerma = f.numeFerma;
		this->nrAnimale = f.nrAnimale;
		this->greutateAnimale = new float[this->nrAnimale];
		for (int i = 0; i < this->nrAnimale; i++)
			this->greutateAnimale[i] = f.greutateAnimale[i];
		
	}

	Ferma&operator=(const Ferma &f) {
		if (this->greutateAnimale != NULL) {
			delete[] this->greutateAnimale;
		}
		this->numeFerma = f.numeFerma;
		this->nrAnimale = f.nrAnimale;
		this->greutateAnimale = new float[this->nrAnimale];
		for (int i = 0; i < this->nrAnimale; i++)
			this->greutateAnimale[i] = f.greutateAnimale[i];
		return *this;
	}
	~Ferma()
	{
		if (this->greutateAnimale != NULL) {
			delete[] this->greutateAnimale;
		}
	}

	int getNrAnimale()
	{
		return this->nrAnimale;
	}
	
	void setNrAnimale(int nrAnimale)
	{
		if(nrAnimale > 0)
		this->nrAnimale = nrAnimale;
	}
	
	string getNumeFerma()
	{
		
		return this->numeFerma;
	}

	void setNumeFerma(string numeFerma)
	{
		if (numeFerma.length() > 0)
		this->numeFerma = numeFerma;
	}

	float* getGreutateAnimale()
	{
		if (greutateAnimale == NULL) {
			throw "Vectorul este null";
		}
		else
		return this->greutateAnimale;
	}

	void setGreutateAnimale(float* greutateAnimale, int nrAnimale)
	{
		this->nrAnimale = nrAnimale;
		if (this->greutateAnimale != NULL)
			delete[] this->greutateAnimale;

		this->greutateAnimale = new float[this->nrAnimale];
		for (int i = 0; i < nrAnimale; i++)
		{
			this->greutateAnimale[i] = greutateAnimale[i];
		}
	}
	friend istream& operator>>(istream&citire, Ferma&f) {
		cout << "Numele fermei: ";
		citire >> f.numeFerma;
		cout << "Numarul de animale: ";
		citire >> f.nrAnimale;
		if (f.greutateAnimale != NULL) delete[]f.greutateAnimale;
		f.greutateAnimale = new float[f.nrAnimale];
		for (int i = 0; i < f.nrAnimale; i++) {
			cout << " greutatea animalului " << i+1 << " : ";
			citire >> f.greutateAnimale[i];
		}
		return citire;
	}
	friend fstream& operator>>(fstream&citire, Ferma&f) {
		cout << "Se citeste din fisier...";
		citire >> f.numeFerma;
		citire >> f.nrAnimale;
		if (f.greutateAnimale != NULL) 
			delete[]f.greutateAnimale;
		f.greutateAnimale = new float[f.nrAnimale];
		for (int i = 0; i < f.nrAnimale; i++) {
			citire >> f.greutateAnimale[i];
		}
		return citire;
	}
};

ostream& operator<<(ostream& afisare, Ferma &f)
{
	afisare << "Numele fermei este: " << f.getNumeFerma() ;
	afisare << endl << "Numarul de animale: " << f.getNrAnimale();
	afisare << endl << "Greutatea animalelor este: ";
	for (int i = 0; i < f.getNrAnimale(); i++)
	{
		afisare << f.getGreutateAnimale()[i] << " ";
	}
	return afisare;
}
fstream& operator<<(fstream& afisare, Ferma &f)
{
	afisare << f.getNumeFerma() << ";";
	afisare << f.getNrAnimale() << ";";
	for (int i = 0; i < f.getNrAnimale(); i++)
	{
		afisare << f.getGreutateAnimale()[i] << ";";
	}
	return afisare;
}




void main() {
	//Ferma f;
	//f.setGreutateAnimale(new float[3]{ 1000,800,1200 }, 3);
	//f.setNumeFerma("FermaDeVaci");
	//cout << f;
	//cin >> f;
	//cout << f;

	//Ferma ferma("Ferma2", 3, new float[3]{ 200, 2300,400 });
	//fstream f("Ferme.csv", ios::app);
	//f << endl;
	//f << ferma<<endl;
	//f.close();

	//Ferma ferma;
	//fstream g("Ferme.txt", ios::in);
	//g >> ferma;
	//cout << ferma;
	//g.close();

	//Ferma ferma("Ferma2", 3, new float[3]{ 200, 2300,400 });
	//fstream f("fisier.data", ios::out | ios::binary);
	//f.write((char*)&ferma, sizeof(Ferma));
	//f.close();

	//fstream g("fisier.data", ios::in | ios::binary);
	//Ferma ferma;
	//g.read((char*)&ferma, sizeof(Ferma));
	//cout << ferma;
	//g.close();

}