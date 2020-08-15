// Adam Majchrzak 24.04.2020

#include "std_lib_facilities.hpp"

template<typename T> 
struct S {
    //konstruktor domyślny
    S() {}
    //drill 2
    //konstruktor ze zmienna T 
    S(T v) : val{ v }  {}
    // pobierz bez const dril 5
    T& get();
    // pobierz const
    const T& get() const;
    //drill 9
    void set(const T& val2);
    //drill 10
    S<T>& operator=(const T&);
private:
    //drill 1, 7
    T val;
};

template <typename T>
istream operator>>(istream is, vector<T> s) {
    T val;
    vector<T> vec;
    for (int i = 0; i < s.size(); ++i) {
        is >> val;
        vec.push_back(val);
    }
}

template<typename T>
void read_val(T& v) {
    cin >> v;
}

template <typename T>
ostream operator<<(ostream os, vector<T> s) {
    os << "{ ";
    for (int i = 0; i < s.size(); ++i) {
        os << s[i] << ", ";
    }
    os << " }";
    return os;
}

int main()
{
    //drill 3
    S<int> var_int(5);
    S<char> var_char('a');
    S<double> var_double(1.5);

    ////S<string> var_string = "Adam";
    //vector<int> var_vector;
    //var_vector.push_back(5);
    //S<vector<int>> s_var_vector(var_vector);
    //drill 4
    //std::cout << var_int.val << std::endl;
    //std::cout << var_char.val << std::endl;
    //std::cout << var_double.val << std::endl;
    //drill 8
    std::cout << "Int: "<<var_int.get() << "\n"
       << "Char: " << var_char.get() << "\n"
       << "Double: " << var_double.get() << "\n";
    //read_val(var_char);
    //read_val(var_char);
    //read_val(var_double);*/
    std::cout << "testuje metode set: " << std::endl;
    S<int> var_int1(10);
    S<char> var_char1('x');
    S<double> var_double1(1.35343);
    var_int.set(var_int1.get());
    var_char.set(var_char1.get());
    var_double.set(var_double1.get());
    std::cout << var_int.get() << "   " << var_char.get() << "   " << var_double.get();
    
    //drill 13
    int s11;
    std::cout << std::endl;
    read_val(s11);
    S<int> s1new(s11);
    std::cout << s1new.get() << std::endl;
    //for (int i = 0; i < s_var_vector.get().size(); ++i) {
    //    std::cout << s_var_vector.get()[i] << std::endl;
    //}
    //std::cout << var_int.val << "\t" << var_char.val << "\t"
    //    << var_double.val << "\t";

    //for (int i = 0; i < s_var_vector.val.size(); ++i) {
    //    std::cout << s_var_vector.val[i] << std::endl;
    //}
    vector <int> vec4;
    vec4.push_back(5);
    S <vector<int>> vec5(vec4);
    
    
}
//drill 6
template<typename T> 
const T& S<T>::get() const { 
    return val; 
}

template<typename T>
T& S<T>::get() {
    return val;
}

template<typename T>
void S<T>::set(const T& val2) {
    val = val2;
}

template<typename T>
S<T>& S<T>::operator=(const T& x)
{
    val = x;
    return *this;
}


