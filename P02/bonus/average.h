
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include<vector>

using namespace std;

class Average{
 private:

   double _sum;
   int _values;
   vector<Average>avg;

 public:

   Average(); //Reset
   
   friend std:: ostream& operator << (std::ostream& ost, Average& average);
   friend std:: istream& operator >> (std::istream& ist, Average& average);
   Average& operator += (double value);

};



