// Adam Majchrzak 12.05.2020

#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iterator>


void printMatches(std::string str, std::regex reg) {
    std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
    std::sregex_iterator lastMatch;
    while (currentMatch != lastMatch) {
        std::smatch match = *currentMatch;
        std::cout << match.str() << " ";
        currentMatch++;
    }
    std::cout << std::endl;
}

int main()
{
    std::string str = "Now I will check\nthat std::cout<<endl is equal\nto .";
    std::cout << "My string: " << std::endl << str << std::endl;
   
    std::regex reg("[\\w.:<]+");
    printMatches(str, reg);
   

    std::regex reg1(".");
    printMatches(str, reg1);

    std::regex reg2("\n");
    printMatches(str, reg2);
    std::cout << std::endl;
    std::cout << "As we can see it has difference. ";
    std::cout << std::endl;
}

