#include "PZ.h"

//konstruktor algorytmu przegladu
PZ::PZ(Graf* graf) {
	ilosc_wierzcholkow = graf->getW();					//pobranie ilosci wierzcholkow
	tab = graf->getTab();								//pobranie grafu
	tablica_permutacji = new int[ilosc_wierzcholkow];	//tworzymy jednowymiarow¹ tablice permutacji
	sciezka = new int[ilosc_wierzcholkow];				//tworzymy jednowymiarowa tablice zawierajaca sciezke
	for (int i = 0;i < ilosc_wierzcholkow;i++) {
		tablica_permutacji[i] = i;						//uzupelniamy tablice permutacji kolejnymi liczbami od 0 do wartosci rownej ilosci wierzcholkow
	}
}


//funkcja rozpoczynajaca algorytm
void PZ::start() {
	permutacje(1);									//wywolanie funkcji permutacji od 1 wierzcholka
}

//funkcja wyswietlajaca wynik
string PZ::wyswietlWynik() {
	string wynik = "";
	wynik = "Minimalna dlugosc: " + to_string(min) + "\n" + "Sciezka: ";

	for (int i = 0; i < ilosc_wierzcholkow; i++) {
		wynik += to_string(sciezka[i]) + " - ";				//wyswietlenie kolejnych zawartosci tablicy sciezka
	}

	wynik += "0";
	return wynik;
}

//destruktor algorytmu
PZ::~PZ() {
	delete[] tablica_permutacji;
	delete[] sciezka;
}

//funkcja wykonujaca permutacje
void PZ::permutacje(int k) {
	int dlugosc = 0;																		//dlugosc sciezki ustawiamy na zero
	if (k == ilosc_wierzcholkow) {															//ostatnie wywolanie funkcji rekurencyjnej
		for (int i = 0;i < ilosc_wierzcholkow - 1;i++) {
			dlugosc += tab[tablica_permutacji[i]][tablica_permutacji[i + 1]];				//obliczamy dlugosc
		}
		dlugosc += tab[tablica_permutacji[ilosc_wierzcholkow - 1]][tablica_permutacji[0]];  //dodajemy odleglosc do zera
		if (dlugosc < min) {																//jezeli dlugosc jest mniejsze od ostatniej znalezionej najmnieszej
			min = dlugosc;																	//przypisujemy j¹ do minimalnej wartosci
			for (int i = 0;i < ilosc_wierzcholkow;i++) {
				sciezka[i] = tablica_permutacji[i];											//wpisujemy do tablicy kolejne wierzcholki
			}
		}
	}
	else { //wykonujemy permutacje i wywolujemy rekurencyjnie nasza funkcje
		for (int i = k;i < ilosc_wierzcholkow;i++) {
			int tmp = tablica_permutacji[i];
			tablica_permutacji[i] = tablica_permutacji[k];
			tablica_permutacji[k] = tmp;
			permutacje(k + 1);
			tmp = tablica_permutacji[i];
			tablica_permutacji[i] = tablica_permutacji[k];
			tablica_permutacji[k] = tmp;
		}
	}
}

//funkcja potrzebna do mierzenia algorytmu nie wyswietla wynikow
void PZ::mierzPZ() {
	permutacje(1);
}
