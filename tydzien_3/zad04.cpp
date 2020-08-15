// Adam Majchrzak 18.03.2020
//

#include <iostream>
#include <vector>

using namespace std;

class Rational {
	float numerator, denominator;
public:
	Rational(float numeratorx, float denominatorx);
	~Rational();
	float additional(float, float); //metoda odpowiada za dodawanie liczb
	float subtraction(float, float); //metoda odpowiada za odejmowanie liczb
	float multiplication(float, float); //metoda odpowiada za mnożenie liczb
	float division(float, float); //metoda odpowiada za dzielenie liczb
};

//konstruktor obiektu
Rational::Rational(float numeratorx, float denominatorx)
{
	numerator = numeratorx;
	denominator = denominatorx;
	numeratorx / denominatorx;
	std::cout << "konstruktor domyslny.";
	std::cout << std::endl;
}

float Rational::additional(float x, float y) {
	std::vector<double> vectorWartosciNumeratora;
	std::vector<double> vectorWartosciDenumeratora;
	int zmienna, zmienna1;
	double liczbaDodana, liczbaDodana1;
	std::cout << "Jesli chcesz dodac liczbe do numeratora wpisz ile chcesz ich dodac: ";
	std::cin >> zmienna;
	for (int i = 0; i < zmienna; ++i) {
		std::cout << "wprowadz liczbe: ";
		std::cin >> liczbaDodana;
		vectorWartosciNumeratora.push_back(liczbaDodana);
		x += vectorWartosciNumeratora[i];
	}
	std::cout << "Jesli chcesz dodac liczbe do denominatora wpisz ile chcesz ich dodac: ";
	std::cin >> zmienna1;
	for (int i = 0; i < zmienna1; ++i) {
		std::cout << "wprowadz liczbe: ";
		std::cin >> liczbaDodana1;
		vectorWartosciDenumeratora.push_back(liczbaDodana1);
		y += vectorWartosciDenumeratora[i];
	}
	std::cout << x << "/" << y << std::endl;
	return x / y;
}

float Rational::subtraction(float x, float y) {
	std::vector<double> vectorWartosciNumeratora;
	std::vector<double> vectorWartosciDenumeratora;
	int zmienna, zmienna1;
	double liczbaDodana, liczbaDodana1;
	std::cout << "Jesli chcesz dodac liczbe do numeratora wpisz ile chcesz ich dodac: ";
	std::cin >> zmienna;
	for (int i = 0; i < zmienna; ++i) {
		std::cout << "wprowadz liczbe: ";
		std::cin >> liczbaDodana;
		vectorWartosciNumeratora.push_back(liczbaDodana);
		x -= vectorWartosciNumeratora
			[i];
	}
	std::cout << "Jesli chcesz dodac liczbe do denominatora wpisz ile chcesz ich dodac: ";
	std::cin >> zmienna1;
	for (int i = 0; i < zmienna1; ++i) {
		std::cout << "wprowadz liczbe: ";
		std::cin >> liczbaDodana1;
		vectorWartosciDenumeratora.push_back(liczbaDodana1);
		y -= vectorWartosciDenumeratora[i];
	}
	std::cout << x << "/" << y << std::endl;
	if (y == 0) {
		std::cout << "Enumerator rowny 0, Nie dziel przez zero";
		return -1;
	}

	return x / y;
}

float Rational::multiplication(float x, float y) {
	std::vector<double> vectorWartosciNumeratora;
	std::vector<double> vectorWartosciDenumeratora;
	int zmienna, zmienna1;
	double liczbaDodana, liczbaDodana1;
	std::cout << "Jesli chcesz dodac liczbe do numeratora wpisz ile chcesz ich dodac: ";
	std::cin >> zmienna;
	for (int i = 0; i < zmienna; ++i) {
		std::cout << "wprowadz liczbe: ";
		std::cin >> liczbaDodana;
		vectorWartosciNumeratora.push_back(liczbaDodana);
		x *= vectorWartosciNumeratora[i];
	}
	std::cout << "Jesli chcesz dodac liczbe do denominatora wpisz ile chcesz ich dodac: ";
	std::cin >> zmienna1;
	for (int i = 0; i < zmienna1; ++i) {
		std::cout << "wprowadz liczbe: ";
		std::cin >> liczbaDodana1;
		vectorWartosciDenumeratora.push_back(liczbaDodana1);
		y *= vectorWartosciDenumeratora[i];
	}
	std::cout << x << "/" << y << std::endl;
	if (y == 0) {
		std::cout << "Enumerator rowny 0, Nie dziel przez zero";
		return -1;
	}

	return x / y;
}

float Rational::division(float x, float y) {
	std::vector<double> vectorWartosciNumeratora;
	std::vector<double> vectorWartosciDenumeratora;
	int zmienna, zmienna1;
	double liczbaDodana, liczbaDodana1;
	std::cout << "Jesli chcesz dodac liczbe do numeratora wpisz ile chcesz ich dodac: ";
	std::cin >> zmienna;
	for (int i = 0; i < zmienna; ++i) {
		std::cout << "wprowadz liczbe: ";
		std::cin >> liczbaDodana;
		vectorWartosciNumeratora.push_back(liczbaDodana);
		x /= vectorWartosciNumeratora[i];
	}
	std::cout << "Jesli chcesz dodac liczbe do denominatora wpisz ile chcesz ich dodac: ";
	std::cin >> zmienna1;
	for (int i = 0; i < zmienna1; ++i) {
		std::cout << "wprowadz liczbe: ";
		std::cin >> liczbaDodana1;
		vectorWartosciDenumeratora.push_back(liczbaDodana1);
		y /= vectorWartosciDenumeratora[i];
	}
	std::cout << x << "/" << y << std::endl;
	if (y == 0) {
		std::cout << "Enumerator rowny 0, Nie dziel przez zero";
		return -1;
	}
	return x / y;
}

void wybierzFunkcje() {
	short int x;
	Rational zmienna(0.0, 0.0);
	std::cout << "Wybierz od operacje matematyczna : " << std::endl;
	std::cout << "1. + | 2. - | 3. * | 4. / | 5. exit()" << std::endl;
	std::cin >> x;
	if (x < 1 || x > 5) {
		exit(0);
	}
	switch (x) {
	case 1: {
			std::cout << zmienna.additional(0.0, 0.0);
			break;
		}
		case 2: {
			std::cout << zmienna.subtraction(0.0, 0.0);
			break;
		}
		case 3: {
			std::cout << zmienna.multiplication(1.0, 1.0);
			break;
		}
		case 4: {
			std::cout << zmienna.division(1.0, 1.0);
			break;
		}
		case 5: {
			std::cout << "Koniec działania programu";
			break;
		}
	}
}

//destruktor obiektu
Rational::~Rational()
{
	std::cout << std::endl << "Destruktor" << std::endl;
}

int main()
{
	wybierzFunkcje();
}

//It is nice to have one class which show you Rational and double solution