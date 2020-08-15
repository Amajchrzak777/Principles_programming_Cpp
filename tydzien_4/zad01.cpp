// zad01.cpp Drill ze strony 376
//Adam Majchrzak 20.03.2020

#include "std_lib_facilities.hpp"

struct Point {
	int x;
	int y;

};

int main()
{
	try {
		Point p;
		int x, y;
		string oname;
		std::cout << "Please enter output file name: \n";
		std::cin >> oname;		//nazwa pliku do zapisu
		ofstream ost(oname.c_str()); //ist is an input steram for the file named name
		if (!ost)error("can't open output file ", oname);
		vector<Point> original_points;
		vector<Point> processed_points;
		for (int i = 0; i <= 2; ++i) {
			std::cin >> x >> y;
			original_points.push_back(Point{ x,y });
		}
		std::cout << "It prints ofstream: \n";
		for (int i = 0; i < original_points.size(); ++i) {
			std::cout << '(' << original_points[i].x << ',' << original_points[i].y << ")\n";
			ost << original_points[i].x << " " << original_points[i].y << '\n';	//zapisz wartości do pliku
		}
		ost.close();
		//plik do odczytu
		ifstream ist(oname.c_str());
		if (!ist) error("Can't open input file", oname);
		// x, y;
		std::cout << "It prints ifstream: \n";
		//wczytaj liczby z pliku
		while (ist >> x >> y) {
			processed_points.push_back(Point{ x,y });
		}
		for (int i = 0; i < processed_points.size(); ++i) {
			if (processed_points[i].x != original_points[i].x) throw -1;	//porównaj vectory jak coś nie gra wypisz błąd
			if (processed_points[i].y != original_points[i].y)  throw -1;
			cout << '(' << processed_points[i].x << ',' << processed_points[i].y << ")\n";
		}
		ist.close();
	}
	catch (out_of_range&) {
		cerr << "oops - some vector index out of range\n";
	}
	catch (int x) {
		cout << "processed_points are not equal to original points";
	}
}