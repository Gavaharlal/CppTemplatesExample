#include <iostream>
#include "MyClass.h"
#include "Array.h"

using std::cout;
using std::endl;
using std::type_info;

void print_values() {
    cout << endl;
}

template<typename T>
void print_values(const T &t) {
    cout << typeid(t).name() << ": " << t << endl;
}

template<typename T, typename... Other>
void print_values(const T &arg, const Other &... tail) {
    cout << typeid(arg).name() << ": " << arg << endl;
    print_values(tail...);
}

int main() {
    MyClass m;
    print_values(0, 3.5, "Hello", '/', m);

    Array<int> array1(7);
    for (int i = 0; i < array1.size(); ++i) {
        array1[i] = i + 1;
    }

    Array<int> array2(array1);
    array2.print();
    array1.print();

    Array<int> array3(2);
    array3.print();

    array3 = Array<int>(5);
    array3.print();

    cout << endl;
    return 0;
}