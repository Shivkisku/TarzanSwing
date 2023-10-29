//
//  EventManager.cpp
//  SDL_EXPERIMENTING
//
//  Created by Rahul Jain on 05/12/21.
//

#include "EventManager.hpp"
#include <iostream>

bool eventManager::Exit_MouseClick(int x, int y, int text_y, int text_width, int scr_width){
    int k1 = (scr_width - text_width)/2;
    int k2 = (scr_width + text_width)/2;
    if((x>=k1) && (x<=k2) && (y>=text_y) && (y<=text_y+38))
        return false;
    return true;
}

bool eventManager::Play_MouseClick(int x, int y, int text_width, int scr_width){
    int k1 = (scr_width - text_width)/2;
    int k2 = (scr_width + text_width)/2;
    if((x>=k1) && (x<=k2) && (y>=350) && (y<=350+38))
        return true;
    return false;
}

bool eventManager::Retry_MouseClick(int x, int y, int text_width, int scr_width){
    int k1 = (scr_width - text_width)/2;
    int k2 = (scr_width + text_width)/2;
    if((x>=k1) && (x<=k2) && (y>=400) && (y<=400+36))
        return false;
    return true;
}

bool eventManager::MouseClick(SDL_MouseButtonEvent& b, Rope* aRope, Me* mainObject, std::vector<Object*> enemyList, std::vector<Object*> frendList)
{
    if(b.type == SDL_MOUSEBUTTONDOWN)
    {
        if(b.button == SDL_BUTTON_LEFT)
        {
            std::cout<<"DANCE"<<std::endl;
            aRope->setTarget(b, mainObject, enemyList, frendList);
            aRope->setInitialPosn(aRope->giveOther()->getPosn());
            aRope->setInitialVel(aRope->giveOther()->getVel());
            aRope->setRopeLength(aRope->giveInitialSep());
            return true;
        }
    }
    if(b.type == SDL_MOUSEBUTTONUP)
    {
        return false;
    }
    return false;
}
