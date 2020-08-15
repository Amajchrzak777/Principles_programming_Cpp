// Adam Majchrzak 28.04.2020
//

#include "std_lib_facilities.hpp"

using namespace std;

template  <typename T>
class Number {
public:

    T a;
    Number() : a(0) {}
    Number(T fA) : a(fA) {}
    Number get() const { return T; }
    Number& operator =(const Number& x) {
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
    friend ostream& operator<<(ostream& os, const Number<T>& show) {
        os << show.a;
        return os;
    }
    friend istream& operator>>(istream& is, Number<T>& enter) {
        is >> enter.a;
        return is;
    }

    Number operator +=(const Number<T>& x) {
        return a += x.a;
    }

    //template<typename TV, typename U>
    //TV template_function(vector<TV> vt, vector<U> vu) {
    //    TV sum = 0;
    //    for (int i = 0; i < vt.size(); ++i) {
    //        sum += vt[i] + vu[i];
    //    }
    //    return sum;
    //}
};

template<typename T, typename U>
T template_function(vector<T> vt, vector<U> vu) {
    T sum = 0;
    for (int i = 0; i < vt.size(); ++i) {
        sum += vt[i] + vu[i];
    }
    return sum;
}

int main()
{
    Number<double> var2(50.5);
    Number<double> var3(40.6565);
    std::cout << "Testuje dla wartosci int." << std::endl;
    vector<Number<int>> v1;
    vector<Number<int>> v2;
    v1.push_back(Number<int>(5));
    v1.push_back(Number<int>(10));
    v2.push_back(Number<int>(7));
    v2.push_back(Number<int>(12));
    std::cout << template_function(v1, v2) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    vector<Number<double>>v3;
    vector<Number<double>>v4;
    v3.push_back(Number<double>(var2));
    v4.push_back(Number<double>(var3));

    std::cout << "Testuje dla wartosci typu double." << std::endl;
    std::cout << template_function(v3, v4); ;
    
    return(0);
}