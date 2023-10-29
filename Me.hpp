#ifndef Me_hpp
#define Me_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Object.hpp"
#include "Lava.hpp"


using namespace std;

class Me{
    private:
        Vec2 posn;
        Vel2 velocity;
        Acc2 acceleration;
        double width, height;
        
    public:
        Me(double x,double y, double len, double vx, double vy);
        
        //Collision Detection
        bool CheckCollision(class Me* me, std::vector<Object*> enemyList, Lava* lava);
        int CheckScoreHit(class Me* me, std::vector<Object*> frendList);
        
        //getters
        Vec2 getPosn();
        Vel2 getVel();
        Acc2 getAcc();
        double getWidth();
        double getHeight();
        double getMass();
        
        //setters
        void setAcc_x(double acc);
        void setAcc_y(double acc);
        void setPosn_x(double x){posn.x = x;}
        void setPosn_y(double y){posn.y = y;}
        void setVel_x(double velx){velocity.Vx = velx;}
        void setVel_y(double vely){velocity.Vy = vely;}

};

#endif 
