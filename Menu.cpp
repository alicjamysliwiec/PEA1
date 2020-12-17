#include "Menu.h"


Menu::Menu() {
	Stoper licznik;		//zmienna przechowuj¹ca czas
	string nazwa_pliku;	//zmienna przechowujaca nazwe pliku tekstowego
	char option;		//opcja ktora wybieramy
	int wartosc;		//ilosc wierzcholkow
	do {
		cout << "1.Wczytaj z pliku" << endl;
		cout << "2.Wygeneruj losowo" << endl;
		cout << "3.Wyswietl" << endl;
		cout << "4.Przeglad zupelny" << endl;
		cout << "5.Algorytm podzialu i ograniczen" << endl;
		cout << "6.Programowanie dynamiczne" << endl;
		cout << "7.Pomiary" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje: ";
		option = _getche();
		cout << endl;

		switch (option) {
		case '1':
			wczytajPlik();						//wczytujemy graf z pliku
			NacisnijKlawiszByKontynuwoac();
			break;
		case '2':
			cout << "Podaj ilosc miast: ";
			cin >> wartosc;
			graf = new Graf(wartosc);			//tworzymy nowy graf
			graf->wygeneruj();					//wywolujemy funkcje generacji grafu
			NacisnijKlawiszByKontynuwoac();
			break;
		case '3':
			if (graf == NULL) {
				cout << "Nie wczytano grafu.";
			}
			else
				graf->wyswietl();					//wyswietlamy wygenerowany  lub wczytany graf
			NacisnijKlawiszByKontynuwoac();
			break;
		case '4':
			if (graf == NULL) {
				cout << "Nie wczytano grafu.";
			}
			else
			algPZ = new PZ(graf);					//tworzymy obiekt algorytmu przegladu zupelnego
			licznik.start();						//startujemy licznik
			algPZ->start();							//rozpoczynamy algorytm
			licznik.stop();							//zatrzymujemy licznik
			licznik.dodajCzas();					//zapisujemy czas wykonania algorytmu
			cout << algPZ->wyswietlWynik() << endl;	//wyswietlamy wyniki
			cout << endl << "Czas wykonania algorytmu: " << licznik.licznik << endl;
			licznik.zerujLicznik();					//zerujemy licznik
			NacisnijKlawiszByKontynuwoac();
			break;
		case '5':
			if (graf == NULL) {
				cout << "Nie wczytano grafu.";
			}
			else
			algBB = new BB(graf);						//tworzymy obiekt algorytmu podzialu i ograniczen
			licznik.start();							//startujemy licznik
			algBB->start();								//rozpoczynamy algorytm
			licznik.stop();								//zatrzymujemy licznik
			licznik.dodajCzas();						//zapisujemy czas wykonania algorytmu
			cout << algBB->wyswietlWynik() << endl;		//wyswietlamy wyniki
			cout << endl << "Czas wykonania algorytmu: " << licznik.licznik << endl;
			licznik.zerujLicznik();						//zerujemy licznik
			NacisnijKlawiszByKontynuwoac();
			break;
		case '6':
			if (graf == NULL) {
				cout << "Nie wczytano grafu.";
			}
			else
			algPD = new PD(graf);						//tworzymy obiekt algorytmu podzialu i ograniczen
			licznik.start();							//startujemy licznik
			algPD->start();								//rozpoczynamy algorytm programowania dynamicznego
			licznik.stop();								//zatrzymujemy licznik
			licznik.dodajCzas();						//zapisujemy czas wykonania algorytmu
			cout << algPD->wyswietlWynik() << endl;		//wyswietlamy wyniki
			cout << endl << "Czas wykonania algorytmu: " << licznik.licznik << endl;
			licznik.zerujLicznik();						//zerujemy licznik
			NacisnijKlawiszByKontynuwoac();
			break;
		case '7':
			menuPomiar();								//wywolujemy menu pomiar
			NacisnijKlawiszByKontynuwoac();
			break;
		case '0':
			break;
		};
	} while (option != '0');
}

