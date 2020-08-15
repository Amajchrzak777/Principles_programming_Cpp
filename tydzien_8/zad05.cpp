// Adam Majchrzak 25.04.2020

#include "std_lib_facilities.hpp"

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
    int x,y;
    vector<int> vu = { 1,2,3,45,6 };
    vector<int> vt = {13,3,56,7,7};
    vector<double> vx = { 1.2,1.3 };
    vector<double> vy = { 1.2,1.3 };
    x = template_function(vu, vt);
    y = template_function(vx, vy);
    std::cout << x << "\n" << y;
}
