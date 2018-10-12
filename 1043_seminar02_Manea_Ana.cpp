#include<iostream>
#include<string>
using namespace std;

int pozitieValoareMaxima(float *v, int n)
{
	int i;
	int max = 0;
	for( i=1;i<n;i++)
		if (v[max] < v[i])
		{
			max = i;  // max ia pozitia pe care se afla valoarea mai mare
		}
	return max;
}

void stergereDePeOPozitie(float* &v, int &n, int pozitie)
{
	//alocam memorie pt un nou vector de n-1 elemente
	float *aux = new float[n - 1];
	int i, j = 0;
	for(i=0;i<n;i++)
		if (i != pozitie)
		{
			aux[j] = v[i];
			j++;
		}
	delete[]v; //dezalocam vectorul v  []-arata ca e vorba de un vector
	v = aux; //se copiaza adresele
	n--; //pt ca a scazut numarul de elemente
}

void stergeValoareMaxima(float* &v, int &n)
{
	//calculam pozitia valorii maxime
	int pozitie = pozitieValoareMaxima(v, n);
	//stergem elementul prin copierea intr-un nou vector
	
	stergereDePeOPozitie(v, n, pozitie);

}
void main()
{
	string sir = "Seminar 2"; 
	sir = "Seminar POO";
	sir += " -pointeri";
	cout << sir << endl;
	cout << sir.substr(sir.find("-") + 1, 8) << endl;//find primeste pozitia caracterului cautat; cautam cuvantul de dupa - cu 8 caractere

	float v[20]; //memoria pt vector se aloca la inceputul compilarii
	float *vector; //pointer la float
	int n = 5;
	vector = new float[n]; // se aloca spatiu la momentul executiei
	//vector va retine adresa primului element
	for (int i = 0; i < n; i++)  //citire vectorul
	{
		cin >> vector[i];
	}

	for (int i = 0; i < n; i++) //afisare vector
	{
		cout << vector[i] << " ";
	}
	cout << endl;

	stergeValoareMaxima(vector, n);

	for (int i = 0; i < n; i++) //afisare vector
	{
		cout << vector[i] << " ";
	}
	cout << endl;

}