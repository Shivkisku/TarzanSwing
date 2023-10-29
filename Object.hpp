#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <math.h>
#define gravity 0.4

struct Vec2{
    double x,y;
};
struct Vel2{
    double Vx=0,Vy=0;
};
struct Acc2{
    double Ax =0,Ay=0;
};

class Object{
    private:
        Vec2 posn;
        Vel2 velocity;
        Acc2 acceleration;
        double len;
        bool evil;
    public:
        Object(bool evil, double x,double y, double len);
        void UpdatePosn();
        
        //getters
        double getLen();
        Vec2 getPosn();
        Vel2 getVel();
        Acc2 getAcc();
        double getMass();
        
        //setters
        void setAcc_x(double acc);
        void setAcc_y(double acc);
        void setPosn_x(double x);
        void setPosn_y(double y);
        void setVel_x(double velx);
        void setVel_y(double vely);
};

#endif
