#include "Graf.h"
using namespace std;

//konstruktor grafu
Graf::Graf(int ilosc) {
	ilosc_wierzcholkow = ilosc;
	tab = new int* [ilosc];
	for (int i = 0; i < ilosc; i++) {
		tab[i] = new int[ilosc];
	}
}

//destruktor grafu
Graf::~Graf() {
	for (int i = 0; i < ilosc_wierzcholkow; i++) {
		delete[] tab[i];
	}
	delete[] tab;
}

//generowanie grafu
void Graf::wygeneruj() {
	for (int i = 0; i < ilosc_wierzcholkow; i++) {
		for (int j = 0; j < ilosc_wierzcholkow; j++) {
			if (i == j) {
				tab[i][j] = -1;						//wpisanie na przekatnych -1
			}
			else {
				tab[i][j] = rand() % 1000 + 1;		//w pozostale miejsca wartosci od 1 do 1000
			}
		}
	}
}

//sensowne wyswietlenie grafu
void Graf::wyswietl() {
	for (int i = 0; i < ilosc_wierzcholkow; i++) {
		for (int j = 0; j < ilosc_wierzcholkow; j++) {
			if (tab[i][j] > 0 && tab[i][j] < 10) {
				cout << "   " << tab[i][j];
			}
			else if (tab[i][j] >= 10 && tab[i][j] < 100) {
				cout << "  " << tab[i][j];
			}
			else if (tab[i][j] >= 100 && tab[i][j] < 1000) {
				cout << " " << tab[i][j];
			}
			else if (tab[i][j] == 1000) {
				cout << tab[i][j];
			}
			else {
				cout << " " << tab[i][j] << " ";
			}
			cout << " ";
		}
		cout << endl << endl;
	}
}

//wczytanie grafu z pliku
void Graf::wczytaj(fstream plik) {
	int liczba;
	for (int i = 0; i < ilosc_wierzcholkow; i++) {
		for (int j = 0; j < ilosc_wierzcholkow; j++) {
			plik >> liczba;
			tab[i][j] = liczba;
		}
	}
}


