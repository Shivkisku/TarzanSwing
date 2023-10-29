#include "Me.hpp"

Me::Me(double x,double y, double len, double vx, double vy)
{
    posn.x = x;
    posn.y = y;
    width = 1.5*len;
    height = len;
    velocity.Vx = vx;
    velocity.Vy = vy;
    acceleration.Ay=0;
}
    
//Collision Detection
bool Me::CheckCollision(class Me* me, std::vector<Object*> enemyList, Lava* lava)
{
    for(auto it: enemyList)
    {
        if((me->posn.x < it->getPosn().x + it->getLen()) && 
            (me->posn.x + me->width > it->getPosn().x) &&
            (me->posn.y < it->getPosn().y + it->getLen()) &&
            (me->height + me->posn.y > it->getPosn().y))
            {
                printf("collision detected\n");
                return true;
            }
    }
    //printf("Object position - (%lf, %lf) lava position - (%lf, %lf)\n",me->getPosn().x,me->getPosn().y,lava->getPosnX(),lava->getPosnY());
    
    if( (me->posn.y < lava->getPosnY() + lava->getLength()) && (me->height + me->posn.y > lava->getPosnY()) )
    {
//    if(me->getPosn().y == lava->getPosnY())
        printf("collided\n");
        return true;
    }
    return false;
}
    
int Me::CheckScoreHit(class Me* me, std::vector<Object*> frendList)
{
    for(int i = 0;i<frendList.size();i++)
    {
        double rIdeal = me->getWidth() + frendList[i]->getLen();
        rIdeal *= rIdeal;
        double Seperation = pow( (me->posn.x - frendList[i]->getPosn().x),2 ) + pow( (me->posn.y - frendList[i]->getPosn().y),2 );
        if(Seperation <= rIdeal)
        {
            
            if(frendList[i] != NULL)
            {
                return i;
            }
        }
    }
    return -1;
}
    
    
//getters
Vec2 Me::getPosn(){return posn;}
Vel2 Me::getVel(){return velocity;}
Acc2 Me::getAcc(){return acceleration;}
double Me::getWidth(){return width;}
double Me::getHeight(){return height;}
    
//setters
void Me::setAcc_x(double acc){acceleration.Ax = acc;}
void Me::setAcc_y(double acc){acceleration.Ay = acc;}

    

