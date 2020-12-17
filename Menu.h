#pragma once
#include "Graf.h"
#include "Stoper.h"
#include "BB.h"
#include "PZ.h"
#include "PD.h"
#include <string>
#include <conio.h>


class Menu {

private:
	Graf* graf = nullptr;					//wskaznik na graf
	Stoper* stoper = nullptr;				//wskaznik na obiekt odpowiadjacy za pomiar czasu
	BB* algBB = nullptr;					//wskaznik na obiekt odpowiadajacy za algorytm podzialu i ograniczen
	PZ* algPZ = nullptr;					//wskaznik na obiekt odpowiadajacy za algorytm przegladu zupelnego
	PD* algPD = nullptr;					//wskaznik na obiekt odpowiadajcy za algorytm programowania dynamicznego

public:
	Menu();									//konstruktor menu
	~Menu();								//destruktor menu
	void NacisnijKlawiszByKontynuwoac();	//funkcja pomocnicza do estetyki programu
	void wczytajPlik();						//funkcja odpowiadaj¹ca za wczytywanie pliku tekstowego
	void menuPomiar();						//funkcja wyswietlajaca menu z pomiarami
	void pomiarPZ();						//funkcja odpowiadajaca za pomiar przegladu zupelnego
	void pomiarPD();						//funkcja odpowiadajaca za pomiar programowania dynamicznego
	void pomiarBB();						//funkcja odpowiadajaca za pomiar algorytmu podzialu i ograniczen
};

