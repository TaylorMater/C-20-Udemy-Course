#include "exercise.h"
#include <cmath>


double hexagon_area(){
    
    //Your code will go below this line
    double side_length {6.7};
    double hex_area = ( ( 3.0 * (std::sqrt(3.0) ) ) / 2.0 ) * std::pow(side_length,2);
    //Your code will go above this line
    
    return hex_area;
}