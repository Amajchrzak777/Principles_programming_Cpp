// Adam Majchrzak 05.05.2020r. 


#include "std_lib_facilities.hpp"
#include <map>

struct Item {
    string name;
    int iid;
    double value;
	Item() : name(), iid(0), value(0.0) {};
	Item(string n = " ", int i=0, double v=0.0) : name(n), iid(i), value(v) {}
};

struct Find_by_name {
	string name;
	Find_by_name(const string& n) : name(n) {}
	bool operator()(const Item& item) const 
	{
		return item.name == name;
	}
};

struct Find_by_iid {
	int iid;
	Find_by_iid(const int& i) : iid(i) {}
	bool operator()(const Item& item) const
	{
		return item.iid == iid;
	}

};

struct Cmp_by_name {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.name < b.name;
	}
};

struct Cmp_by_iid {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.iid < b.iid;
	}
};

struct Cmp_by_value {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.value > b.value;
	}
};

ostream& operator<<(std::ostream& os, const Item& item)
{
    return os << item.name << '\t'
        << item.iid << '\t'
        << item.value;
}

istream& operator>>(std::istream& is, Item& item)
{
    std::string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    item = Item( name, iid, value );
    return is;
}


//drill 5
void put_in_msi(std::map<string, int>& msi) {
	string s;
	int x;
	std::cout << "writee pairs from cin and i will place them in the msi (string,x)";
	for (int i = 0; i < 10; ++i) {
		std::cin >> s;
		std::cin >> x;
		msi.insert({ s, x });
	}
}

