// Stack-yigin-codes-static_array.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
template<typename Tur>
class Yigin
{
private:
	void genislet(int boyut) {
		Tur* yeniAlan = new Tur[kapasite + boyut];

		for (int i = 0; i < tepe; i++) {
			yeniAlan[i] = veriler[i];
		}
		delete[] veriler;
		veriler = yeniAlan;
		kapasite += boyut;

	}
	int tepe;
	int kapasite;
	Tur* veriler;
public:
	Yigin() {
		tepe = -1;
		kapasite = 5;
		veriler = new Tur[kapasite];

	}
	~Yigin() {
		delete[] veriler;

	}
	void Ekle(Tur veri) {
		if (tepe < kapasite - 1) {

			genislet(kapasite);
		}
		tepe++;
		veriler[tepe] = veri;
	}
	void Cikar() {
		if (tepe != -1) {
			tepe--;
		}
	}
	friend ostream &operator <<(ostream& os, Yigin& yigin) {
		os << "----->";
		for (int i = yigin.tepe; i >= 0; i--)
		{
			os << yigin.veriler[i] << endl << "       ";
		}
		os << endl;
		return os;
	}
	Tur getir() {
		if (tepe != -1) {
			return veriler[tepe];

		}
		else
		{
			throw exception("Yigin::getir() eleman yok");
		}
	}
	bool bosmu() {
		if (tepe != -1) {
			return true;

		}
		else {
			return false;
		}
	}
};

int main()
{
	Yigin<int> yigin;
	
	cout << yigin;
	for (int i = 0; i < 6; i++) {
		yigin.Cikar();
		cout << yigin;
	}
	for (int i = 0; i < 16; i++) {
		yigin.Ekle(i);
	}
	cout << yigin;
}