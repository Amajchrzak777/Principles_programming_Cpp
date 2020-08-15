// Adam Majchrzak 23.03.2020
//

#include "std_lib_facilities.hpp"

struct Osoba {
	string last_name;
	string name;
	string telephone_number;
	string email_adress;
};

int main()
{
	int a, b, c, d;
	int birth_year;
	birth_year = 1999;
	int age; 
	age = 20;
	std::cout << "hex \t" << std::hex << birth_year /*<< std::dec << '\t' << age*/ << '\n'
		<< "octal \t" << std::oct << birth_year /*<< std::dec << '\t' << age*/ << '\n'
		<< "decimal " << std::dec << birth_year; /*<< std::dec << '\t' << age*/

	std::cout << '\n' << "hex \t" << std::hex << age << '\n'
		<< "octal \t" << std::oct << age << '\n'
		<< "decimal " << std::dec << age;


	std::cout << '\n';
	std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
	std::cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
	//explain to Drill 8. 1 wczytanie to jest standardowa liczba dziesiętna, potem mamy
	//konwersje na liczbe w zapisie ósemkowym, następnie konwersja na szestnastowy,
	//który do momentu konwersji na inny będzie używany domyślnie, zatem zmienna d również jest
	//w systemie szesnatkowym

	std::cout << "defaultfloat form " << 1234567.89 << '\t'
		<< "fixed form " << fixed << 1234567.89 << '\t'
		<< "scientific form " << scientific << 1234567.89 << '\n';
	//default form, czyli tzw. forma domyślna zwraca nam 2 miejsca po przecinku, 3 miejsce zaokrągla w górę lub w dół
	//fixed form zwraca nam wszystkie miejsca po przecinku które dany typ obsługuje, w przypadku floata jest to 6 liczb, w naszym przykładzie dodaje 0 na końcu
	//scientific form zwraca nam zawsze liczbe w notacji wykładniczej, maksymalna liczbe miejsc po przecinku w zależności od typu
	//wedlug mnie najdokładniejszy i najbardziej czytelny jest typ fixed
	string last_name, name;
	string telephone_number;
	string email_adress;
	vector<Osoba> dane;
	std::cout << "Wprowadzd najpierw nazwisko, imie, telefon oraz email: ";
	for (int i = 1; i <= 5; ++i) {
		cin >> last_name >> name >> telephone_number >> email_adress;
		dane.push_back(Osoba{ last_name,name,telephone_number,email_adress });
	}
	for (int i = 0; i < dane.size(); ++i) {
		cout << i+1 << ". person : "<< setw(8) << dane[i].last_name 
			<< "\t|\t" << setw(8) << dane[i].name 
			<< "\t|\t" << setw(8) << dane[i].telephone_number 
			<< "\t|\t" << setw(8) << dane[i].email_adress << '\n';
 	}
}