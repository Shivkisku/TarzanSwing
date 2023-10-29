#include "Rope.hpp"
#include <climits>
#include <iostream>

void Rope::setTarget(SDL_MouseButtonEvent& b, Me* hero, std::vector<Object*> enemyList, std::vector<Object*> frendList)
{
    double targetMouseDistance = INT_MAX;
    for(auto it: enemyList)
    {
        double seperation = pow((b.x - it->getPosn().x),2) + pow((b.y - it->getPosn().y),2);
        if(seperation < targetMouseDistance)
        {
            otherNode = it;
            targetMouseDistance = seperation;
        }
    }
    for(auto it: frendList)
    {
        double seperation = pow((b.x - it->getPosn().x),2) + pow((b.y - it->getPosn().y),2);
        if(seperation < targetMouseDistance)
        {
            otherNode = it;
            targetMouseDistance = seperation;
        }
    }
    meNode = hero;
    initialPosn = otherNode->getPosn();
    initialVel = otherNode->getVel();
    ropeLength = pow((otherNode->getPosn().y - meNode->getPosn().y ),2) + pow((otherNode->getPosn().x - meNode->getPosn().x ),2);
    ropeLength = pow(ropeLength,0.5);
}

double Rope::giveInitialSep()
{
    double seperation = pow((otherNode->getPosn().y - meNode->getPosn().y ),2) + pow((otherNode->getPosn().x - meNode->getPosn().x ),2);
    return seperation;
}
    
