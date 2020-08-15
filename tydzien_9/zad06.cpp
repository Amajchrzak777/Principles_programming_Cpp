// Adam Majchrzak 06.05.2020

#include "std_lib_facilities.hpp"
#include <set>
struct Fruit {
    const string name;
    int count;
    double unit_price;
    // . . .
    //Fruit(string n, int c) : name(n), count(c) {}
    Fruit(const string& n, int c = 0, double u_p = 0.0) : name(n), count(c), unit_price(u_p) {}
};

struct Fruit_order {
    bool operator()(const Fruit& a, const Fruit& b) const
    {
        return a.name < b.name;
    }
};

struct Fruit_comparision {
    bool operator() (const Fruit* a, const Fruit* b)
    {
        return a->name < b->name;
    }
        
};

ostream& operator<<(ostream& os, const Fruit& f) {
   os << f.name << " " << f.count << " " << f.unit_price;
   return os;
}

ostream& operator<<(ostream& os, const Fruit* f) {
    os << f->name << " " << f->count << " " << f->unit_price;
    return os;
}


set<Fruit, Fruit_order> inventory; // use Fruit_order(x,y) to compare Fruits
//set<Fruit*, Fruit_comparision> inventory; // use Fruit_order(x,y) to compare Fruits

int main()
{

    set<Fruit*, Fruit_comparision> no_copy;
    set<Fruit*, Fruit_comparision>::const_iterator iter;

    inventory.insert(Fruit{ "quince", 5, 6.6 });
    inventory.insert(Fruit{ "apple", 200, 0.37 });

    for (auto& x : inventory)
        cout << x;

    no_copy.insert(new Fruit("quince", 15, 34.432));
    no_copy.insert(new Fruit("apple", 213, 34.32));
    no_copy.insert(new Fruit("banana", 323, 43.3453));
 
    for (auto& x : no_copy) {
        cout << *x;
    }
}

