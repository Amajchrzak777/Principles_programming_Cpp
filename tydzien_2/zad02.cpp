//Adam Majchrzak 06.03.2020

#include "std_lib_facilities.hpp"
//#include <iostream>
//#include <vector>


int main()
{
	try {
		vector<int> v1;
		int note_count = 0;
		int how_many_values;
		double sum = 0;
		std::cout << "Wprowadz ile ocen liczb wprowadzic: " << std::endl;
		std::cin >> note_count;
		//Zapisuje liczby do wektora
		for (int i = 0; i < note_count; ++i) {
			int note = 0;
			std::cin >> note;
			v1.push_back(note);
		}

		std::cout << "Please enter the number of values you want to sum: ";
		std::cin >> how_many_values;
		for (int j = 0; j < how_many_values; j++) {
			sum += v1[j];
		}
		std::cout << "The sum of the first " << how_many_values << " numbers " << sum << ".";
		return 0;
	}
	catch (exception & e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}

