#include <iostream>
#include <string>

class Average{
 private:

   float _sum;
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
   if(average._values ==0 && average._sum ==0)
    {
         ost<<"The current average is undefined.\n\n";
         ost<< "1 - Enter a new value \n2 - Auto enter a random value \n3 - Clear the calculator \n0 - Exit \n \nCommand? "; 
    }else{
          if(average._values !=0)
       {
           ost<< "THe average is " << (average._sum / average._values) << "\n";        
 
       }
       else
       {
            ost<< "Undefined\n";
       }
     }

}

std:: istream& operator >> (std::istream& ist, Average& average)
{
   
   double temp;   
   ist >> temp ;
   average._sum += temp;
   average._values ++; 


}

Average& Average::operator += (double value)
{

}

int main()
{

   Average average;
   int input;
   cout<<"=================================================="<<endl;
   cout<<"               Merely Average Calculator"<<endl;


   cin >> average;
   cout << average;

   cin >> input;



}

