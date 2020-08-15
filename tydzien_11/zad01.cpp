// Adam Majchrzak 18.05.2020
//

#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>
#include <cmath>

using namespace std;

using namespace Numeric_lib;
//using cmplx = complex<double>;
//drill1
void _01(){
    std::cout << "sizes: \n" << "int - " << sizeof(int) << "\n"
        << "float - " << sizeof(float) << "\n"
        << "double - " << sizeof(double) << "\n"
        << "char - " << sizeof(char) << "\n"
        << "short int - " << sizeof(short) << "\n"
        << "long int - " << sizeof(long) << "\n"
        << "long long  int - " << sizeof(long long) << "\n"
        << "int * - " << sizeof(int*) << "\n"
        << "double * - " << sizeof(double*);
}

//drill2
void _02() {
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int, 2> d(10, 10);
    Matrix<int, 3> e(10, 10, 10);

        std::cout << "\n\nsizes: \n" << "Matrix<int> a(10) " << sizeof(a) << "\n"
            << "Matrix<int> b(100) " << sizeof(b) << "\n"
            << "Matrix<double> c(10) " << sizeof(c) << "\n"
            << "Matrix<int, 2> d(10, 10) " << sizeof(d) << "\n"
            << "Matrix<int, 3> e(10,10,10) " << sizeof(e);
        //drill 3
        std::cout << "\nNumber of elements of: ";
        std::cout << "\na: " << a.size() /*<< "columns: " << a.dim2()*/
            << "\nb: " << b.size() /*<< "columns: " << a.dim2()*/
            << "\nc: " << c.size() /*<< "columns: " << a.dim2()*/
            << "\nd: " << d.size() /*<< "columns: " << a.dim2()*/
            << "\ne: " << e.size() << "\n"; /*<< "columns: " << a.dim2()*/;
}

//drill 4
void _03() {
    int number, n, i = 0;
    std::cout << "\nHow many numbers do you want to enter ? ";
    std::cin >> n;
    std::cout << "Enter int, program will compute square of the number.\n";
    while (i<n) {
        std::cin >> number;
        if (number >= 0) {
            std::cout << sqrt(number);
            std::cout << '\n';
        }
        else {
            std::cout << "number must be integer and > 0\n";
        }
        i++;
    }
}

//drill 5
void _04() {
    float number;
    int i = 0;
    std::cout << "Enter 10 floats\n";
    Matrix<double> a(10);
    for (int i = 0; i < a.size(); ++i) {
        std::cin >> number;
        a[i] = number;
    }
    std::cout << a;
    cout << "\n";

}

//drill 6
void _05() {
    int n, m;
    std::cout << "Enter n, m: ";
    std::cin >> n >> m;
    Matrix<double, 2> matrix(n, m);
    for (int i = 0; i < matrix.dim1(); i++) {
        for (int j = 0; j < matrix.dim2(); j++) {
            matrix(i, j) = (i + 1) * (j + 1);
            cout << matrix(i, j);
        }
        cout << '\n';
    }
    
}

//drill 7
void _06() {
    complex<double> sum = 0;
    complex<double> x;
    Matrix<complex<double>> a(10);
    std::cout << "Read 10 complex numbers i will compute sum of it";
    for (int i = 0; i < 10; ++i) {
        std::cin >> x;
        a[i] = x;//complex
    }
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
    }
    std::cout << "Sum: " << sum;
}

//dril 8
void _07() {
    int n;
    Matrix<int, 2> m(2, 3);
    //cout << m.dim1();
    std::cout << "Enter 6 values to matrix: \n";
    for (int i = 0; i < m.dim1(); ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> n;
            m[i][j] = n;
        }
    }
    std::cout << m;
}

int main()
{
    _01();
    _02();
    _03();
    _04();
    _05();
    _06();
    _07();
}

