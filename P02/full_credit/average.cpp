
#include "average.h"






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

