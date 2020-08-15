//Adam Majchrzak 06.03.2020

#include "std_lib_facilities.hpp"
/*
	procedure Silnia(a)
	begin
	for(int i > 1, i--)
	wynik*=i
	return wynik
	end
	procedure
	begin
	cin a, b
	check the warnings
	P(a,b) = a!/(a-b)!
	C(a,b) = P(a,b)/b!
	end
*/
int silnia(int a) {
	int wynik = 1;
	for (int i = a; i > 1; i--) {
		wynik *= i;
	}
	return wynik;
}



int main()
{
	unsigned int a = 0;
	unsigned int b = 0;
	double P = 0.0;
	int sum = 1;
	int suma1 = 1;
	int c = 0;
	int wynikPermutacjiKoncowej = 0;
	std::cout << "Wprowadz 2 liczby calkowite aby obliczyc permutacje P(a,b): \n";
	std::cin >> a >> b;
	
	while(b > a) {
		std::cout << "liczba 2 nie moze byc większa od 1 z zalozenia algorytmu P(a,b).";
		cin >> b;
		if (b > a) {
			return -1;
		}
	}
	while (b == a) {
		std::cout << "Liczba 2 nie moze byc rowna 1 poniewaz dojdzie do dzielenia przez 0";
		cin >> b;
		if (b == a) {
			return -2;
		}
	}
	while ((a < 0) && (b < 0)) {
		std::cout << "Liczba 1 i 2 musza byc dodatnie z zalozenia silni.";
		cin >> a >> b;
		if ((a < 0) && (b < 0)) {
			return -3;
		}
	}

	c = a - b;
	sum = silnia(a);
	suma1 = silnia(c);
	P = sum / suma1;
	std::cout << "wynik permutacji P(a,b) wynosi: " << P << std::endl;

	wynikPermutacjiKoncowej = P / silnia(b);
	std::cout <<"Wynik permutacji końcowej C(a,b) wynosi: " <<wynikPermutacjiKoncowej;


	
	return 0;
}