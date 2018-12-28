//seminarul 12 - 20.12.2018
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Echipa {
	string nume;
	int nrJucatori;
	int* varsteJucatori;
public:
	Echipa() {
		this->nume = "Necunoscut";
		this->nrJucatori = 0;
		this->varsteJucatori = NULL;
	}
	Echipa(string nume, int nrJucatori, int* varsteJucatori) {
		this->nume = nume;
		this->nrJucatori = nrJucatori;
		this->varsteJucatori = new int[nrJucatori];
		for (int i = 0; i < this->nrJucatori; i++) {
			this->varsteJucatori[i] = varsteJucatori[i];
		}
	}
	Echipa(Echipa& e) {  //constr de copiere
		this->nume = e.nume;
		this->nrJucatori = e.nrJucatori;
		this->varsteJucatori = new int[e.nrJucatori];
		for (int i = 0; i < e.nrJucatori; i++) {
			this->varsteJucatori[i] = e.varsteJucatori[i];
		}
	}
	Echipa operator =(Echipa& ec) {
		this->nume = ec.nume;
		this->nrJucatori = ec.nrJucatori;
		if(this->varsteJucatori!=NULL)
			delete[]this->varsteJucatori;
		this->varsteJucatori = new int[ec.nrJucatori];
		for (int i = 0; i < ec.nrJucatori; i++) {
			this->varsteJucatori[i] = ec.varsteJucatori[i];
		}
		return *this;
	}
	~Echipa() {
		if (this->varsteJucatori != NULL)
			delete[]this->varsteJucatori;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	string getNume() {
		return nume;
	}
	void setNrJucatori(int nrJucatori) {
		this->nrJucatori = nrJucatori;
	}
	int getNrJucatori() {
		return nrJucatori;
	}
	void setVarstaJucatori(int nrJucatori,int* varstaJucatori) {
		if (varsteJucatori != NULL)
			delete[]this->varsteJucatori;
		this->varsteJucatori = new int[nrJucatori];
		for (int i = 0; i < nrJucatori; i++) {
			this->varsteJucatori[i] = varsteJucatori[i];
		}
	}
	int* getVarsteJucatori() {
		if (varsteJucatori != NULL)
			return varsteJucatori;
		else
			throw "Nu avem jucatori";
	}
	friend ostream& operator <<(ostream& out, const Echipa &e) {
		out <<"Numele echipei: "<< e.nume << endl;
		out <<"Numarul jucatorilor: "<<e.nrJucatori << endl;
		out <<"Varstele jucatorilor: ";
		for (int i = 0; i < e.nrJucatori; i++) {
			out << e.varsteJucatori[i] << " ";
		}
		return out;
	}
	friend istream& operator >>(istream& in, Echipa &e) {
		cout << "Numele echipei: ";
		in>>e.nume;
		cout << "Numarul jucatorilor: ";
		in >> e.nrJucatori;
		if (e.varsteJucatori != NULL)
			delete[]e.varsteJucatori;
		e.varsteJucatori= new int[e.nrJucatori];
		cout << "Varstele jucatorilor: " << endl;
		for (int i = 0; i < e.nrJucatori; i++) {
			cout << "Introduceti varsta jucatorului " << i<<": ";
			in>>e.varsteJucatori[i];
			cout << endl;
		}
		return in;
	}
	//este indicat ca operatorii pentru lucrul cu fisiere sa se faca separat

	friend fstream& operator <<(fstream& out, Echipa e) {
		out << e.nume << ",";
		out << e.nrJucatori << ",";
		for (int i = 0; i < e.nrJucatori; i++) {
			out << e.varsteJucatori[i] << ",";
		}
		out << endl;
		return out;
	}
	friend fstream& operator >>(fstream& in, Echipa &e) {
		in >> e.nume;
		in >> e.nrJucatori;
		if (e.varsteJucatori != NULL)
			delete[]e.varsteJucatori;
		e.varsteJucatori = new int[e.nrJucatori];
		for (int i = 0; i < e.nrJucatori; i++) {
			in >> e.varsteJucatori[i];
		}
		return in;
	}
};

void main() {
	//Echipa e("NumeEchipa", 2, new int[2]{ 21,24 });
	//fstream f("fisier.txt", ios::out);  //construim un fisier
	//f << e;    //se apeleaza operatorul << , dar nu se afiseaza pe monitor, se afiseaza in fisier
	//f.close();

	//Echipa e;
	//fstream g("fisier.txt", ios::in);
	////ifstream g("fisier.txt");
	//g>> e;
	//g.close();
	//cout << e;


	/*fstream f("fisier.csv", ios::out);
	Echipa e1("nume", 2, new int[2]{ 21,24 });
	Echipa e2("numeech", 3, new int[3]{ 21,24,22});
	f << e1;
	f << e2;
	f.close();*/

	////fisier binar
	//Echipa e("nume", 2, new int[2]{ 21,24 });
	//fstream f("fisier.bin", ios::out | ios::binary);
	//f.write((char*)&e, sizeof(Echipa));
	//f.close();


	Echipa e;
	fstream f("fisier.bin", ios::in | ios::binary);
	f.read((char*)&e, sizeof(Echipa));
	cout << e;
}
// csv = comma separrated value
//TEMA: look up serializare si deserializare