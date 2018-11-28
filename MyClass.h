//
// Created by Computer on 28.11.2018.
//

#pragma once
#include <iostream>

class MyClass{
    friend std::ostream& operator<<(std::ostream& os, const MyClass&);
};


