#include <iostream>
#include "Vector.h"

int main(){

Vector<int> ob;
ob.insert(0,7);
ob.insert(1,8);
std::cout<< ob.empty();
ob.insert(2,9);
ob.removal(1);
}