void Menu::pomiarPZ() {
	int wielkosc, liczbaProb;
	Stoper stoper;
	cout << "Podaj ilosc miast: ";
	cin >> wielkosc;
	cout << "Podaj liczbe testow: ";
	cin >> liczbaProb;
	for (int j = 0; j < liczbaProb; j++) {
		graf = new Graf(wielkosc);
		algPZ = new PZ(graf);
		stoper.start();
		algPZ->mierzPZ();
		stoper.stop();
		stoper.dodajCzas();
	}

	cout << "Sredni czas wykonywania algorytmu dla ilosc miast " << wielkosc << ":" << stoper.licznik / liczbaProb;
	stoper.zerujLicznik();
}

void Menu::pomiarPD() {
	int wielkosc, liczbaProb;
	Stoper stoper;
	cout << "Podaj ilosc miast: ";
	cin >> wielkosc;
	cout << "Podaj liczbe testow: ";
	cin >> liczbaProb;
	for (int j = 0; j < liczbaProb; j++) {
		graf = new Graf(wielkosc);
		algPD = new PD(graf);
		stoper.start();
		algPD->start();
		stoper.stop();
		stoper.dodajCzas();
	}

	cout << "Sredni czas wykonywania algorytmu dla ilosc miast " << wielkosc << ":" << stoper.licznik / liczbaProb;
	stoper.zerujLicznik();
}

void Menu::pomiarBB() {
	int wielkosc, liczbaProb;
	Stoper stoper;
	cout << "Podaj ilosc miast: ";
	cin >> wielkosc;
	cout << "Podaj liczbe testow: ";
	cin >> liczbaProb;
	for (int j = 0; j < liczbaProb; j++) {
		graf = new Graf(wielkosc);
		algBB = new BB(graf);
		stoper.start();
		algBB->start();
		stoper.stop();
		stoper.dodajCzas();
	}

	cout << "Sredni czas wykonywania algorytmu dla ilosc miast " << wielkosc << ":" << stoper.licznik / liczbaProb;
	stoper.zerujLicznik();
}

void Menu::menuPomiar() {
	char option;
	do {
		cout << "1.Przeglad zupelny" << endl;
		cout << "2.Algorytm podzialu i ograniczen" << endl;
		cout << "3.Programowanie dynamiczne" << endl;
		cout << "0.Powrot do menu" << endl;
		cout << "Podaj opcje: ";
		option = _getche();
		cout << endl;

		switch (option) {
		case '1': //pomiar przegladu zupelnego
			pomiarPZ();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '2': //pomiar algorytmu podzialu i ograniczen
			pomiarBB();
			NacisnijKlawiszByKontynuwoac();
			break;

		case '3': //pomiar programowania dynamicznego
			pomiarPD();
			NacisnijKlawiszByKontynuwoac();
			break;
		}
	} while (option != '0');
}

void Menu::NacisnijKlawiszByKontynuwoac() {
	cout << "\nNacisnij dowolny klawisz by kontynuowac" << endl;
	_getche();
}
void Menu::wczytajPlik() {
	fstream plik;
	string nazwa; //nazwa pliku z ktorego wczytujemy
	do
	{
		cout << "\nPodaj nazwe pliku z ktorego mam pobrac dane(musi konczyc sie na .txt i byc w katalogu programu): ";
		cin >> nazwa;
		plik.open(nazwa);
	} while (!plik.good()); //dopoki nie uda sie wczytac pliku powtarza zabytanie o nazwe pliku
	int liczba;
	plik >> liczba;
	graf = new Graf(liczba);
	int tmp;
	for (int i = 0; i < liczba; i++) {
		for (int j = 0; j < liczba; j++) {
			plik >> tmp;
			graf->getTab()[i][j] = tmp;
		}
	}
}

Menu::~Menu() {

}