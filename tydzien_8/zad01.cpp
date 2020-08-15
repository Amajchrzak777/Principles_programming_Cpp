// Adam Majchrzak 23.04.2020

#include "std_lib_facilities.hpp"

int ga[10] = { 1,2,4,8,16,32,64,128,256,512 };

void f(int a[], int n) {
    int la[10];
    for (int i = 0; i < n; ++i) {
        la[i] = ga[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cout << la[i] << std::endl;
    }
    int* p = new int(10);
    p = *&a;
    for (int i = 0; i < n; ++i) {
        std::cout << p[i] << std::endl;
    }
    /*for (int i = 0; i < 10; ++i) {
        delete[] &la[i];
    }

    delete [] la;*/
}

int main()
{
    f(ga, 10);
    long int silnia = 1;
    int* aa = new int[10];
    for (int i = 0; i < 10;++i) {
        silnia = silnia*(i+1);
        aa[i] = silnia;
    }
    f(aa, 10);
}
