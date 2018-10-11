#include<iostream>
#include<string>
using namespace std;

int pozitieValoareMaxima(float* v, int n) {
	int max = 0;
	for (int i = 1; i < n; i++) {
		if (v[max] < v[i]) {
			max = i;
		}
	}

	return max;
}

void stergereDePeOPozitie(float* &v, int &n, int pozitie) {
	float*aux = new float[n - 1];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (i != pozitie) {
			aux[j] = v[i];
			j++;
		}
	}
	delete[]v;
	v = aux;
	n--;
}

void stergeValoareMaxima(float* &v, int &n) {
	//calculam pozitia valorii maxime
	int pozitie = pozitieValoareMaxima(v, n);
	//stergem elmentul prin copierea intr-un nou vector
	stergereDePeOPozitie(v, n, pozitie);
}

void main() {
	string sir = "Seminar 2";
	sir = "Seminar POO";
	sir += "-pointeri";

	cout << sir << endl;
	cout<<sir.substr(sir.find('-') + 1, 8)<<endl;

	//float v[20];
	float * vector;
	int n = 5;
	vector = new float[n];
	for (int i = 0; i < n; i++) {
		cin >> vector[i];
	}

	for (int i = 0; i < n; i++) {
		cout << vector[i] << " ";
	}
	cout << endl;

	stergeValoareMaxima(vector, n);

	for (int i = 0; i < n; i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
}