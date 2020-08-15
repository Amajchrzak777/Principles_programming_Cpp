// zadanie 2: wykonac Exercise 9 ze str. 378
// Adam Majchrzak 22.03.2020
// Uwaga: chodzi o to aby czytać jednocześnie z dwóch plików. W każdym z tych plików słowa są posortowane.
// Należy zapisać plik wyjściowy w którym wszystkie słowa także są posortowane oraz zawiera wszystkie słowa z obu plików.
// Uwaga: nie wolno samemu sortować tych słów, ponieważ oba pliki już są posortowane! Wywołanie polecenia sort(..) jest zakazane!

#include "std_lib_facilities.hpp"



struct Words {
	string word1;
};

int main()
{
	Words word;
	string word1;
	string name_of_file;
	string connect;
	vector<Words> words_to_file1;
	vector<Words> read_the_words;
	std::cout << "Put the name of file which connect 2 files: ";
	std::cin >> connect;
	ofstream connectFile(connect.c_str());	//wczytuje do zapisu plik łączący 2 pliki
	if (!connectFile)error("can't open output file ", connect);
	std::cout << "Create two files: \n";
	for (int j = 1; j < 3; ++j) {
		std::cout << "Please enter " << j << " output file name: \n";
		std::cin >> name_of_file;
		ofstream ost(name_of_file.c_str());  //wczytuje do zapisu plik 1 oraz 2 
		if (!ost)error("can't open output file ", name_of_file);
		std::cout << "Put words to the file: \n";
		for (int i = 0; i <= 1; ++i) {
			std::cin >> word1;				
			words_to_file1.push_back(Words{ word1 });  //zapisuje slowa do wektora
		}
		for (int i = 0; i < words_to_file1.size(); ++i) {
			ost << words_to_file1[i].word1 << " "; //zapisuje slowa do plików
		}
		ost.close();	
		ifstream ist(name_of_file.c_str()); //otwieram plik do odczytu
		if (!ist)error("Can't open input file", name_of_file);
		while (ist >> word1) {
			read_the_words.push_back(Words{ word1 });	//wczytuje słowa
			connectFile << word1 << " ";		
		}
		for (int i = 0; i < read_the_words.size(); ++i) {
			cout << read_the_words[i].word1 << " ";//wypisuje
		}
		std::cout << '\n';
		ist.close();
		words_to_file1.clear();  //czyszcze zawartosci wektorow
		read_the_words.clear();
	}
}