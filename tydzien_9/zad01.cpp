// Adam Majchrzak 03.05.2020
//

#include "std_lib_facilities.hpp"

//drill 6
template<typename Iter1, typename Iter2>
Iter2 scopy(Iter1 f1, Iter1 e1, Iter2 f2) {
	while (f1 != e1) {
		*f2 = *f1;
		++f1; ++f2;
	}
	return f2;
}

int main()
{
	//drill 1-3
	array<int, 10> arr = { 0,1,2,3,4,5,6,7,8,9 };
	std::cout << "array: ";
	for (const auto& a : arr) std::cout << arr[a] << " ";

	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	std::cout << "\nvector: ";
	for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";

	list<int> l = { 0,1,2,3,4,5,6,7,8,9 };
	list<int>::iterator ptr_l2;
	std::cout << "\nlist: ";
	for (ptr_l2 = l.begin(); ptr_l2 != l.end(); ++ptr_l2) {
		std::cout << *ptr_l2 << " ";
	}
	//drill 4
	array<int, 10> arr1 = arr;
	//std::cout << "copy array: ";
	//for (const auto& a : arr1) std::cout << arr1[a] << ", ";

	vector<int> v1 = v;
	//std::cout << "\ncopy vector: ";
	//for (int i = 0; i < v1.size(); ++i) std::cout << v1[i] << ", ";

	list<int> l1 = l;
	/*std::cout << "\nlist: ";
	for (int i : l1) cout << l1 << ", ";*/


	//drill 5
	array<int, 10>::iterator ptr_arr;
	std::cout << "\ncopied array + 2: ";
	for (ptr_arr = arr1.begin(); ptr_arr < arr1.end(); ++ptr_arr) {
		std::cout << *ptr_arr + 2 << " ";
	}

	vector<int>::iterator ptr_vec;
	std::cout << "\ncopied vector + 3: ";
	for (ptr_vec = v1.begin(); ptr_vec < v1.end(); ++ptr_vec) {
		std::cout << *ptr_vec + 3 << " ";
	}

	list<int>::iterator ptr_l;
	std::cout << "\ncopied list + 5: ";
	for (ptr_l = l1.begin(); ptr_l != l1.end(); ++ptr_l) {
		std::cout << *ptr_l + 5 << " ";
	}
	//drill 7
	vector<int>::iterator v_copy;
	v_copy = scopy(arr.begin(), arr.end(), v1.begin());

	vector<int>::iterator ptr_vec1;
	std::cout << "\ncopied array, arr to vec: ";
	for (ptr_vec1 = v1.begin(); ptr_vec1 < v1.end(); ++ptr_vec1) {
		std::cout << *ptr_vec1 << " ";
	}

	array<int, 10>::iterator arr_copy;
	arr_copy = scopy(l1.begin(), l1.end(), arr.begin());

	array<int, 10>::iterator ptr_arr1;
	std::cout << "\ncopied list, list to arr: ";
	for (ptr_arr1 = arr.begin(); ptr_arr1 < arr.end(); ++ptr_arr1) {
		std::cout << *ptr_arr1 << " ";
	}
	//drill 8
	int n = 3;
	auto result = find(begin(v), end(v), n);
	if (result != end(v)) std::cout << "\nPosition of v: " << result - v.begin();

	int n1 = 27;
	auto result1 = find(begin(l), end(l), n1);
	if (result1 != end(l)) std::cout << "\nl contains: " << n1 << '\n';
	else std::cout << "\nl does not contain: " << n1 << '\n';


	int n2 = 5;
	auto result2 = find(begin(l), end(l), n2);
	if (result2 != end(l)) std::cout << "\nPosition of l: " << n2;
	else std::cout << "l does not contain, no posstion. ";
}
