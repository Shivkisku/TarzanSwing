#include "Lava.hpp"

Lava::Lava(double x, double y, double len, double wid)
{
    this->posX = x;
    this->posY = y;
    this->length = len;
    this->width = wid;
}

void Lava::UpdatePosn()
{
    double deltaTime = 1;
    velX = velX + acclnX * deltaTime;
    posX = posX + velX * deltaTime;
    velY = velY + acclnY * deltaTime;
    posY = posY + velY * deltaTime;
}
//bool Lava::CheckCollision(std::vector<Object*> frendList) {
//    if(frendList[0]->getPosn().y == this->getPosnY())
//        return true;
//    return false;
//}

//getters

double Lava::getLength() { return length; }
double Lava::getWidth() { return width; }
double Lava::getPosnX() { return posX; }
double Lava::getPosnY() { return posY; }
double Lava::getVelX() { return velX; }
double Lava::getVelY() { return velY; }
double Lava::getacclnX(){ return acclnX; };
double Lava::getacclnY(){ return acclnY; };

//setters
void Lava::setAcc_x(double acc) { acclnX = acc; }
void Lava::setAcc_y(double acc) { acclnY = acc; }
void Lava::setPosn_x(double x) { posX = x; }
void Lava::setPosn_y(double y) { posY = y; }
void Lava::setVel_x(double velx) { velX = velx; }
void Lava::setVel_y(double vely) { velY = vely; }
