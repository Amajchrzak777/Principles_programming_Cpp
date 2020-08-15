//Adam Majchrzak 04.03.2020

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

inline void keep_window_open()

{ char ch; cin>>ch; }

int main(){
    int age;
    cout << "Enter the name of the person you want to write to \n";
	string first_name, how_are_you, my_day, friend_name, my_reply, my_name;	// first_name is a variable of type string
	cin >> first_name;	// read characters into first name
	char friend_sex = '0';
	cout << "Friend name: ";
	cin >> friend_name;
	cout << "Dear, " << first_name << "!\n";
	cout << "How are you ?\n";
    cin >> how_are_you;
    cout << "What are you doing today ?\n";
    cin >> my_day;
    cout << "Have you seen " << friend_name <<  " lately ?\n";
    cin >> my_reply;
    cout << "Friend sex is: (choose m or f) ";
    cin >> friend_sex;
    if(friend_sex='m'){
        cout<<"If you see "<<friend_name<<" please ask him to call me.";
    }else{
        cout<<"If you see"<<friend_name<<" please ask her to call me.";
    }
    cout << "\nFriend's age: ";
    cin >>age;
    if((age==0)||(age>=110)){
        return EXIT_FAILURE;
    }else{
        cout << "\nI hear you just had a birthday and you are "<<age<<" years old.";
    }
    if(age<12){
        cout << "\nNext year you will be "<<age+1<<".";
    }else if(age==17){
        cout << "\nNext year you will be able to vote.";
    }else if(age>70){
        cout << "\nI hope you are enjoying retirement.";
    }
    cout << "\n\nYour's sincerely, \n";
    cin >> my_name;

    return 0;
}
