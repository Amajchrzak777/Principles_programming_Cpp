﻿// Adam Majchrzak 08.05.2020
//

#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>

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
    vector<Message> m; // Messages in order
    Mail_file(const string& n); // read file n into lines

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

Mail_file::Mail_file(const string& n)
// open file named n
// read the lines from n into lines
// find the messages in the lines and compose them in m
 // for simplicity assume every message is ended by a –––– line
{
    ifstream in{ n }; // open the file
    if (!in) {
        cerr << "no " << n << '\n';
        exit(1); // terminate the program
    }
    for (string s; getline(in, s); ) // build the vector of lines
        lines.push_back(s);
    auto first = lines.begin(); // build the vector of Messages
    for (auto p = lines.begin(); p != lines.end(); ++p) {
        if (*p == "-------") { // end of message
            if (p != first)
                m.push_back(Message{first,p});
            first = p + 1; // –––– not part of message
        }
    }
}

int is_prefix(const string& s, const string& p)
// is p the first part of s?
{
    int n = p.size();
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
    Mail_file mfile{ "my-mail-file.txt" }; // initialize mfile from a file
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
    for (const auto& m : mfile) {
        string s;
        if (find_from_addr(&m, s))
            sender.insert(make_pair(s, &m));
    }

}