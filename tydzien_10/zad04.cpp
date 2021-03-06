﻿// Adam Majchrzak 12.05.2020
//


#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>
#include <regex>

using namespace std;

typedef vector<string>::const_iterator Line_iter;

class Message { // a Message points to the first and the last lines of a message
    Line_iter first;
    Line_iter last;
public:
    Message(Line_iter p1, Line_iter p2) :first{ p1 }, last{ p2 } { }
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }
    // . . .
};

using Mess_iter = vector<Message>::const_iterator;
struct Mail_file { // a Mail_file holds all the lines from a file
 // and simplifies access to messages
    string name; // file name
    vector<string> lines; // the lines in order
    vector<string> names;
    vector<Message> m; // Messages in order
    Mail_file(const string& n); // read file n into lines

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

int is_prefix(const string& s, const string& p)
// is p the first part of s?
{
    const int n = p.size();
    if (string(s, 0, n) == p) return n;
    return 0;
}

// find the name of the sender in a Message;
// return true if found
// if found, place the sender’s name in s:
bool find_from_addr(const Message* m, string& s) {
    for (Line_iter p = m->begin(); p != m->end(); ++p)
        if (int n = is_prefix(*p, "From: ")) {
            s = string(*p, n);
            return true;
        }
    return false;
}

// return the subject of the Message, if any, otherwise "":
string find_subject(const Message* m) {
    for (Line_iter p = m->begin(); p != m->end(); ++p)
        if (int n = is_prefix(*p, "Subject: ")) return string(*p, n);
    return "";
}



int main()
{
    Mail_file mfile{ "mymail.txt" }; // initialize mfile from a file
     // first gather messages from each sender together in a multimap:
    
    multimap<string, const Message*> sender;
    for (const auto& m : mfile) {
        string s;
        if (find_from_addr(&m, s))
            sender.insert(make_pair(s, &m));
    }
    // now iterate through the multimap
    // and extract the subjects of John Doe’s messages:
    auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
    for (auto p = pp.first; p != pp.second; ++p)
        cout << find_subject(p->second) << '\n';
}

Mail_file::Mail_file(const string& n) : name(n)
{
    ifstream in{ n.c_str() }; // open the file
    if (!in) {
        cerr << "no " << n << '\n';
        exit(1); // terminate the program
    }
    //std::regex reg2("(Subject([^ ]+\.\\w{1,10}\.\\w{1,10}\.\\w{1,10}\.\\w{1,10}\.[\\w?!.-{2}]))");
    std::regex reg("(From[^ ]+\.\\w{1,10}\.\\w{1,10})");
    std::regex reg2("(Subject[^ ]+\.[\\w.?!]{1,10}\.[\\w.?!]{1,10}\.[\\w.!?]{1,10}\.[\\w.!?]{1,10}\.[\\w.!?]{1,10})");
    //std::regex reg2("(Subject([^ ]+\.[\\w.+%!?]{1,10}\.[\\w.+%!?]{1,10}\.[\\w.+%!?]{1,10}\.[\\w.+%!?]{1,10}\.[\\w?!.-]{1,3}))");
    int lineno = 0;
    for (string s; getline(in, s); ) { // build the vector of lines
        ++lineno;
        smatch matches; // matched strings go here
        if (regex_search(s, matches, reg2)){
            cout << lineno << ": " << matches[0] << '\n';
        }
        if (regex_search(s, matches, reg)) {
            std::cout << lineno << ": " << matches[0] << '\n';
        }
            
        lines.push_back(s);
    }
   
    
    auto first = lines.begin(); // build the vector of Messages
    for (auto p = lines.begin(); p != lines.end(); ++p) {
        if (*p == "––––") { // end of message
            m.push_back(Message(first, p));
            first = p + 1; // –––– not part of message
        }
    }

}
