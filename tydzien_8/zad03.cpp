// Adam Majchrzak 24.04.2020
//

#include "std_lib_facilities.hpp"

class Stack {
    int data = 0;
    Stack* under = nullptr;
public:
    void add_to_stack(int, Stack*&);
    int remove_from_stack(Stack*&);
    void show_stack(Stack*);
}; 

int main()
{
    std::cout << "For instance addressess for array: \n";
    int* arr = new int[20];
    for (int i = 0; i < 20; ++i) {
        arr[i] = i;
        std::cout << (int)&arr[i] << std::endl;
    }

    std::cout << std::endl << "On the stack: \n";
    Stack* my_stack = new Stack;
    Stack* x = nullptr;

    my_stack->add_to_stack(1, x);
    my_stack->add_to_stack(5, x);
    my_stack->add_to_stack(10, x);
    my_stack->add_to_stack(7, x);
    my_stack->add_to_stack(6, x);
    my_stack->add_to_stack(3, x);
    my_stack->add_to_stack(2, x);
    my_stack->show_stack(x);
    std::cout << "\n\n For vector: \n";

    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    for (int i = 0; i < v1.size(); ++i) {
        std::cout << (int)&v1[i] << std::endl;
    }
}

void Stack::add_to_stack(int d, Stack*& top) {
    Stack* new_element = new Stack;
    new_element->data = d;
    new_element->under = top;
    top = new_element;
}

void Stack::show_stack(Stack* top) {
    
    while (top != nullptr){
        std::cout << top->data << "\taddress: " << (int)*&top <<std::endl;
        top = top->under;   
    }
}

int Stack::remove_from_stack(Stack*& top) {
    if (top == nullptr) {
        return 0;
    }
    Stack* temp = top;
    int d = top->data;
    top = top->under;
    delete temp;
    return d;
}

