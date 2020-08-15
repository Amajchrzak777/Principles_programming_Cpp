// zad05.cpp
// Adam Majchrzak 24.03.2020

#include "std_lib_facilities.hpp"

void wybor() {
	vector<int> hex;
	vector<int> oct;
	vector<int> dec;
	int liczbahex;
	int liczbaoct;
	int liczba;
	int n;
	int ch;
	int i = 0;
	std::cin >> n; 
	while (i < n) {
		std::cout << "Jesli wprowadzisz 1 wpisz liczbe w formacie szesnastkowym: "
			<< "Jesli wprowadzisz 2 wpisz liczbe w formacie osemkowym: "
			<< "Jesli wprowadzisz 3 wpisz liczbe w formacie dziesietnym: "
			<< "Inna cyfra badz litera konczy dzialanie programu: ";
		std::cin >> ch;
		switch (ch) {
		case 1: {
			std::cin >> std::hex >> liczbahex;
			hex.push_back(liczbahex);
			break;
		}
		case 2: {
			std::cin >> std::oct >> liczbaoct;
			oct.push_back(liczbaoct);
			break;
		}
		case 3: {
			std::cin >> std::dec >> liczba;
			dec.push_back(liczba);
			break;
		}
		default: {
			std::cout << "Koniec dzialania programu";
		}
		}
		i++;
	}
	for (int i = 0; i < hex.size(); i++) {
		std::cout << std::hex << "Zapis szesnastkowy: \t0x" << liczbahex << std::dec << " \tzamiana na system dziesietny: \t" << liczbahex << '\n';
	}
	for (int i = 0; i < oct.size(); i++) {
		std::cout << std::oct << "Zapis osemkowy: \t0" << liczbaoct << std::dec << " \tzamiana na system dziesietny: \t" << liczbaoct << '\n';
	}
	for (int i = 0; i < dec.size(); i++) {
		std::cout << "Zapis dzisietny: \t" << liczba << " \tzamiana na system dziesietny: \t" << std::dec << liczba << '\n';
	}
}

int main()
{
	std::cout << "Wprowadz liczbe a ja zamienie ja na dziesietna: \n";
	std::cout << "Wybierz czy chcesz zamienic liczbe w systemie szesnastkowym, osemkowym czy dziesietnym: [1, 2, 3] \n";
	std::cout << "Ile liczb chcesz wczytac ? ";
	wybor();
}
