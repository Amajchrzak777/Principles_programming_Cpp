#include "std_lib_facilities.hpp"
//Adam Majchrzak 04.03.2020

int main()
{
	int x = 0;
	srand(time(NULL));
	std::cout << "Menu: 0-paper 1-rock 2-scissors";
	vector<string> v1;
	v1.push_back("Paper");
	v1.push_back("Rock");
	v1.push_back("Scissors");
	int i_am_also_playing;
	x = std::rand() % 3;
	//std::cout << x <<std::endl;
	std::cout << "Rules :\n" << "Paper beat rock, sccissors beat paper, rock beat scissors, if draw try again\n";
	std::cout << std::endl << "The game with only vector is so boring so i am also playing put the value: ";
	while (true) {
		std::cout << "0/1/2\n";
		std::cin >> i_am_also_playing;
		switch (x) {
		case 0:
			std::cout << "Computer: " << v1[0] << std::endl;
			break;
		case 1:
			std::cout << "Computer: " << v1[1] << std::endl;
			break;
		case 2:
			std::cout << "Computer: " << v1[2] << std::endl;
			break;
		default:
			std::cout << "cos poszlo nie tak";
			break;
		}
		switch (i_am_also_playing) {
		case 0:
			std::cout << v1[0] << std::endl;
			break;
		case 1:
			std::cout << v1[1] << std::endl;
			break;
		case 2:
			std::cout << v1[2] << std::endl;
			break;
		default:
			std::cout << "cos poszlo nie tak";
			break;
		}
		/*if ((v1[x] == 0) == (i_am_also_playing == 1) || (v1[x] == 1) == (i_am_also_playing == 2) || (v1[x] == 2) == (i_am_also_playing == 0)) {
			cout << "Computer win";
		}
		else if ((v1[x] == 1) == (i_am_also_playing == 0) || (v1[x] == 2) == (i_am_also_playing == 1) || (v1[x] == 0) == (i_am_also_playing == 2)) {
			{
				cout << "I won";
			}
		else {
			cout << "Draw, try again";
		}*/
		if (i_am_also_playing == '|')return 0;
		}
		return 0;
	}
