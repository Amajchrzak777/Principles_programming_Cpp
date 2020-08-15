#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

//Adam Majchrzak 04.03.2020

using namespace std;

inline void keep_window_open()

{ char ch; cin>>ch; }

int main(){
    int val1;
    int val2;
    cout<<"Enter first integer value. ";
    cin >> val1;
    cout<<"Enter second integer value. ";
    cin >> val2;
    cout << "sum equals :" << val1+val2<<endl;
    cout << "difference equals: " << val1-val2<<endl;
    cout << "product equals: " << val1*val2 <<endl;
    cout << "ratio equals: " << val1/val2 <<endl;
    if(val1>val2){
        cout<< "val1 is larger than val2";
    }else if(val1<val2){
        cout<< "val2 is larger than val1";
    }else{
        cout<< "val1 equals val2";
    }
    cout<<endl;
    double val3;
    double val4;
    cout<<"Enter first integer value. ";
    cin >> val3;
    cout<<"Enter second integer value. ";
    cin >> val4;
    cout << "sum equals :" << val3+val4<<endl;
    cout << "difference equals: " << val3-val4<<endl;
    cout << "product equals: " << val3*val4 <<endl;
    cout << "ratio equals: " << val3/val4 <<endl;
    if(val3>val4){
        cout<< "val1 is larger than val2";
    }else if(val3<val4){
        cout<< "val2 is larger than val1";
    }else{
        cout<< "val1 equals val2";
    }
    return 0;
}
//The difference is:
//-ratio if it's integer value for example 2/3 = 0 if it's double it equal 2/3

