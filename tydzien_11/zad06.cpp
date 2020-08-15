// Adam Majchrzak 19.05.2020

#include <iostream>
#include <regex>
#include <string>
#include <bitset>

using namespace std;

void function_to_bit(int your_number) {
    int x = static_cast<unsigned long long>(your_number);
    int count = 0;//number of 1 bits
    std::cout << std::endl;
    int i = 0;
    while (true)
    {
        i++;
        unsigned long long bit = x & 1;
        if (bit == 1)
        {
            count++;
            std::cout << "place " << i << ": " << bit;
            std::cout << std::endl;
        }
        else if (bit == 0)
        {
            std::cout << "place " << i << ": " << bit;
            std::cout << std::endl;
        }
        x >>= 1;
        if (i == 32) {
            break;
        }
    }
}

int main()
{
    //some number, i test for 11 
    std::cout << std::endl << "For some number: " << std::endl;
    int bites = 0xb;
    std::cout << bites << '\n';
    std::cout << std::bitset<32>(bites);
    
    //all zeeros 
    std::cout << std::endl << "\n\nFor all zeros: " << std::endl;
    int all_zeross = (1 << 15 & 0b0111111111111111);
    std::cout <<std::endl<< all_zeross << std::endl;
    std::cout << std::bitset<32>(all_zeross);

    //all ones 
    std::cout << std::endl << "\n\nFor all ones: " << std::endl;
    int all_ones = 0xffffffff;
    std::cout << std::endl << all_ones << std::endl;
    std::cout << std::bitset<32>(all_ones);

    //some number, i test for 11 unsigned
    std::cout << std::endl << "\n\nFor some number unsigned: " << std::endl;
    unsigned int bites_unsigned = 0xb;
    std::cout << bites_unsigned << '\n';
    std::cout << std::bitset<32>(bites_unsigned);

    //all zeeros unsigned
    std::cout << std::endl << "\n\nFor all zeros unsigned: " << std::endl;
    unsigned int all_zeross_unsigned = (1 << 15 & 0b0111111111111111);
    std::cout << std::endl << all_zeross_unsigned << std::endl;
    std::cout << std::bitset<32>(all_zeross_unsigned);


    //all ones unsigned
    std::cout << std::endl << "\n\nFor all ones unsigned: " << std::endl;
    unsigned all_ones_unsigned = 0xffffffff;
    std::cout << std::endl << all_ones_unsigned << std::endl;
    std::cout << std::bitset<32>(all_ones_unsigned);

    std::cout << std::endl << "\n\nFor int " << std::endl;
    function_to_bit(bites);
    function_to_bit(~bites);
    function_to_bit(all_zeross);
    function_to_bit(all_ones);


    //for unsigned
    std::cout << std::endl << "For unsigned: " << std::endl;
    function_to_bit(bites_unsigned);
    function_to_bit(~bites_unsigned);
    function_to_bit(all_zeross_unsigned);
    function_to_bit(all_ones_unsigned);

   
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
