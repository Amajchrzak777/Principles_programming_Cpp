//Adam Majchrzak 11.03.2020

#include "std_lib_facilities.hpp"
#include <cmath>

struct Token {
	char kind; //what kind of Token
	double value;//for numbers a value
	string name;
	//konstruktory obiektów
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind{ ch }, name{ n } { } //brak konstruktora 

};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

namespace MojNamespace {
	const char exit = 'Q';
}

const char let = '#';
//const char exit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_ex = 's';
const char pow_ex = 'p';

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case '#':
	case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch) || ch == '_') {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)|| ch == '_')) s += ch; //blad dodanie +
			cin.unget();
			if (s == "#") return Token(let);
			if (s == "exit") return Token(MojNamespace::exit); //blad bylo name zamiast quit
			if (s == "sqrt") return Token(square_ex);
			if (s == "pow") return Token(pow_ex);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

double define_name(string var, double val)
// add (var,val) to var_table
{
	if (is_declared(var)) error(var, " declared twice");
	names.push_back(Variable(var, val));
	return val;
}

Token_stream ts;

double expression(); //deklaracja


//Funkcja służąca do kolejności działań
double primary()
{
	Token t = ts.get(); //dostań się do następnego Tokena
	switch (t.kind) {
	case '(':
	{
		int d = narrow_cast<double>(expression());
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '-':
		return -primary();
	case '+':
		return primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double power(); //deklaracja


//Podobny do expression
double term()
{
	int left = narrow_cast<double>(power());
	while (true) {
		Token t = ts.get();
		switch (t.kind) { //wybierz w zależności od t * lub /
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		case '%': //dodałem modulo bo nie było
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left = fmod(left, d);
			//t = ts.get(); //zjada mi znak
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}


//Funkcja która odpowiada za potegowanie pow(x,i) ex.9
double power()
{
	int left = narrow_cast<double>(primary());
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case ',': {
			double d = expression();
			return pow(left, (int)d);
			ts.unget(t);
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}


//podobny do term
double expression()
{
	int left = narrow_cast<double>(term());
	while (true) {
		Token t = ts.get(); //wybierz w zaleznosci od t.kind + lub -
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}


//Funkcja odpowiada za pierwiastkowanie sqrt(x)
double square()
{
	int d =  narrow_cast<double>(expression());		//funkcja dotycząca pierwiastka
	if (d < 0) error("square cannot be < 0"); // zalozenie z definicji 
	int x = narrow_cast<double>(sqrt(d));
	return x;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case '#':
		return declaration();
	case square_ex:
		return square();
	case pow_ex:
		return power();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == MojNamespace::exit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error & e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

void inicialize_k()
{
	names.push_back(Variable("k", 1000));//inicjalizuje predefined k
	//names.push_back(Variable("pi", 3.14));
	//names.push_back(Variable("e", 2.73));
}

int main()
{
	define_name("pi", 3.14);
	define_name("e", 2.73);
	try {
		inicialize_k();
		calculate();
		return 0;
	}
	catch (exception & e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}