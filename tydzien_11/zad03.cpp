// Adam Majchrzak 19.05.2020

#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"


using namespace std;
using namespace Numeric_lib;

template<class T> 
struct Triple {
    void operator()(T& a) { a *= 3; }
};

template<class T> 
struct Triple_for_1 {
    T operator()(T& a) { return a *= 3; }
};

template<class T>
struct Triple_for_2 {
    T operator()(T a) { return a *= 3; }
};


int main()
{
    std::cout << "\n";
    double tab[] = { 1.0,2.0,3.0,4.0,5.0 };
    Matrix<double> matrix(tab);
    std::cout << "Moja macierz: " << matrix;
    
    std::cout << std::endl << "\nDla struct Triple: ";
    matrix.apply(Triple<double>());
    std::cout << "\nDziala dla 1:\n----------------------\n\n";
    std::cout << matrix << "\n\n";
    /*matrix = apply(Triple<double>(), matrix);*/


    std::cout << "\n\nDla struct Triple_for_2 dziala dla 1\ndla 2 nie dziala ze wzgledu na brak referencji nie zmienia wartosci"
        << "\n---------------------\n";
    matrix.apply(Triple_for_2<double>());
    std::cout << "\n" << matrix;
    matrix = apply(Triple_for_2<double>(), matrix);
    std::cout << "\n" << matrix;

    std::cout << "\n\n\n\nDla struct Triple_for_1 dziala dla 2\n----------------------\n";
    matrix.apply(Triple_for_1<double>());
    std::cout << "\n" << matrix << "\n";
    matrix = apply(Triple_for_1<double>(), matrix);
    std::cout << "\n" << matrix;
}

