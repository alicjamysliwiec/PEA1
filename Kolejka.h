#pragma once
#pragma once
#include <string>
#include "Stos.h"
#include "Wierzcholek.h"

using namespace std;


class Kolejka {
private:

	Wierzcholek* poczatek = nullptr;	//wskaznik na wierzcholek

public:

	void push(Wierzcholek element);		//funkcja dodajaca wierzcholek do kolejki
	Wierzcholek front();				//funkcja zwracajaca wierzcholek znajdujacy sie z przodu kolejki
	void pop();							//funkcja usuwajaca pierwszy wierzcholek z kolejki
	bool czyPusta();					//funkcja sprawdzajaca czy kolejka jest pusta
	Kolejka();							//konstruktor kolejki
	~Kolejka();							//destruktor kolejki
};