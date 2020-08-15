// zad01.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Adam Majchrzak 05.03.2020

#include "std_lib_facilities.hpp"

int main()
{

	try {
		/*std::cout << "Success!\n";
		std::cout << "Success!\n";
		std::cout << "Success" << "!\n";
		std::cout << "success" << "!\n";
		*/
		//int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
		//vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";
		//NIE WIEM O CO CHODZI if (cond) cout << "Success!\n"; else cout << "Fail!\n";
		//bool c = false; if (c==false) cout << "Success!\n"; else cout << "Fail!\n";
		//string s = "ape"; string c = "fool"; if (c.size() > s.size()) cout << "Success!\n"; else cout << "Fail!\n";
		//string s = "ape"; if (s != "fool") cout << "Success!\n";
		//string s = "ape"; if (s != "fool") cout << "Success!\n";
		//string s = "ape"; if (s + "fool" != s) cout << "Success!\n";
		//vector<char> v(5); for (int i = 0; 0 > v.size(); ++i);  cout << "Success!\n"; 
		//vector<char> v(5); for (int i = 0; i <= v.size(); ++i) { cout << "Success!\n"; }
		//string s = "Success!\n"; for (int i = 0; i < s.size(); ++i) { cout << s[i]; }
		//if (true) cout << "Success!\n"; else cout << "Fail!\n";
		//int x = 2000; int c = x; if (c == 2000) cout << "Success!\n";
		//string s = "Success!\n"; for (int i = 0; i < 10; ++i) { cout << s[i]; }
		//vector<int> v(5); for (int i = 0; i <= v.size(); ++i) { cout << "Success!\n"; }
		//int i = 0; int j = 9; while (i < 10) { ++i; if (j < i) cout << "Success!\n"; }
		//int x = 2; double d = 5.0 / (double(x) -2.0); if (d != 2.0 * double(x) + 0.5) cout << "Success!\n";
		//string s = "Success!"; for (int i = 0; i <= s.size(); ++i) { cout << s[i]; }
		//int i = 0; int j = 0; while (i < 10){ ++i; if (j < i) cout << "Success!\n";}
		//int x = 4; double d = 5.0 / (double(x) - 2.0); if (d != 2.0 * x + 0.5) cout << "Success!\n";
		cout << "Success!\n";

		return 0;
	}
	catch (exception & e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
