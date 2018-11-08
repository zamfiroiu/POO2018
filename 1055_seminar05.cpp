//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Film {
//	string titlu;
//	int nrActori;
//	string *numeActori;
//	static int fps;
//	const float id;//nu este unic;
//public:
//	Film():id(1) {
//		titlu = "Ion";
//		nrActori = 2;
//		numeActori = new string[nrActori];
//		numeActori[0] = "Ion";
//		numeActori[1] = "Ana";
//	}
//
//	Film(string titlu, int nrActori, string *numeActori, float idNou) :id(idNou) {
//		this->titlu = titlu;
//		this->nrActori = nrActori;
//		this->numeActori = new string[nrActori];
//		for (int i = 0; i < nrActori; i++) {
//			this->numeActori[i] = numeActori[i];
//		}
//	}
//
//	~Film() {
//		delete[]numeActori;
//	}
//	void setTitlu(string titluNou) {
//		if (titluNou.length() > 3){
//			titlu = titluNou;
//		}
//	}
//	string getTitlu() {
//		return titlu;
//	}
//
//	void setActori(int nrActori, string*numeActori) {
//		this->nrActori = nrActori;
//		delete []this->numeActori;//evitare memory leak;
//		this->numeActori = new string[nrActori];
//		for (int i = 0; i < nrActori; i++) {
//			this->numeActori[i] = numeActori[i];
//		}
//	}
//	int getNrActori() {
//		return nrActori;
//	}
//	string*getNumeActori() {
//		return numeActori;
//	}
//
//	string getNumeActor(int index){ 
//		if(index>=0 && index<nrActori)
//			return numeActori[index];
//		else {
//			return "";
//		}
//	}
//	void setFPS(int fps) {
//		this->fps = fps;
//	}
//
//	static int getFPS() {
//		return fps;
//	}
//};
//
//int Film::fps = 60;
//
//void main() {
//	Film f;
//	cout << f.getTitlu()<<endl;
//	f.setTitlu("Marcel");
//	cout<<f.getTitlu()<<endl;
//
//	cout << f.getFPS();
//
//	cout << Film::getFPS();
//}