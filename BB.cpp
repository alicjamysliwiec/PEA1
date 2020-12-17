#include "BB.h"

using namespace std;

//konstruktor algorytmu
BB::BB(Graf* graf) {
	ilosc_wierzcholkow = graf->getW();					//pobranie ilosci wierzcholkow
	tab = graf->getTab();								//pobranie grafu
	tablica_min = new int[ilosc_wierzcholkow];			//utworzenie tablicy wartosci minimalnych
	odwiedzone = new bool[ilosc_wierzcholkow];			//utworzenie tablicy z informacja o odwiedzonych wierzcholkach
	int min = 999999999;
	for (int i = 0; i < ilosc_wierzcholkow; i++) {
		odwiedzone[i] = false;							//ustawienie wszystkich wierzcholkow jako nieodwiedzone
		for (int j = 0; j < ilosc_wierzcholkow; j++) {
			if (tab[i][j] != -1 && tab[i][j] < min) {
				min = tab[i][j];						//wyszukanie wartosci minimalnej w kazdym wierszu
			}
		}
		tablica_min[i] = min;							//dopisanie jej do tablicy
		ograniczenie_dolne += min;						//wyliczenie ograniczenia dolnego
		min = 99999999;
	}
}

//destruktor algorytmu
BB::~BB() {
	delete[] tablica_min;
	delete[] odwiedzone;
}

//funkcja liczaca ograniczenie dolne
int BB::dolne(Wierzcholek wierzcholek, int nastepny) {
	int wynik = wierzcholek.getO_dolne();					//do wyniku przypisujemy ograniczenie dolne wierzcholka
	wynik -= tablica_min[wierzcholek.getWartosc()];			//wynik zmniejszamy o wartosc tablicy 
	wynik += tab[wierzcholek.getWartosc()][nastepny];		//wynik powiekszamy o odleglosc miedzy wierzcholkami

	return wynik;											//zwracamy wynik
}

//funkcja liczaca ograniczenie gorne
void BB::gorne(Wierzcholek wierzcholek) {
	int wynik = dolne(wierzcholek, 0);		//do wyniku przypisujemy ograniczenie dolne wierzcholka, ktorego nastepnym wierzcholkie jest wierzcholek poczatkowy
	if (wynik < ograniczenie_gorne) {		//jezeli wynik jest mniejszy od ogranizenia gornego
		aktualna_sciezka.copy(&sciezka);	//kopiujemy aktualna sciezke do docelowej
		ograniczenie_gorne = wynik;			//zmieniamy ograniczenie gorne
	}
}

//funkcja rekurencyjna
void BB::rekurencja(Wierzcholek wierzcholek) {
	aktualna_sciezka.push(wierzcholek.getWartosc());				//dodajemy do stosu wierzcholek
	odwiedzone[wierzcholek.getWartosc()] = true;					//ustawiamy wierzcholek jako odwiedzony
	Wierzcholek tmp_wierzcholek;									//tworzymy tymczasowy wierzcholek
	Kolejka kolejka;												//tworzymy kolejke
	for (int i = 0; i < ilosc_wierzcholkow;i++) {
		if (!odwiedzone[i]) {										//je¿eli wierzcholek jest nieodwiedzomy
			tmp_wierzcholek.setWartosc(i);							//ustawiamy jego wartosci
			tmp_wierzcholek.setO_dolne(dolne(wierzcholek, i));		//ustawiamy dolne ograniczenie
			kolejka.push(tmp_wierzcholek);							//dodajemy go do kolejki
		}
	}
	if (kolejka.czyPusta()) {										//jezeli kolejka jest pusta - zbadalismy kazdy wierzcholek grafu
		gorne(wierzcholek);											//wyznaczamy gorne ograniczenie dla wierzcholka
	}
	else {
		while (!kolejka.czyPusta()) {								//dopoki kolejka nie jest pusta
			tmp_wierzcholek = kolejka.front();						//aktualny poczatek kolejki przypisujemy do tymczasoego wierzcholka
			kolejka.pop();											//usuwamy wierzcholek z kolejki

			if (tmp_wierzcholek.getO_dolne() < ograniczenie_gorne) //jezeli dolne ograniczenie tymczasowego wierzcholka jest mniejsze niz dotychczasowe gorne
			{	
				rekurencja(tmp_wierzcholek);						//wykonujemy funkcje rekurencyjnie
			}
			else break;												//w przeciwnym wypadku przerywamy
		}
	}
	aktualna_sciezka.pop();											//usuwamy wierzcholek z aktualnej sciezki
	odwiedzone[wierzcholek.getWartosc()] = false;					//ustawiamy wierzcholek jak nieodwiedzony
}

//funkcja rozpoczynajaca algorytm
void BB::start() {
	Wierzcholek start;						//wierzcholek startowy
	start.setWartosc(0);					//ustawiamy mu wartosc na zero
	start.setO_dolne(ograniczenie_dolne);	//ustawiamy mu ograniczenie dolne na obecne
	rekurencja(start);						//rozpoczynamy funkcje rekurencyjna
}

//funkcja wyswietlajaca wynik
string BB::wyswietlWynik() {
	string wynik = "";
	wynik = "Minimalna dlugosc: " + to_string(ograniczenie_gorne) + "\n" + "Sciezka: " + sciezka.toString() + "0";

	return wynik;

}