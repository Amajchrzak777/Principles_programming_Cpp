//Adam Majchrzak 16.03.2020

#include "std_lib_facilities.hpp"
#include "my.h"

void print_foo() {
	int foo = 7;
	std::cout << foo << std::endl;
}

void print(int i) {
	std::cout << i << std::endl;
}

void swap_v(int a, int b) {
	int temp;
	std::cout << "a: " << a << std::endl << "b: " << b << std::endl;
	temp = a;
	a = b;
	b = temp;
	std::cout << "a: " << a << std::endl << "b: " << b << std::endl;
}

void swap_r(int& a, int& b) {
	int temp;
	std::cout << "a: " << a << std::endl << "b: " << b << std::endl;
	temp = a;
	a = b;
	b = temp;
	std::cout << "a: " << a << std::endl << "b: " << b << std::endl;
}

void swap_cr(const int& a, const int& b) {
	/*int temp;
	temp = a;
	a = b;			//zakomentowalem poniewaz program nie chciał tego kompilowac
	b = temp;*/
	std::cout << "a: " <<a << std::endl << "b: "<< b;
}