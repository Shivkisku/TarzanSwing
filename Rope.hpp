#ifndef Rope_hpp
#define Rope_hpp

#include <stdio.h>
#include <math.h>
#include <vector>

#include "Object.hpp"
#include "Me.hpp"
#include "Lava.hpp"

#define K 0.0005
#define originalLen 0

class Rope{
private:
    Me* meNode;
    Object* otherNode;
    Vec2 initialPosn;
    Vel2 initialVel;
    double ropeLength;
    Vec2 slackOccurence;

public:

    bool RopeCalculus(bool slack,std::vector<Object*> enemyList, std::vector<Object*> frendList, Lava* lava);
    
    void setInitialPosn(Vec2 posn){initialPosn = posn;}
    void setInitialVel(Vel2 vel){initialVel = vel;}
    void setRopeLength(double len){ropeLength = len;}
    Me* giveMe(){return meNode;}
    Object* giveOther(){return otherNode;}
    double giveInitialSep();
    void setSlackOccurence(Vec2 posn){slackOccurence = posn;}
    
    void setTarget(SDL_MouseButtonEvent& b, Me* hero, std::vector<Object*> enemyList, std::vector<Object*> frendList);
    Object* getTarget(){return otherNode;}
    Vec2 getSlackOccurence(){return slackOccurence;}
};

#endif 
