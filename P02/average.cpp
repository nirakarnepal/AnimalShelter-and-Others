#include <iostream>
#include <string>

class Average{
 private:

   float _sum;
   int _values;

 public:

   Average(); //Reset
   Average(float sum, int values);
   friend std:: ostream& operator << (std::ostream& ost, Average& average);
   friend std:: istream& operator >> (std::istream& ist, Average& average);
   Average& operator += (double value);

};

std:: ostream& operator << (std::ostream& ost, Average& average)
{


}

std:: istream& operator >> (std::istream& ist, Average& average)
{


}

Average& Average::operator += (double value)
{


}

int main()
{
   int input;
   cout<<"=================================================="<<endl;
   cout<<"               Merely Average Calculator"<<endl;


   cout<< "1 - Enter a new value \n2 - Auto enter a random value \n3 - Clear the calculator \n0 - Exit \n \nCommand?"<<endl;

   cin >> input;



}

