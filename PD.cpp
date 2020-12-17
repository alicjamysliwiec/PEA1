#include "PD.h"

void PD::start() {
	//obliczamy wszystkie drogi prowadzace z wierzcholka 0 do wierzcholkow od 1 do liczby_wierzcholkow i zapisujemy je w tablicy
	for (int i = 1; i < ilosc_wierzcholkow; i++) {
		pamiecDrogi[(1 << i) | 1][i] = tab[0][i];			//zapisanie dlugosci drogi z wierzcholka i do wierzcholka 0
		pamiecPoprzednichWierzcholkow[(1 << i) | 1][i] = 0;	//zapisanie wierzcholka z ktorego prowadzi droga do wierzcholka i (w tym przypadku droga jest prowadzona do wierzcholka 0)
	}
	//dla kazdej maski bitowej, ktora zawiera wierzcholek 0 (dlatego +2) zaczynajac od pierwszej uzupelnionej przez nas (od 3)
	for (int maska_bitowa = 3; maska_bitowa < 1 << ilosc_wierzcholkow; maska_bitowa += 2) {
		for (int v = 0; v < ilosc_wierzcholkow; v++) { //sprawdzamy po kolei kazdy wierzcholek
			if (maska_bitowa & (1 << v)) { //jesli wierzcholek nalezy do zadanej maski
				for (int j = 0; j < ilosc_wierzcholkow; j++) { //szukamy kolejnego wierzcholka
					if (!(maska_bitowa & (1 << j))) { //ktory nie nalezy do maski, bo chcemy dodac go na koncu drogi
						if (pamiecDrogi[maska_bitowa][v] + tab[v][j] < pamiecDrogi[maska_bitowa | (1 << j)][j]) { //porownujemy czy taka nowa droga jest krotsza od wczesniej odkrytej drogi 
																										// (przechodzacej przez te same wierzcholki, ale w innej kolejnosci)
							pamiecPoprzednichWierzcholkow[maska_bitowa | (1 << j)][j] = v; //jesli jest to lepsze rozwiazanie zapisujemy dla nowej drogi nowy poprzedni wierzcholek
							pamiecDrogi[maska_bitowa | (1 << j)][j] = pamiecDrogi[maska_bitowa][v] + tab[v][j]; //oraz nowa dlugosc tejze drogi
						}
					}
				}
			}
		}
	}

	//przeszukujemy tablice w celu znalezienia najlepszego rozwiazania
	for (int i = 0; i < ilosc_wierzcholkow; i++) {
		tymczasowa = pamiecDrogi[(1 << ilosc_wierzcholkow) - 1][i] + tab[i][0]; //dla kazdego wierzcholka pobieramy droge z ostatniego wiersza tablicy (maska 11.111 czyli droga zawierajaca wszystkie wierzcholki)
																				//i dodajemy droge prowadzaca do wierzcholka 0
		if (tymczasowa < wynik) {	//jesli znaleziono lepszy wynik
			wynik = tymczasowa;		// to zapisujemy go
			wierzcholek = i;		//i wierzcholek, z ktorego ta droga prowadzi
		}
	}
}

//funkcja wyswietlajaca wynik
string PD::wyswietlWynik()
{
	string ten_wynik = "";
	int maska_bitowa = (1 << ilosc_wierzcholkow) - 1;	//maska pozwalajaca poruszac sie po tabeli pamieci
	int poprzedni, aktualny = wierzcholek;				//zmienne pomocnicze do odnajdywania kolejnych wierzcholkow
	Stos sciezka;										//stos z odwrocona kolejnoscia wierzcholkow
	sciezka.push(aktualny);

	for (int i = ilosc_wierzcholkow - 2; i > 0; i--) {
		poprzedni = pamiecPoprzednichWierzcholkow[maska_bitowa][aktualny]; //pobieramy poprzedni wierzcholek
		sciezka.push(poprzedni);						//dodajemy do stosu
		maska_bitowa = maska_bitowa ^ (1 << aktualny);	//tworzymy nowa maske bitowa
		aktualny = poprzedni;							//ustawiamy poprzedni na aktualny
	}

	ten_wynik = "Minimalna dlugosc:  " + to_string(wynik) + "\n" + "Sciezka: " + sciezka.odKoncaToString() + " - 0";

	return ten_wynik;
}

//konstruktor algorytmu
PD::PD(Graf* graf) {

	tab = graf->getTab();												 //pobranie tablicy
	ilosc_wierzcholkow = graf->getW();									//pobranie liczby wierzcholkow
	pamiecDrogi = new int* [1 << ilosc_wierzcholkow];					//deklaracja tablicy przechowujacej minimalna dlugosc drogi dla kazdy podproblemu
	pamiecPoprzednichWierzcholkow = new int* [1 << ilosc_wierzcholkow]; //deklaracja tablica przechowujaca wartosc poprzedniego wierzcholka, z ktorego prowadzi droga

	for (int i = 0; i < (1 << ilosc_wierzcholkow); i++) {
		pamiecDrogi[i] = new int[ilosc_wierzcholkow];
		pamiecPoprzednichWierzcholkow[i] = new int[ilosc_wierzcholkow];
		for (int j = 0; j < ilosc_wierzcholkow; j++) {
			pamiecDrogi[i][j] = wynik;
			pamiecPoprzednichWierzcholkow[i][j] = wynik;
		}
	}
}

//dekonstruktor algorytmu
PD::~PD() {
	for (int i = 0; i < (1 << ilosc_wierzcholkow); i++) {
		delete[] pamiecDrogi[i];
		delete[] pamiecPoprzednichWierzcholkow[i];
	}
	delete[] pamiecDrogi;
	delete[] pamiecPoprzednichWierzcholkow;
}


