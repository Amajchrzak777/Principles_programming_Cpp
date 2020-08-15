// Adam Majchrzak 23.04.2020

#include "std_lib_facilities.hpp"

vector<int> gv = { 1,2,4,8,16 };

void f(vector<int> v) {
    vector<int> lv(5);
    lv = gv;
    for (int i = 0; i < lv.size(); ++i) {
        std::cout << lv[i] << std::endl;
    }
    vector<int> lv2 = v;
    for (int i = 0; i < lv2.size(); ++i) {
        std::cout << lv2[i] << std::endl;
    }
}

int main()
{
    f(gv);
    int silnia = 1;
    vector<int> vv;
    for (int i = 0; i < 10; ++i) {
        silnia = silnia * (i+1);
        vv.push_back(silnia);
    }
    f(vv);
}

