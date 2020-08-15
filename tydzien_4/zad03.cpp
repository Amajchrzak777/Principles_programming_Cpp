// Adam Majchrzak 22.03.2020
//

#include "std_lib_facilities.hpp"

int main() {
	char ch = 0;
	double sum = 0;
	string iname;
	std::cout << "Please enter the name of file ";
	std::cin >> iname;
	ifstream ist( iname.c_str());
	cout << "wypisuje co sie w pliku znajduje \n";
	while (ist.get(ch)) {
		if (isdigit(ch)) {
			ist.unget();
			double x;
			ist >> x;
			sum += x;
		}
	}
	cout << sum;
	//cout << "\nGotowe\n";
	ist.close();
}