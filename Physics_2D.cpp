#include <iostream>
#include <math.h>
#include "Vector.hpp"
#include "Physics_2D.hpp"
using namespace std;

    Vector* Physics_2D::vfinal(Vector* v0,Vector* a, double t)
    {
        struct Vector* v = new Vector();
        v->x = v0->x + a->x*(t);
        v->y = v0->y + a->y*(t);
        cout << "Vfinal " << v->x << " " << v->y << endl; 
        return v;
    }
    void Physics_2D::pfinal(Vector* p0, Vector* v,Vector* a, double t)
    {
        p0->x = p0->x + ((v->x)*t) + (0.5)*(a->x)*(pow(t,2));
        p0->y = p0->y + ((v->y)*t) + (0.5)*(a->y)*(pow(t,2));

    }
    //Force will be epresented by m*a
    double Physics_2D::omega(Vector* hinge, Vector* pos, Vector* v){
        struct Vector* t = new Vector();
        VectorAlgebra* m= new VectorAlgebra();
        t = m->Sub(hinge,pos);
        double sinTheta = m->SinV(t,v);

        double w = (m->Length(v)*sinTheta) / m->Length(t);
        cout << w << endl;
        return w; 
    }

