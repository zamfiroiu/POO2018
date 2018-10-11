//#include<iostream>
//#include<string>
//using namespace std;
//
//int cautaMinim(int*v, int n) {
//	int indexMinim = 0;
//	for (int i = 1; i < n; i++) {
//		if (v[i] < v[indexMinim]) {
//			indexMinim = i;
//		}
//	}
//	return indexMinim;
//}
//
//void stergePozitieCuMinim(int* &v, int &n, int index) {
//	int* aux = new int[n - 1];
//	int j = 0;
//	for (int i = 0; i < n; i++) {
//		if (i != index) {
//			aux[j] = v[i];
//			j++;
//		}
//	}
//	delete[]v;
//	v = aux;
//	n--;
//}
//
//
//void stergeMinim(int * &v, int &n) {
//	//cautam indexul pentru valoarea minima din vector
//	int index = cautaMinim(v,n);
//	//stergem elementeul de pe indexul gasit prin copierea urmatoarelor elemente
//	//modificam dimensiunea vectorului
//	stergePozitieCuMinim(v, n, index);
//}
//
//void main() {
//
//	string sir = "Seminar 02";
//	sir = "seminar 2";
//	sir.append("-pointeri");
//	sir += "-pointeri";
//	cout << sir<<endl;
//	string sir2 = sir.substr(sir.find('-') + 1, 8);
//	cout << sir2<<endl;
//	
//	int v[100];
//	cout << v;
//
//	int * vector;
//	int n = 5;
//	vector = new int[n];
//	for (int i = 0; i < n; i++) {
//		vector[i] = i;
//	}
//	cout << endl << endl;
//	for (int i = 0; i < n; i++) {
//		cout << vector[i];
//	}
//
//	stergeMinim(vector, n);
//	cout << endl << endl;
//	for (int i = 0; i < n; i++) {
//		cout << vector[i];
//	}
//	delete[]vector;
//}