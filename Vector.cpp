#include<math.h>
#include "Vector.hpp"

    Vector* VectorAlgebra::Add(Vector* a, Vector* b){
        Vector* temp = new Vector();
        temp->x = a->x + b->x;
        temp->y = a->y + b->y;
        cout << "Add " << temp->x << " " << temp->y << endl; 
        return temp;
    }
    Vector* VectorAlgebra::Sub(Vector*a ,Vector* b){
        Vector* temp = new Vector();
        temp->x = a->x - b->x;
        temp->y = a->y - b->y;
        cout << "Sub " << temp->x << " " << temp->y << endl; 
        return temp;
    }
    Vector* VectorAlgebra::ScalarMul(double a, Vector*b){
        Vector* temp = new Vector();
        temp->x = a*(b->x) ;
        temp->y = a*(b->y);
        cout << "ScalarMul " << temp->x << " " << temp->y << endl; 
        return temp;
    }
    
    double VectorAlgebra::Dot(Vector*a,Vector*b){
        double temp;
        temp = (a->x)*(b->x) + (a->y)*(b->y);
        cout << "Dot " << temp << endl;
        return temp;
    }
    double VectorAlgebra::Cross(Vector*a,Vector*b){
        double temp;
        temp = (a->x)*(b->y) - (a->y)*(b->x);
        cout << "Cross " << temp << endl;
        return temp;
    }
    double VectorAlgebra::Length(Vector*a){
        double temp;
        temp = sqrt(pow(a->x,2) + pow(a->y,2));
        cout << "Length " << temp << endl;
        return temp;
    }
    Vector* VectorAlgebra::Unit(Vector*a){
        Vector* temp = new Vector();
        temp->x = (a->x)/Length(a);
        temp->y = ((a->y)/Length(a));
        cout << "Unit " << temp->x << " " << temp->y << endl; 
        return temp;
    }
    double VectorAlgebra::CosV(Vector*a ,Vector*b){
        double temp;
        temp = (Dot(a,b)/(Length(a)*Length(b)));
        cout << "Cos " << temp << endl;
        return temp;
    }
    double VectorAlgebra::SinV(Vector*a ,Vector*b){
        double temp;
        temp = sqrt(1 - pow(CosV(a,b),2));
        cout << "Sin " << temp << endl;
        return temp;
    }
    double VectorAlgebra::TanV(Vector*a ,Vector*b){
        double temp;
        temp = SinV(a,b)/CosV(a,b);
        cout << "Tan " << temp << endl;
        return temp;
    }
    Vector *VectorAlgebra::Rotate(Vector* obj,Vector* hinge,double theta){
        struct Vector* t = new Vector();
        t =  Sub(obj, hinge);
        struct Vector m;
        //m.x = hinge->x; m.y = 0;
        struct Vector* temp = new Vector();
        temp->x = ((t->x)*cos(theta) - (t->y)*sin(theta)) + hinge->x;
        temp->y = ((t->x)*sin(theta) + (t->y)*cos(theta)) + hinge->y;
        cout << "Rotate " << temp->x << " " << temp->y << endl;
        return temp;
    }
    void VectorAlgebra::Reduce(Vector* obj, Vector* hinge, double delta){
        double slope = ((hinge->y - obj->y)/(hinge->x - obj->x));
        
        if(hinge->x >= obj->x ){
            obj->x = obj->x + delta;
            obj->y = hinge->y - (hinge->x - obj->x)*slope;
        }
        else if(hinge->x <= obj->x ){
            obj->x = obj->x - delta;
            obj->y = hinge->y - (hinge->x - obj->x)*slope;
        }
        cout << "Reduce " << obj->x << " " << obj->y << endl;      
    }
// int main()
// {
//     class VectorAlgebra* V = new class VectorAlgebra();
//     struct Vector a;
//     a.x = 4; a.y = 4;
//     struct Vector b;
//     b.x = 8; b.y = 8 ;
//     /*V->Add(&a,&b);
//     V->Sub(&a,&b);
//     V->ScalarMul(4,&b);
//     V->CompoMul(&a,&b);
//     V->Dot(&a,&b);
//     V->Cross(&a,&b);
//     V->Length(&a);
//     V->Unit(&a);
//     V->CosV(&a,&b);
//     V->SinV(&a,&b);
    
//     V->TanV(&a,&b);*/
//  //   V->Rotate(&b,&a,0.52);
//     V->Reduce(&b,&a,1);
//     return 0;
// }