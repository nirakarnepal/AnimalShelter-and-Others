#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "line.h"

int main() {

   Line line{1,2,3,4};
   std::cout << line.to_string() << "is " << line.length() << " long" << std::endl;
}
