//
// Created by Computer on 28.11.2018.
//

#include "MyClass.h"

std::ostream &operator<<(std::ostream &os, const MyClass &instance) {
    std::cout << "MyClass output";
    return os;
}
