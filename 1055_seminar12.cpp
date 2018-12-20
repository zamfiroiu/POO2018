//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//class Echipa
//{
//	string nume;
//	int nrJucatori;
//	int* varsteJucatori;
//public:
//	Echipa()
//	{
//		this->nume = "Necunoscut";
//		this->nrJucatori = 0;
//		this->varsteJucatori = NULL;
//	}
//
//	Echipa(string nume, int nrJucatori, int *varsteJucatori)
//	{
//		this->nume = nume;
//		this->nrJucatori = nrJucatori;
//		this->varsteJucatori = new int[nrJucatori];
//		for (int i = 0; i < nrJucatori; i++)
//		{
//			this->varsteJucatori[i] = varsteJucatori[i];
//		}
//
//	}
//	Echipa(Echipa &e)
//	{
//		this->nume = e.nume;
//		this->nrJucatori = e.nrJucatori;
//		this->varsteJucatori = new int[e.nrJucatori];
//		for (int i = 0; i < e.nrJucatori; i++)
//		{
//			this->varsteJucatori[i] = e.varsteJucatori[i];
//		}
//
//	}
//	Echipa operator=(Echipa& ec) {
//		this->nume = ec.nume;
//		this->nrJucatori = ec.nrJucatori;
//		if (varsteJucatori != NULL)
//			delete[]this->varsteJucatori;
//		this->varsteJucatori = new int[ec.nrJucatori];
//		for (int i = 0; i < ec.nrJucatori; i++)
//		{
//			this->varsteJucatori[i] = ec.varsteJucatori[i];
//
//		}
//		return *this;
//	}
//	~Echipa() {
//		if (this->varsteJucatori != NULL)
//			delete[]this->varsteJucatori;
//	}
//	string getNume()
//	{
//		return nume;
//	}
//	void setNume(string numeNou) {
//		nume = numeNou;
//	}
//	int getNrJucatori()
//	{
//		return nrJucatori;
//	}
//	void setNrJucatori(int nrJucatoriNou)
//	{
//		nrJucatori = nrJucatoriNou;
//	}
//	int*getVarsteJucatori() {
//		if (varsteJucatori != NULL)
//			return varsteJucatori;
//		else
//			throw "Nu avem jucatori";
//
//	}
//	void setVarsteJucatori(int* varsteJucatori, int nrJucatori) {
//		if (varsteJucatori != NULL)
//			delete[]varsteJucatori;
//		varsteJucatori = new int[nrJucatori];
//		for (int i = 0; i < nrJucatori; i++)
//			this->varsteJucatori[i] = varsteJucatori[i];
//	}
//	friend ostream& operator<<(ostream& monitor, const Echipa& e) {
//		monitor << "numele echipei: ";
//		monitor << e.nume<<endl;
//		monitor << "numarul de jucatori: ";
//		monitor << e.nrJucatori<<endl;
//		monitor << "cu varstele: "<<endl;
//		for (int i = 0; i < e.nrJucatori; i++)
//			monitor << e.varsteJucatori[i] << " ";
//		return monitor;
//	}
//	friend fstream& operator<<(fstream& monitor, Echipa e) {
//		monitor << e.nume << ";";
//		monitor << e.nrJucatori << ";";
//		for (int i = 0; i < e.nrJucatori; i++)
//			monitor << e.varsteJucatori[i] << ";";
//		monitor << endl;
//		return monitor;
//	}
//	friend istream& operator>>(istream& monitor, Echipa &e) {
//		cout << "Introduceti numele echipei: ";
//		monitor >> e.nume;
//		cout << "Introduceti numarul de jucatori: ";
//		monitor >> e.nrJucatori;
//		if (e.varsteJucatori != NULL)
//			delete[] e.varsteJucatori;
//		e.varsteJucatori = new int[e.nrJucatori];
//		for (int i = 0; i < e.nrJucatori; i++) {
//			cout << "Introduceti varsta jucatorului" << i;
//			monitor >> e.varsteJucatori[i];
//		}
//		return monitor;
//	}
//	friend fstream& operator>>(fstream& monitor, Echipa &e) {
//		monitor >> e.nume;
//		monitor >> e.nrJucatori;
//		if (e.varsteJucatori != NULL)
//			delete[] e.varsteJucatori;
//		e.varsteJucatori = new int[e.nrJucatori];
//		for (int i = 0; i < e.nrJucatori; i++) {
//			monitor >> e.varsteJucatori[i];
//		}
//		return monitor;
//	}
//
//};
//void main() {
//	//Echipa e("NumeEchipa", 2, new int[2]{ 21,24 });
//	//fstream f("fisier.txt", ios::out);
//	//f << e;
//	//f.close();
//	//Echipa e("e", 1, new int[1]{23});
//	//fstream g("fisier.txt", ios::in);
//	////ifstream g("fisier.txt");
//	//g >> e;
//	//cout << e;
//
//	//fstream f("fisier.csv", ios::app);
//
//	//Echipa e("nume", 2, new int[2]{21,24});
//	//Echipa e1("numeEchipa", 3, new int[3]{ 21,24,22 });
//	//f << e<<e1;
//	//f.close();
//
//	//Echipa e("nume", 2, new int[2]{ 21,24 });
//	//fstream f("fisier.bin", ios::out | ios::binary);
//	//f.write((char*)&e, sizeof(Echipa));
//	//f.close();
//
//	Echipa e;
//	fstream f("fisier.bin", ios::in | ios::binary);
//	f.read((char*)&e, sizeof(Echipa));
//	cout << e;
//
//
//}