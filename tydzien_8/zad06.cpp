// Adam Majchrzak 25.04.2020
//

#include "std_lib_facilities.hpp"

class Int
{
public:
    int a;
    Int() : a(0) {}
    Int(int fA);
    Int get() const { return a; }
    Int& operator =(const Int& x)
    {
        a = x.a;
        return *this;
    }
    Int operator+(const Int& x) {
        return a + x.a;
    }
    Int operator-(const Int& x) {
        return a - x.a;
    }
    Int operator*(const Int& x) {
        return a * x.a;
    }
    Int operator/(const Int& x) {
        return a / x.a;
    }
};

Int::Int(int fA)
    : a( fA )
{
}

ostream& operator<<(ostream& os, const Int& show) {
    os << show.a;
    return os;
}

istream& operator>>(istream& is, Int& enter) {
    is >> enter.a;
    return is;
}
int main()
{
    Int var_to_cin;
    Int var(55);
    std::cout << var << "\tOperator << dziala prawidlowo." << std::endl; 
    Int var1(15);
    Int result = var + var1;
    std::cout << result << "\tOperator + dziala prawidlowo."<< std::endl;
    Int var2(50);
    Int var3(40); 
    Int result1 = var2 - var3;
    std::cout << result1 << "\tOperator - dziala prawidlowo."<<std::endl;
    Int result2 = var2 * var3;
    std::cout << result2 << "\tOperator * dziala prawidlowo."<<std::endl;
    Int result3 = var2 / var3;
    std::cout << result3 << "\tOperator / dziala prawidlowo."<<std::endl;

    std::cout << "Teraz przetestujmy operator >> wprowadz liczbe calkowita." << std::endl;
    std::cin >> var_to_cin;
    std::cout << var_to_cin;
    return(0);
}