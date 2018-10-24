#include<iostream>
#include<string>

using namespace std;

int pozitieCuvantLung(string* v, int n) {
	int max = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].length() > v[max].length()) {
			max = i;
		}
	}
	return max;
}

void stergemDePeOPozitie(string* &v, int &n, int poz) {
	string*aux = new string[n - 1];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (i != poz) {
			aux[j++] = v[i];
		}
	}
	delete[]v;
	v = aux;
	n--;
}

void stergereElementLung(string* &v, int &n) {
	//determinam pozitia celui mai lung cuvant
	int pozitie = pozitieCuvantLung(v, n);
	//stergem elementul de pe acea pozitie si scadem n;
	stergemDePeOPozitie(v, n, pozitie);
}

void main() {
	string sir = "semar 2";
	sir = "Seminar 2";
	sir.append("-pointeri");
	cout << sir << endl;
	cout << sir.substr(sir.find('-')+1, 8)<<endl;

	string vector[20];
	int n = 4;
	string*v = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	stergereElementLung(v, n);
	
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	delete[]v;
}