//
//  Physics_2D.hpp
//  SDL_EXPERIMENTING
//
//  Created by Rahul Jain on 12/12/21.
//

#ifndef Physics_2D_h
#define Physics_2D_h

#include <iostream>
#include <math.h>
#include "Vector.hpp"
using namespace std;
class Physics_2D
{
    public :
    Vector* vfinal(Vector* v0,Vector* a, double t);
    void pfinal(Vector* p0, Vector* v,Vector* a, double t);
    //Force will be epresented by m*a
    double omega(Vector* hinge, Vector* pos, Vector* v);

};


#endif /* Physics_2D_h */
