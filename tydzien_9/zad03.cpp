//Adam Majchrzak 04.05.2020
//

#include "std_lib_facilities.hpp"


void scopy_list(list<int>& l) {
	vector<double> v1;
	list<int>::iterator it = l.begin();
	while (it != l.end()) {
		v1.push_back(*it);
		++it;
	}
	std::cout << "copy before sort: ";
	for (int i = 0; i < v1.size(); ++i) std::cout << v1[i] << " ";
	sort(v1);
	std::cout << "\ncopy after sort: ";
	for (int i = 0; i < v1.size(); ++i) std::cout << v1[i] << " ";
}

int main()
{
	list<int> x;
	//wrzuc wartosci
	for (int i = 10; i > 0; --i) x.push_back(i);
	//wypisz je
	for (int n : x) std::cout << n << " ";
	std::cout << '\n';
	scopy_list(x);
}

