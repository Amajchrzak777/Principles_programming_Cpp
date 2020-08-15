// Adam Majchrzak 12.05.2020
//

#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
using namespace std;
// accept a pattern and a set of lines from input
// check the pattern and search for lines with that pattern
int main()
{
    regex pattern;
    string pat;
    cout << "enter pattern: ";
    string n;
    getline(cin, pat); // read pattern
    
    try {
        pattern = pat; // this checks pat
        cout << "pattern: " << pat << '\n';
    }
    catch (...) {
        cout << pat << " is not a valid regular expression\n";
        exit(1);
    }

    std::cout << "\n---------------------\n";
    cout << "Podaj nazwe pliku: (plik.txt)";
    cin >> n;
    ifstream in{ n.c_str() }; // open the file
    if (!in) {
        cerr << "no " << n << '\n';
        exit(1); // terminate the program
    }
    std::cout << "\n---------------------\n";
    cout << "now enter lines:\n";
    int lineno = 0;
    for (string line; getline(in, line); ) {
        ++lineno;
        smatch matches;
        if (regex_search(line, matches, pattern)) {
            cout << "line " << lineno << ": " << line << '\n';
            for (int i = 0; i < matches.size(); ++i)
                cout << "\tmatches[" << i << "]: "
                << matches[i] << '\n';
        }
        else
            cout << lineno << ": " <<"didn't match\n";
    }
}