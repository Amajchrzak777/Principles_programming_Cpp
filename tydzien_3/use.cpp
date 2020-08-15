#include <iostream>
#include "my.h"
#include "std_lib_facilities.hpp"

namespace X {
	int var;
	void print() {
		std::cout << var << std::endl;
	}
}
namespace Y {
	int var;
	void print() {
		std::cout << var << std::endl;
	}
}
namespace Z {
	int var;
	void print() {
		std::cout << var << std::endl;
	}
}

using namespace X;

int main() {
	print_foo();
	print(99);
	//char cc;
	//std::cin >> cc;
	int x = 7;
	int y = 9;
	swap_v(x, y);
	swap_r(x, y);
	//swap_cr(x, y);
	swap_v(7, 9);
	//swap_r(7, 9); //nie skompiluje si� bo przez wartosc a nie zmienna (pass_by_reference)
	//swap_cr(7, 9);
	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
	//swap_r(cx, cy); //nie skompiluje si� bo const int (pass_by_reference)
	//swap_cr(cx, cy);
	swap_v(7.7, 9.9);
	//swap_r(7.7, 9.9);	//nie skompliluje si� bo double to int (pass_by_reference)
	//swap_cr(7.7, 9.9);
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
	//swap_r(dx, dy); //nie skompiluje si� bo konwersja z double to int (pass_by_reference)
	//swap_cr(dx, dy);
	swap_v(7.7, 9.9);
	//swap_r(7.7, 9.9); // nie skompliluje si� bo konwersja z double to int (pass_by_reference)
	//swap_cr(7.7, 9.9);
	int var;			//drill zadanie 3
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	Y::print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		using Z::print;
	}
	Y::print();
	X::print();
}

//wszystkie swap_cr si� nie skompiluj� poniewa� const nie mog� 
//przypisa� do innej zmiennej aby zmieni� wwarto��
//wszystkie swap_v si� skompiluja poprawnie
//zostawi�em w programie tylko te kt�re si� kompiluj