int main() {
	//drill 1
	string oname = "plik.txt";
	std::cout << "Plik wejsciowy: ";

	vector<Item> vi;
	ifstream ist(oname.c_str());
	if (!ist) cerr << "Can't open file";
	Item x("x", 2, 2);
	while (ist >> x) {
		vi.push_back(Item{ x });
	}
	cout << endl;
	for (int i = 0; i < vi.size(); ++i) std::cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << '\n';
	
	//drill 2
	std::cout << "\nsort by name: \n";
	std::sort(vi.begin(), vi.end(), Cmp_by_name());
	for (int i = 0; i < vi.size(); ++i) std::cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << '\n';
	//drill 3
	std::cout << "\nsort by iid: \n";
	std::sort(vi.begin(), vi.end(), Cmp_by_iid());
	for (int i = 0; i < vi.size(); ++i) std::cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << '\n';
	//drill 4
	std::cout << "\nsort by value: \n";
	std::sort(vi.begin(), vi.end(), Cmp_by_value());
	for (int i = 0; i < vi.size(); ++i) std::cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << '\n';

	//drill 5
	std::cout << "\nafter 2 inserts: \n";
	vi.insert(vi.end(), Item("horse shoe", 99, 12.34));
	vi.insert(vi.end(), Item("Canon S400", 9988, 499.95));
	for (int i = 0; i < vi.size(); ++i) std::cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << '\n';
	//drill 6
	vector<Item>::iterator iter = find_if(vi.begin(), vi.end(), Find_by_name("horse shoe"));
	std::cout << "\niterator wskazuje na: \n";
	cout << *iter;
	vi.erase(iter);
	cout << "\n\nPo erase tak wyglada vector: \n";
	for (int i = 0; i < vi.size(); ++i) std::cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << '\n';
	
	vector<Item>::iterator iter1 = find_if(vi.begin(), vi.end(), Find_by_name("Canon S400"));
	std::cout << "\niterator wskazuje na: \n";
	cout << *iter1;
	vi.erase(iter1);
	cout << "\n\nPo erase tak wyglada vector: \n";
	for (int i = 0; i < vi.size(); ++i) std::cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << '\n';
	//drill 7
	vector<Item>::iterator iter2 = find_if(vi.begin(), vi.end(), Find_by_iid(15));
	std::cout << "\niterator wskazuje na: \n";
	cout << *iter2;
	vi.erase(iter2);
	cout << "\n\nPo erase tak wyglada vector: \n";
	for (int i = 0; i < vi.size(); ++i) std::cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << '\n';

	vector<Item>::iterator iter3 = find_if(vi.begin(), vi.end(), Find_by_iid(353));
	std::cout << "\niterator wskazuje na: \n";
	cout << *iter3;
	vi.erase(iter3);
	cout << "\n\nPo erase tak wyglada vector: \n";
	for (int i = 0; i < vi.size(); ++i) std::cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << '\n';
	ist.close();
	//drill 8
	
	string oname2 = "plik2.txt";
	std::cout << "Plik wejsciowy: ";
	ifstream ist2(oname2.c_str());
	if (!ist2) cerr << "Can't open file";
	list<Item> li;
	Item l("x", 2, 2);
	while (ist2 >> l) {
		li.push_back(Item{ l });
	}
	cout << endl;
	for (auto n : li) cout << n << '\n';

	std::cout << "\nsort by name: \n";
	li.sort(Cmp_by_name());
	for (auto n : li) cout << n << '\n';
	std::cout << "\nsort by iid: \n";
	li.sort(Cmp_by_iid());
	for (auto n : li) cout << n << '\n';
	std::cout << "\nsort by value: \n";
	li.sort(Cmp_by_value());
	for (auto n : li) cout << n << '\n';
	li.insert(li.end(), Item("horse shoe", 99, 12.34));
	li.insert(li.end(), Item("Canon S400", 9988, 499.95));
	std::cout << "\nafter 2 inserts: \n";
	for (auto n : li) cout << n << '\n';
	list<Item>::iterator iter4 = find_if(li.begin(), li.end(), Find_by_name("Canon S400"));
	li.erase(iter4);
	list<Item>::iterator iter5 = find_if(li.begin(), li.end(), Find_by_name("horse shoe"));
	li.erase(iter5);
	std::cout << "\nafter 2 erases: \n";
	for (auto n : li) cout << n << '\n';

	list<Item>::iterator iter6 = find_if(li.begin(), li.end(), Find_by_iid(353));
	li.erase(iter6);
	list<Item>::iterator iter7 = find_if(li.begin(), li.end(), Find_by_iid(15));
	li.erase(iter7);
	std::cout << "\nafter 4 erases: \n";
	for (auto n : li) cout << n << '\n';
	ist2.close();
	//drill 1
	std::map<string, int> msi;

	//drill 2
	msi.insert({ "Adam", 4 });
	msi.insert({ "Karol", 5 });
	msi.insert({ "Aga", 15 });
	msi.insert({"Andrzej", 5});
	msi.insert({ "Michal", 12 });
	msi.insert({ "Ada", 65 });
	msi.insert({ "Pawel", 434 });
	msi.insert({ "Piotr", 35 });
	msi.insert({ "Ela", 1215 });
	msi.insert({ "Irek", 12315 });
	//drill 3
	for (auto itr = msi.begin(); itr != msi.end(); ++itr) {
		cout << itr->first << ": " << itr->second << "\n";
	}
	//drill 4
	msi.erase(msi.begin(), msi.end());
	//drill 6
	put_in_msi(msi);
	for (auto itr = msi.begin(); itr != msi.end(); ++itr) {
		cout << itr->first << ": " << itr->second << "\n";
	}

	//drill 8
	int sum = 0;
	for (auto itr = msi.begin(); itr != msi.end(); ++itr) {
		int x = itr->second;
		sum += x;
	}
	std::cout << "Sum of all integers: " << sum << std::endl;
	
	//drill 9, 10, 11
	std::map<int, string> mis;
	for (const auto& a : msi)
		mis[a.second] = a.first;

	for (auto itr = mis.begin(); itr != mis.end(); ++itr) {
		cout << itr->first << ": " << itr->second << "\n";
	}

	//drill 1
	vector<double> vd;
	string oname1 = "plik1.txt";
	ifstream ist1(oname1.c_str());
	if (!ist1) cerr << "plik nie zostal otwarty";
	float a;
	while (ist1 >> a) vd.push_back(a);
	//drill 2
	std::cout << "\nvector vd: \n";
	for (int i = 0; i < vd.size(); ++i) std::cout << vd[i] << '\n';
	//drill 3
	vector<int> vi1(vd.size());
	copy(vd.begin(), vd.end(), vi1.begin());
	std::cout << "\nPairs: \n";
	for (int i = 0; i < vd.size(); ++i) std::cout << "(" << vd[i] << "," << vi1[i] << ")" << '\n';
	double sum_double = 0.0;
	int sum_int = 0;
	for (int i = 0; i < vd.size(); ++i) sum_double += vd[i];
	std::cout << "\nThe sum of vector vd: " << sum_double;
	for (int i = 0; i < vi1.size(); ++i) sum_int += vi1[i];
	std::cout << "\nThe sum of vector vi1: " << sum_int;

	double sumx = 0.0;
	sumx = sum_double - sum_int;
	std::cout << "\ndifference bettwen vd - vi1: " << sumx;

	std::reverse(vd.begin(), vd.end());
	std::cout << "\nreversed: \n";
	for (int i = 0; i < vd.size(); ++i) std::cout << vd[i] << '\n';

	double mean_value_of_vd = 0.0;
	mean_value_of_vd = sum_double / vd.size();
	std::cout << "\nmean value of vd:" << mean_value_of_vd << '\n';


	vector<double> vd2;
	std::cout << "\nvector vd2: " << '\n';
	for (int i = 0; i < vd.size(); ++i) {
		if (vd[i] < mean_value_of_vd) {
			vd2.push_back(vd[i]);
		}
	}
	for (int i = 0; i < vd2.size(); ++i)std::cout << vd2[i] << '\n';


	std::cout << "\nafter sort\n";
	sort(vd.begin(), vd.end());
	for (int i = 0; i < vd.size(); ++i) std::cout << vd[i] << '\n';

}
