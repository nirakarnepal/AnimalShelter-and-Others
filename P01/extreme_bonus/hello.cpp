//Nirakar Nepal
//1001666002

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

  char* name = getenv ("USER");
  if (name!=NULL)
  {
    cout << "Hello " << name << "!" << endl;  

  }
  
}
