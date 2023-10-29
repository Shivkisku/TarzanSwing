#pragma once
#ifndef Lava_hpp
#define Lava_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Object.hpp"
using namespace std;

class Lava {
private:
    int length;
    int width;
    double posX;
    double posY;
    double velX;
    double velY;
    double acclnX;
    double acclnY;

public:
    Lava(double x, double y, double len, double wid);

    //Collision Detection
//    bool CheckCollision(std::vector<Object*> frendList);
    void UpdatePosn();

    //getters
    double getPosnX();
    double getPosnY();
    double getVelX();
    double getVelY();
    double getacclnX();
    double getacclnY();
    double getWidth();
    double getLength();

    //setters
    void setAcc_x(double acc);
    void setAcc_y(double acc);
    void setPosn_x(double x);
    void setPosn_y(double y);
    void setVel_x(double x);
    void setVel_y(double y);
};

#endif
