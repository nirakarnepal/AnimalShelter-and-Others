#include "line.h"


Line::Line(double x1, double y1, double x2, double y2){
   _x1 = x1;
   _y1 = y1;
   _x2 = x2;
   _y2 = y2;
}

std::string Line::to_string(){
    //std::cout<<std::fixed;
    std::cout<<std::setprecision(6);
    //std::cout<<"(" << _x1 << "," <<_y1 <<")-(" << _x2 << "," << _y2 << ") ";
    return "(" + std::to_string(_x1) + "," + std::to_string(_y1) + ")-(" + std::to_string(_x2) + "," + std::to_string(_y2) + ") ";
}

double Line::length(){
  double result;
  double temp1;
  double temp2;

  temp1 = (_x1 - _x2);
  temp2 = (_y1 - _y2);
  
  result = sqrt((temp1*temp1) + (temp2*temp2));
  ;
  
return result;

}




