// Adam Majchrzak 28.04.2020
//

#include <iostream>

using namespace std;

template  <typename T>
class Number{
public:
    T a;
    Number() : a(0) {}
    Number(T fA) : a(fA) {}
    Number get() const { return T; }
    Number& operator =(const Number& x){
        a = x.a;
        return *this;
    }
    Number operator+(const Number& x) {
        return a + x.a;
    }
    Number operator-(const Number& x) {
        return a - x.a;
    }
    Number operator*(const Number& x) {
        return a * x.a;
    }
    Number operator/(const Number& x) {
        return a / x.a;
    }
    Number operator%(Number<int>& x) {
        return a % x.a;
    }
    /*Int operator%(Int<double>& x) { Suma modulo nie może byc typu double 
        return a % x.a;
    }*/
    friend ostream& operator<<(ostream & os, const Number<T> & show) {
        os << show.a;
        return os;
    }
    friend istream& operator>>(istream& is, Number<T>& enter) {
        is >> enter.a;
        return is;
    }
};

int main()
{
    Number<double> var_to_cin;
    Number<int> var(55);
    std::cout << var << "\tOperator << dziala prawidlowo." << std::endl;
    Number<int> var1(15);
    Number<int> result = var + var1;
    std::cout << result << "\tOperator + dziala prawidlowo." << std::endl;
    Number<double> var2(50);
    Number<double> var3(40);
    Number<double> result1 = var2 - var3;
    std::cout << result1 << "\tOperator - dziala prawidlowo." << std::endl;
    Number<double> result2 = var2 * var3;
    std::cout << result2 << "\tOperator * dziala prawidlowo." << std::endl;
    Number<double> result3 = var2 / var3;
    std::cout << result3 << "\tOperator / dziala prawidlowo." << std::endl;
    Number<int> result4 = var % var1;
    /*Int<double> result5 = var2 % var3;*/
    std::cout << "modulo operator '%' Number<int> " << result4 << std::endl;
    /*std::cout << "modulo operator '%' Number<double>" << result5 << std::endl;*/
    std::cout << "Teraz przetestujmy operator >> wprowadz liczbe calkowita." << std::endl;
    std::cin >> var_to_cin;
    std::cout << var_to_cin;
    return(0);
}