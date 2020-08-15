// Adam Majchrzak 16.03.2020

#include "std_lib_facilities.hpp"

//void pobierz_name();
//void pobierz_age();
void wyswietl_name(const vector<string> &, const vector<int> &);
void sort_function(vector<string>, vector<int>);


vector<string> pobierz_name() {
	vector<string> name;
	std::string names;

	for (int i=1; i <= 5; i++) {
		std::cout << "Please write the names of these people: ";
		std::cin >> names;
		name.push_back(names);
	}
	return name;
}

vector<int> pobierz_age() {
	vector<int> age;
	int ages;

	for (int i = 1; i <= 5; i++) {
		std::cout << "Please write the ages of these people: ";
		std::cin >> ages;
		age.push_back(ages);
	}
	return age;
}

void wyswietl_name_age(const vector<string> &name, const vector<int> &age) {
	for (int i = 0; i <= name.size(); ++i) {
		std::cout << name[i] << ", "<< age[i]<<'\n';
	}
}

int main()
{
	vector<string> pobierz_name();
	vector<string> name = pobierz_name();
	vector<int> pobierz_age();
	vector<int> age = pobierz_age();
	sort(name.begin(), name.end());
	sort(age.begin(), age.end());
	wyswietl_name_age(name, age);
}