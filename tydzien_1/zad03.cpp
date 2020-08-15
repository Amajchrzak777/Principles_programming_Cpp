//Adam Majchrzak 04.03.2020

#include "std_lib_facilities.hpp"
#include <vector>

int main()
{
	const double ft_to_meter = 0.3048;
	const double in_to_meter = 0.0254;
	double conv = 0;
	double sum_of_conv = 0;
	double sum_of_conv1 = 0;
	double sum_of_var1 = 0;
	//double var1 = 0;
	double var2 = 0;
	string metr = "m";
	string foot = "ft";
	string inch = "in";
	char unit = 'c';
	std::cout << "put two int variables: \n" << "char | ends the program \n";
	double minimum = 0;
	//minimum = var1;
	vector<double> values(10);

	for (double var1; cin >> var1;) {
		values.push_back(var1);
		std::sort(values.begin(), values.end());
		std::cout << std::endl << values[var1] << std::endl;
			if (var1 > var2) {
				std::cout << "the larger value is: " << var1 << std::endl;
				std::cout << "the smaller value is: " << var2 << std::endl;
				if (abs(var1 - var2) < 0.01) {
					std::cout << "the numbers are almost equal \n";
				}
				std::cout << "wybierz jednostke sposrod 3\n 1 - metr\n 2 - foot\n 3 - cal\n";
				cin >> unit;
				switch (unit)
				{
				case '1':
					std::cout << var1 << metr <<std::endl;
					conv = var1;
					break;
				case '2':
					std::cout << var1 << foot <<std::endl;
					conv = var1 * ft_to_meter;
					break;
				case '3':
					std::cout << var1 << inch<<std::endl;
					conv = var1 * in_to_meter;
					break;
				default:
					std::cout << "wybrales poza zakresem";
					break;
				}
				sum_of_conv += conv;
			}
			else if (var1 < var2) {
				std::cout << "the larger value is: " << var2 << std::endl;
				std::cout << "the smaller value is: " << var1 << std::endl;
				if (abs(var1 - var2) < 0.01) {
					std::cout << "the numbers are almost equal \n";
				}
				std::cout << "wybierz jednostke sposrod 3\n 1 - metr\n 2 - foot\n 3 - cal\n";
				cin >> unit;
				switch (unit)
				{
				case '1':
					std::cout << var2 << metr;
					conv = var2;
					break;
				case '2':
					std::cout << var2 << foot;
					conv = var2 * ft_to_meter;
					break;
				case '3':
					std::cout << var2 << inch;
					conv = var2 * in_to_meter;
					break;
				default:
					std::cout << "wybrales poza zakresem";
					break;
				}
				sum_of_conv1 += conv;
			}
			else {
				std::cout << "the numbers are equal";
			}
			if (var1 == '|' && var2 == '|') break;
	}
	sum_of_var1 = sum_of_conv + sum_of_conv1;
	std::cout<< std::endl << sum_of_var1;

	return 0;
}

