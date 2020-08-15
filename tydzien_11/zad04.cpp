// Adam Majchrzak 19.05.2020

#include <iostream>
#include <iomanip>
#include <bitset>


using namespace std;

//drill 1
void _01() {
    int v = 1;
    for (int i = 0; i < sizeof(v) * 8; ++i) {
        std::cout << v << ' ';
        v <<= 1;
    }
}

//drill 2
void _02() {
    unsigned int v = 1;
    for (int i = 0; i < sizeof(v) * 8; ++i) {
        std::cout << v << ' ';
        v <<= 1;
    }
}

//drill 3
void _03() {
    short unsigned int bites = 0xffff;
    std::cout << "hex: 0x" <<hex << bites << " \tdec: " << dec << bites<< "\tbites: " << bitset<16>(bites) <<std::endl;
    bites = 0x0001;
    std::cout << "hex: 0x" << hex << bites << " \tdec: " << dec << bites << "\t\tbites: " << bitset<16>(bites)<< std::endl;
    bites = 0x8000;
    std::cout << "hex: 0x" << hex << bites << " \tdec: " << dec << bites << "\tbites: " << bitset<16>(bites) << std::endl;
    bites = 0x0000;
    std::cout << "hex: 0x" << hex << bites << " \tdec: " << dec << bites << "\t\tbites: " << bitset<16>(bites) << std::endl;
    bites = 0xff00;
    std::cout << "hex: 0x" << hex << bites << " \tdec: " << dec << bites << "\tbites: " << bitset<16>(bites) << std::endl;
    bites = 0x5555;
    std::cout << "hex: 0x" << hex << bites << " \tdec: " << dec << bites << "\tbites: " << bitset<16>(bites) << std::endl;
    bites = 0xaaaa;
    std::cout << "hex: 0x" << hex << bites << " \tdec: " << dec << bites << "\tbites: " << bitset<16>(bites) << std::endl;
}

//drill 5
void _04()
{
    /*Do 3 and 4 using bit manipulation operations( |, &, << ) and (only)the
        literals 1 and 0.*/
    std::cout << std::endl << "hex: 0x" << hex << (1 << 15 | 0b1111111111111111)
        << dec << " \tdec: " << (1 << 15 | 0b1111111111111111);

    std::cout << std::endl << "hex: 0x" << hex << (1 << 15 & 0b0111111111111111 | 0b0000000000000001)
        << dec << " \tdec: " << (1 << 15 & 0b0111111111111111 | 0b0000000000000001);
    //std::cout << std::endl << "hex: 0x" << hex << (1 << 15 & 0b0111111111111111 | 0b0000000000000001);
    std::cout << std::endl << "hex: 0x" << hex << (1 << 15)
        << dec << " \tdec: " << (1 << 15);
    //std::cout <<std::endl << "hex: 0x" << hex << (1<<15);
    std::cout << std::endl << "hex: 0x" << hex << (1 << 15 & 0b0111111111111111)
        << dec << " \tdec: " << (1 << 15 & 0b0111111111111111);
    //std::cout << std::endl << "hex: 0x" << hex << (1<<15 & 0b0111111111111111);
    std::cout << std::endl << "hex: 0x" << hex << (0b1111111111111111 & 0b0101010101010101)
        << dec << " \tdec: " << (0b1111111111111111 & 0b0101010101010101);
    //std::cout << std::endl << "hex: 0x" << hex << (0b1111111111111111 & 0b0101010101010101);
    std::cout << std::endl << "hex: 0x" << hex << (0b1111111111111111 & 0b1010101010101010)
        << dec << " \tdec: " << (0b1111111111111111 & 0b1010101010101010);
    //std::cout << std::endl << "hex: 0x" << hex <<(0b1111111111111111 & 0b1010101010101010);
}
int main()
{
    _01();
    std::cout << std::endl;
    _02();
    std::cout << std::endl;
    _03();
    std::cout << std::endl;
    _04();
    std::cout << std::endl;
}

