#include<iostream>
#include<string>

using namespace std;

//int adunare(int a, int b) {
//	return a + b;
//}
//float adunare(float a, float b) {
//	return a + b;
//}

class Timbru {
	int an;
	string tara;
	float pret;

public:

	Timbru() :an(0), tara("Romania"), pret(0) {};
	Timbru(int an, string tara, float pret) {
		this->an = an;
		this->tara = tara;
		this->pret = pret;
	}
	float getPret() {
		return pret;
	}

	operator float() {
		return this->pret;
	}

	Timbru operator+(Timbru t) {
		Timbru timbru = *this;
		timbru.pret = this->pret + t.pret;
		return timbru;
	}

};
template <class cl>
class Colectionar
{
	cl* colectie;
	int nr_elemente;
	string nume;
public:
	Colectionar(cl* colectie, int nr_elemente, string nume)
	{
		this->nr_elemente = nr_elemente;
		this->colectie = new cl[nr_elemente];
		for (int i = 0; i < nr_elemente; i++)
		{
			this->colectie[i] = colectie[i];
		}
		this->nume = nume;
	}
	Colectionar()
	{
		this->nume = "";
		this->nr_elemente = 0;
		this->colectie = NULL;
	}
	~Colectionar()
	{
		if(this->colectie != NULL)
		delete[] this->colectie;
	}

	Colectionar(const Colectionar &col)
	{
		this->nr_elemente = col.nr_elemente;
		this->nume = col.nume;
		this->colectie = new cl[col.nr_elemente];
		for (int i = 0; i < col.nr_elemente; i++)
		{
			this->colectie[i] = col.colectie[i];
		}
	}
	Colectionar operator=(const Colectionar &c) {
		this->nume = c.nume;
		this->nr_elemente = c.nr_elemente;
		if (this->colectie != null) delete[]this->colectie;
		this->colectie = new cl[this->nr_elemente];
		for (int i = 0; i < this->nr_elemente; i++) {
			this->colectie[i] = c.colectie[i];
		}
		return *this;
	}
	float calculareValoare() {
		float sum = 0;
		for (int i = 0; i < this->nr_elemente; i++) {
			sum =sum + this->colectie[i];
		}
		return sum;
	}
};

template <class T>
T adunare(T a, T b) {
	return a + b;
}

void main() {
	std::cout << adunare(1, 2) << std::endl;
	std::cout << adunare(1.0f, 2.678f) << endl;
	Timbru t1(2019, "Romania", 100);
	Timbru t2(2018, "Romania", 20);
	Timbru t3 = adunare(t1, t2);
	cout << t3.getPret()<<endl;

	Colectionar<int> c1;

	Colectionar<float> c2(new float[3]{ 4.6f,5.8f,2.7f }, 3, "Popescu");

	cout << c2.calculareValoare()<<endl;

	Colectionar<Timbru> c3(new Timbru[2]{ t1,t2 }, 2, "Vasilescu");

	cout << c3.calculareValoare();
}