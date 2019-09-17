

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "average.h"
using namespace std;


int printmenu(Average average)
{
   int choice;
   std::cout<<"\n====================================\n";
   std::cout<<"\tMerely Average Calculator\t";
   std::cout<<"\n====================================\n";
   std::cout<<"The current average is " << average;

   std::cout<<"\n\n1 - Enter a new value.\n2 - Auto generate a random value.\n9 - Clear the calculator.\n0 - Exit.\n\nCommand? ";
   std::cin>> choice;

   return choice;

}

int main()
{

   Average average;
   srand(time(0));
   while(1)
   {
    switch(printmenu(average))
    {
      case 1: std::cin >> average;
              break;
      case 2: average += rand() % (100);
              break;
      case 9: average = Average();
              break;
      case 0: exit(0);
      default: std::cout<<"\n Invalid choice, please chose 1, 2, 9 or 0";

    }
    
   }
   return 0;
}



