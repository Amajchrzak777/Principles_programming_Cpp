// Adam Majchrzak 16.04.2020,
//

#include <cmath>
#include <iostream>
#include <vector>

void print_array(std::ostream& os, int* a, int n) {
	for (int i = 0; i < n; ++i) {
		os << a[i] << std::endl;
	}
}

void print_vector(std::ostream& os, std::vector<int> v1) {
	for (int i = 0; i < v1.size(); ++i) {
		os << v1[i] << std::endl;
	}
}

int main()
{
	int x = 7;
	int* p1 = &x;
	std::cout << "value p1: " << *p1 << " value x: " << x;
	int* arr = new int[7];
	for (int i = 0; i < 7; ++i) {
		arr[i] = pow(2, i);
	}
	int* p2 = *&arr;
	std::cout << std::endl;
	print_array(std::cout, arr, 7);
	print_array(std::cout, p2, 7);

	int* p3 = p2;
	p1 = p2;
	p3 = p2;
	std::cout << "value p1 : " << *p1 << " value p2: " << *p2;

	delete[] arr;

	int* arr1 = new int[10];
	for (int i = 0; i < 10; ++i) {
		arr1[i] = pow(2, i);
	}
	int* p4 = *&arr1;

	int* arr2 = new int[10];
	int* p5 = *&arr2;

	p5 = p4;
	print_array(std::cout, p5, 10);
	int a;
	std::cout << std::endl;
	std::vector<int> v2;
	for (int i = 0; i < 10; ++i) {
		v2.push_back(pow(2, i));
	}
	print_vector(std::cout, v2);

	std::vector<int>* v1 = &v2;

	std::vector<int> v4[10];
	std::vector<int>* v3 = *&v4;

	*v4 = v2;
	print_vector(std::cout, *v4);
}	

