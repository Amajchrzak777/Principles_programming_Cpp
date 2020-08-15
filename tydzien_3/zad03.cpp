//Adam Majchrzak 17.03.2020
//wersja 9.4.1
//wersja 9.4.2
//wersja 9.4.3
// nie udało mi się wykonać wersji 9.7.1 oraz 9.7.4 
// zatem zostawiam w ostatniej wersji 9.4.3
#include "std_lib_facilities.hpp"


class Date {
	int y, m, d;
	bool is_valid();
public:
	Date(int year, int month, int day);
	class Invalid {};
	void add_day(int n);
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
};

Date::Date(int year, int month, int day)
{
	y = year;
	m = month;
	d = day;
	if (!is_valid()) throw Invalid{};
}

bool Date::is_valid() {
	if (m < 1 || m > 12) return false;
	if (d < 1 || d > 31) return false;
}

void Date::add_day(int n)
{
	d += n;
}
////////////////////////////////////////////////////////////

void init_day(Date& dd, int y, int m, int d) {
	int year, day, month;
	//year = dd.y, month = dd.m, day = dd.d;
	//std::cout << std::endl << dd.y << dd.m << dd.d;
	if ((m < 1) || (m > 12)) {
		cout << "scope of m - [1, 12]";
		exit(2);
	}
	if ((d < 1) || (d > 31)) {
		cout << "scope of d - [1, 31]";
		exit(1);
	}
}
/////////////////////////////////////////////////////////////

int main()
{
	try {
		Date today{ 2020, 03, 18 };
		std::cout << "today: "<< '\n' <<"year: " << today.year() << '\n';
		std::cout << "month: " << today.month() << '\n';
		std::cout << "day: " << today.day() << '\n';
		init_day(today, 2008, 3, 30);
		Date tomorrow{2020,03,18};
		tomorrow.add_day(1); //sprawdzam czy metoda add_day(n) działa, działa poprawnie
		std::cout << "tomorrow: "<< '\n' <<"year: " << tomorrow.year() << '\n';
		std::cout << "month: " << tomorrow.month() << '\n';
		std::cout << "day: " << tomorrow.day() << '\n';
	}
	catch (Date::Invalid) {
		runtime_error("invalid date");
	}
}