bool Rope::RopeCalculus(bool Roped, std::vector<Object*> enemyList, std::vector<Object*> frendList, Lava* lava)
{
    double seperation = pow((otherNode->getPosn().y - meNode->getPosn().y ),2) + pow((otherNode->getPosn().x - meNode->getPosn().x ),2);
    seperation = pow(seperation,0.5);

    bool counterClock = true;

    if(initialPosn.x - meNode->getPosn().x > 0 && initialVel.Vy>0)
        counterClock = false;
    
    if(initialPosn.x - meNode->getPosn().x < 0 && initialVel.Vy<0)
        counterClock = false;

    double XwrtO = otherNode->getPosn().x - meNode->getPosn().x;
    double YwrtO = otherNode->getPosn().y - meNode->getPosn().y;
    
    double Vsqr = pow(initialVel.Vx,2) + pow(initialVel.Vy,2) - 2*gravity*(otherNode->getPosn().y - initialPosn.y);
    
    if(!Roped)
    {
        //Slack mechanics
        for(auto it: enemyList)
            it->setAcc_y(-gravity);
        for(auto it: frendList)
            it->setAcc_y(-gravity);
        lava->setAcc_y(-gravity);
        return false;
    }
    if(Vsqr <= 0 && Roped )
    {
        std::cout<<"relPosn: "<<(otherNode->getPosn().y - meNode->getPosn().y)<<std::endl;
        return false;
    }

    //Normal condition
    if(counterClock == true)
    {

        for(auto it:enemyList) it->setAcc_x(0);
        for(auto it:enemyList) it->setAcc_y(0);
        for(auto it:frendList) it->setAcc_x(0);
        for(auto it:frendList) it->setAcc_y(0);
        lava->setAcc_y(0);
        lava->setAcc_x(0);
        
        double Vnet = pow(Vsqr,.5);

        if(XwrtO == 0)
        {
            if(YwrtO < 0)
            {

                for(auto it:enemyList) it->setVel_x(-Vnet);
                for(auto it:frendList) it->setVel_x(-Vnet);
                for(auto it:frendList) it->setVel_y(0);
                for(auto it:enemyList) it->setVel_y(0);
                lava->setVel_x(0);
                lava->setVel_y(0);
            }
            else
            {

                for(auto it:enemyList) it->setVel_x(Vnet);
                for(auto it:frendList) it->setVel_x(Vnet);
                for(auto it:frendList) it->setVel_y(0);
                for(auto it:enemyList) it->setVel_y(0);
                lava->setVel_x(0);
                lava->setVel_y(0);
            }
        }
        else
        {
            double theta = atan(XwrtO/YwrtO);
            
            //1st quadrant tick
            //sin+ cos+
            if(XwrtO>0 && YwrtO<0)
            {
//                    std::cout<<"1st  "<<meNode->getVel().Vy<<std::endl;
//                    meNode->setVel_x(-Vnet*cos(theta));
//                    meNode->setVel_y(Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_x(-Vnet*cos(theta));
                for(auto it:frendList) it->setVel_x(-Vnet*cos(theta));
                for(auto it:frendList) it->setVel_y(Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_y(Vnet*sin(theta));
                lava->setVel_x(0);
                lava->setVel_y(Vnet*sin(theta));

            }
            //2nd quadrant tick
            //sin- cos+
            else if(XwrtO>0 && YwrtO>0)
            {
//                    std::cout<<"2nd  "<<meNode->getVel().Vy<<std::endl;
//                    meNode->setVel_x(Vnet*cos(theta));
//                    meNode->setVel_y(-Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_x(Vnet*cos(theta));
                for(auto it:frendList) it->setVel_x(Vnet*cos(theta));
                for(auto it:frendList) it->setVel_y(-Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_y(-Vnet*sin(theta));
                lava->setVel_x(0);
                lava->setVel_y(-Vnet*sin(theta));
            }
            //3rd quadrant tick
            //sin- cos-
            else if(XwrtO<0 && YwrtO>0)
            {
//                    std::cout<<"3rd  "<<meNode->getVel().Vy<<std::endl;
//                    meNode->setVel_x(Vnet*cos(theta));
//                    meNode->setVel_y(-Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_x(Vnet*cos(theta));
                for(auto it:frendList) it->setVel_x(Vnet*cos(theta));
                for(auto it:frendList) it->setVel_y(-Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_y(-Vnet*sin(theta));
                lava->setVel_x(0);
                lava->setVel_y(-Vnet*sin(theta));
            }
            //4th quadrant tick
            //sin+ cos-
            else if(XwrtO<0 && YwrtO<0)
            {
//                    std::cout<<"4th  "<<meNode->getVel().Vy<<std::endl;
//                    meNode->setVel_x(-Vnet*cos(theta));
//                    meNode->setVel_y(Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_x(-Vnet*cos(theta));
                for(auto it:frendList) it->setVel_x(-Vnet*cos(theta));
                for(auto it:frendList) it->setVel_y(Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_y(Vnet*sin(theta));
                lava->setVel_x(0);
                lava->setVel_y(Vnet*sin(theta));
            }
            
        }
    }
    else
    {
//            std::cout<<"Clockwise"<<std::endl;
        for(auto it:enemyList) it->setAcc_x(0);
        for(auto it:enemyList) it->setAcc_y(0);
        for(auto it:frendList) it->setAcc_x(0);
        for(auto it:frendList) it->setAcc_y(0);
        lava->setAcc_y(0);
        lava->setAcc_x(0);

        double Vnet = pow(Vsqr,.5);
//            std::cout<<"Vel: "<<Vnet<<std::endl;

        if(XwrtO == 0)
        {
            if(YwrtO < 0)
            {
//                    meNode->setVel_x(Vnet);
//                    meNode->setVel_y(0);
                for(auto it:enemyList) it->setVel_x(Vnet);
                for(auto it:frendList) it->setVel_x(Vnet);
                for(auto it:frendList) it->setVel_y(0);
                for(auto it:enemyList) it->setVel_y(0);
                lava->setVel_y(0);
                lava->setVel_x(0);

            }
            else
            {
//                    meNode->setVel_x(-Vnet);
//                    meNode->setVel_y(0);
                for(auto it:enemyList) it->setVel_x(-Vnet);
                for(auto it:frendList) it->setVel_x(-Vnet);
                for(auto it:frendList) it->setVel_y(0);
                for(auto it:enemyList) it->setVel_y(0);
                lava->setVel_y(0);
                lava->setVel_x(0);
            }
        }
        else
        {
            double theta = atan(XwrtO/YwrtO);

            //1st quadrant tick
            //sin+ cos+
            if(XwrtO>0 && YwrtO<0)
            {
//                    meNode->setVel_x(Vnet*cos(theta));
//                    meNode->setVel_y(-Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_x(Vnet*cos(theta));
                for(auto it:frendList) it->setVel_x(Vnet*cos(theta));
                for(auto it:frendList) it->setVel_y(-Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_y(-Vnet*sin(theta));
                lava->setVel_x(0);
                lava->setVel_y(-Vnet*sin(theta));
            }
            //2nd quadrant tick
            //sin- cos+
            else if(XwrtO>0 && YwrtO>0)
            {
//                    meNode->setVel_x(-Vnet*cos(theta));
//                    meNode->setVel_y(Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_x(-Vnet*cos(theta));
                for(auto it:frendList) it->setVel_x(-Vnet*cos(theta));
                for(auto it:frendList) it->setVel_y(Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_y(Vnet*sin(theta));
                lava->setVel_x(0);
                lava->setVel_y(Vnet*sin(theta));
            }
            //3rd quadrant tick
            //sin- cos-
            else if(XwrtO<0 && YwrtO>0)
            {
//                    meNode->setVel_x(-Vnet*cos(theta));
//                    meNode->setVel_y(Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_x(-Vnet*cos(theta));
                for(auto it:frendList) it->setVel_x(-Vnet*cos(theta));
                for(auto it:frendList) it->setVel_y(Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_y(Vnet*sin(theta));
                lava->setVel_x(0);
                lava->setVel_y(Vnet*sin(theta));
            }
            //4th quadrant tick
            //sin+ cos-
            else if(XwrtO<0 && YwrtO<0)
            {
//                    meNode->setVel_x(Vnet*cos(theta));
//                    meNode->setVel_y(-Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_x(Vnet*cos(theta));
                for(auto it:frendList) it->setVel_x(Vnet*cos(theta));
                for(auto it:frendList) it->setVel_y(-Vnet*sin(theta));
                for(auto it:enemyList) it->setVel_y(-Vnet*sin(theta));
                lava->setVel_x(0);
                lava->setVel_y(-Vnet*sin(theta));
            }
            
        }
    }
    return true;
}