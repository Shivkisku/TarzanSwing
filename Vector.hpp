#pragma once
#include<iostream>
using namespace std;

struct Vector
{
    double x=0,y=0;
};

class VectorAlgebra
{
    public: 
        Vector* Add(Vector* a, Vector* b);
        Vector* Sub(Vector*a ,Vector* b);
        Vector* ScalarMul(double a, Vector*b);
        double Dot(Vector*a,Vector*b);
        double Cross(Vector*a,Vector*b);
        double Length(Vector*a);
        Vector* Unit(Vector*a);
        double CosV(Vector*a ,Vector*b);
        double SinV(Vector*a ,Vector*b);
        double TanV(Vector*a ,Vector*b);
        Vector* Rotate(Vector* obj,Vector* hinge,double theta);
        void Reduce(Vector* obj, Vector* hinge, double delta);
        
};
