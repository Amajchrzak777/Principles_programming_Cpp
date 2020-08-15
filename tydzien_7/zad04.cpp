// Adam Majchrzak 16.04
//

#include <iostream>
#include <vector>

void print_array10(std::ostream& os, int* a) {
	for (int i = 0; i < 10; ++i) {
		os << a[i] << std::endl;
	}
}

void print_array(std::ostream& os, int* a,int n) {
	for (int i = 0; i < n; ++i) {
		os << a[i] << std::endl;
	}
}

void print_vector(std::ostream& os, std::vector<int>& v1) {
	for (int i = 0; i < v1.size(); ++i) {
		os << v1[i] << std::endl;
	}
}

int main()
{
	int* arr = new int[10];
	for (int i = 0; i < 10; ++i) {
		std::cout << arr[i] << std::endl;
	}
	print_array10(std::cout, arr);
	delete[] arr;
	std::cout << std::endl;
	int* arr1 = new int[10];
	for (int i = 0; i < 10; ++i) {
		arr1[i] = 100 + i;
	}
	for (int i = 0; i < 10; ++i) {
		std::cout << arr1[i] << std::endl;
	}
	delete[] arr1;
	std::cout << std::endl;
	int* arr2 = new int[11];
	for (int i = 0; i < 11; ++i) {
		arr2[i] = 100 + i;
	}
	for (int i = 0; i < 11; ++i) {
		std::cout << arr2[i] << std::endl;
	}
	delete[] arr2;
	std::cout << std::endl;
	int* arr3 = new int[20];
	for (int i = 0; i < 20; ++i) {
		arr3[i] = 100 + i;
	}
	print_array(std::cout, arr3, 20);
	delete[] arr3;
	int a = 100;
	std::vector<int> v1;
	for (int i = 0; i < 10; ++i) {
		v1.push_back(a + i);
	}
	std::cout << std::endl;
	print_vector(std::cout, v1);

	std::vector<int> v2;
	for (int i = 0; i < 11; ++i) {
		v2.push_back(a + i);
	}
	std::cout << std::endl;
	print_vector(std::cout, v2);

	std::vector<int> v3;
	for (int i = 0; i < 20; ++i) {
		v3.push_back(a + i);
	}
	std::cout << std::endl;
	print_vector(std::cout, v3);
}
