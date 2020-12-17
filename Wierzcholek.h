#pragma once
class Wierzcholek {
private:
	Wierzcholek* nastepny;					//wskaznik na nastepny wierzcholek
	int o_dolne = 0;						//zmienna przechowuj¹ca ograniczenie dolne wierzcholka
	int wartosc = 0;						//funkcja przechowuj¹ca wartosc wierzcholka

public:
	Wierzcholek();							//konstruktor wierzcholka
	~Wierzcholek();							//destruktor wierzcholka
	int getO_dolne() {
		return o_dolne;						//funkcja zwracajaca wartosc ograniczenia dolnego
	}
	int getWartosc() {
		return wartosc;						//funkcja zwracajaca wartosc wierzcholka
	}
	Wierzcholek* getNastepny() {
		return nastepny;					//funkcja zwracajaca wskaznik na nastepny wierzcholek
	}
	void setWartosc(int wartosc) {
		this->wartosc = wartosc;			//funkcja ustawiajaca wartosc wierzcholka
	}
	void setO_dolne(int o_dolne) {
		this->o_dolne = o_dolne;			//funkcja ustawiajaca wartosc ograniczenia dolnego dla wierzcholka
	}

	void setNastepny(Wierzcholek* nastepny) {
		this->nastepny = nastepny;			//funkcja ustawiajaca nastepny wierzcholek
	}

};

