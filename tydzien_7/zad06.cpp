// Adam Majchrzak 21.04.2020
// zad 13

#include <iostream>
#include <string>
#include <vector>

struct God {
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;
    God(std::string n, std::string m, std::string v, std::string w)
        : name{ n }, mythology{ m }, vehicle{ v }, weapon{ w } {}
    God()
    {
    }
    void print_all();
    void add_ordered();
    std::vector<God> Greek;
    std::vector<God> Roma;
    std::vector<God> Nordic;
};

int main()
{
    std::vector<God> Greek_Mythology;
    God* show = new God;

    God* gods = new God{ "Zeus", "Greek", "", "lightning" };
    God* gods1 = new God{ "Odin", "Norse", "Eight-legged flying horse called Sleipner",
"Spear called Gungnir" };
    God* gods2 = new God{ "Thor", "Norse", "null", "Axe" };
    gods->add_ordered();
    gods1->add_ordered();
    gods2->add_ordered();
    
}


void God::print_all() { 
    std::cout << this->name << std::endl
        << this->mythology << std::endl
        << this->vehicle << std::endl
        << this->weapon << std::endl;
}

void God::add_ordered() {
    
    if (this->mythology == "Greek") {
        Greek.push_back(God{ this->name, this->mythology, this->vehicle, this->weapon });
        std::cout << "Greek mythology" << std::endl;
        for (int i = 0; i < Greek.size(); ++i) {
            std::cout << Greek[i].name << " "
                << Greek[i].mythology << " "
                << Greek[i].vehicle << " "
                << Greek[i].weapon << std::endl;
        }
    }
    else if (this->mythology == "Norse") {
        Nordic.push_back(God{this->name, this->mythology, this->vehicle, this->weapon});
        std::cout << "Norse mythology" << std::endl;
        for (int i = 0; i < Nordic.size(); ++i) {
            std::cout << Nordic[i].name << " "
                << Nordic[i].mythology << " "
                << Nordic[i].vehicle << " "
                << Nordic[i].weapon << std::endl;
        }
    }
    else if (this->mythology == "Roma") {
        Roma.push_back(God{ this->name, this->mythology, this->vehicle, this->weapon });
        std::cout << "Roma mythology" << std::endl;
        for (int i = 0; i < Roma.size(); ++i) {
            std::cout << Roma[i].name << " "
                << Roma[i].mythology << " "
                << Roma[i].vehicle << " " 
                << Roma[i].weapon << std::endl;
        }
    }
    else {
        std::cout << "This is not character from mythology.";
    }


}
