// Adam Majchrzak 18.05.2020
//

#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

//dziala dla obu
double triple(double& d) {
    return  d *= 3;
}
//dziala tylko dla jednej
void triple_for_1(double& d) {
    d *= 3;
}

double triple_for(double d) {
    return  d *= 3;
}

int main()
{
    std::cout << "\n";
    double tab [] = { 1.0,2.0,3.0,4.0,5.0 };
    Matrix<double> matrix(tab);
    std::cout << "Moja macierz: "<<matrix;
    matrix.apply(triple);
    std::cout << "\n\ntripl(double& d) - Dziala dla obu:\n----------------------\n\n" << matrix;
    matrix = apply(triple, matrix);
    std::cout << "\n" << matrix;

    std::cout << "\n\ntriple_for_1(double &d) - Dziala dla jednej\n----------------------\n";
    matrix.apply(triple_for_1);
    std::cout << "\n" << matrix << "\n";


    std::cout << "\n\n funkcja triple_for(double d) - ktora nie pobiera referencji wlacza sie ale jak widac dziala tylko dla jednej: \n --------------------- \n";
    matrix.apply(triple_for);
    std::cout << std::endl << matrix;
    matrix = apply(triple_for, matrix);
    std::cout << std::endl << matrix;
}

