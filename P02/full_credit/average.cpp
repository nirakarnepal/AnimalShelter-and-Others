#ifndef _average_h
#define _average_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Average{
 private:

   double _sum;
   int _values;

 public:

   Average(); //Reset
   
   friend std:: ostream& operator << (std::ostream& ost, Average& average);
   friend std:: istream& operator >> (std::istream& ist, Average& average);
   Average& operator += (double value);

};

//here we set both sum and values to zero via initialization list
Average::Average(): _sum{0}, _values{0} {}


std:: ostream& operator << (std::ostream& ost, Average& average)
{
   
       if(average._values == 0)
       {
           ost<< "Undefined\n";  
 
       }
       else
       {
          ost<<(average._sum / average._values) << "\n";        
       }
     
   return ost;
}

std:: istream& operator >> (std::istream& ist, Average& average)
{
   
   double temp; 
   cout<< "Please enter double value: "<<endl;  
   ist >> temp ;
   average._sum += temp;
   average._values ++; 
   return ist;

}

Average& Average::operator += (double value)
{
   _sum += value;
   _values++;

   return *this;
}


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



#endif

