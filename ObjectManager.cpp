#include "ObjectManager.hpp"

ObjectManager::ObjectManager(int ww, int wh, Me* m){
    windowWidth=ww;
    windowHeight=wh;
    mainObject=m;  
    
}

void ObjectManager::Spawn(vector<Object*>& el, vector<Object*>& fl, int bias){
    srand(time(0));

    Object* special1 =new Object(false, windowWidth/2+bias, windowHeight/4, 20);
    fl.push_back(special1);
    for(int i=0;i<10;i++)
    {
        double randX = (rand() % (int)(special1->getPosn().x + windowWidth/2 - (special1->getPosn().x - windowWidth/2) + 1)) + (special1->getPosn().x - windowWidth/2);
        double randY = (rand() % (int)(special1->getPosn().y - (special1->getPosn().y - windowHeight/4) + 1)) + (special1->getPosn().y - windowHeight/4);
        Object* temp = new Object(false,randX,randY,20);
        fl.push_back(temp);
    }
    for(int i=0;i<2;i++)
    {
        double randX = (rand() % (int)(special1->getPosn().x + windowWidth/2 - (special1->getPosn().x - windowWidth/2) + 1)) + (special1->getPosn().x - windowWidth/2);
        double randY = (rand() % (int)(special1->getPosn().y - (special1->getPosn().y - windowHeight/4) + 1)) + (special1->getPosn().y - windowHeight/4);
        Object* temp = new Object(true,randX,randY,20);
        el.push_back(temp);
    }


    Object* special2 =new Object(false, windowWidth/2+bias, windowHeight/2, 20);
    fl.push_back(special2);
    for(int i=0;i<45;i++)
    {
        double randX = (rand() % (int)(special2->getPosn().x + windowWidth/2 - (special2->getPosn().x - windowWidth/2) + 1)) + (special2->getPosn().x - windowWidth/2);
        double randY = (rand() % (int)(special2->getPosn().y+windowHeight/4 - (special2->getPosn().y -windowHeight/4) + 1)) + (special2->getPosn().y - windowHeight/4);
        Object* temp = new Object(false,randX,randY,20);
        fl.push_back(temp);
    }
    for(int i=0;i<3;i++)
    {
        double randX = (rand() % (int)(special2->getPosn().x + windowWidth/2 - (special2->getPosn().x - windowWidth/2) + 1)) + (special2->getPosn().x - windowWidth/2);
        double randY = (rand() % (int)(special2->getPosn().y+windowHeight/4 - (special2->getPosn().y -windowHeight/4) + 1)) + (special2->getPosn().y - windowHeight/4);
        Object* temp = new Object(true,randX,randY,20);
        el.push_back(temp);
    }


    Object* special3 =new Object(false, windowWidth/2+bias, 3*windowHeight/4, 20);
    fl.push_back(special3);
    for(int i=0;i<10;i++)
    {
        double randX = (rand() % (int)(special3->getPosn().x + windowWidth/2 - (special3->getPosn().x - windowWidth/2) + 1)) + (special3->getPosn().x - windowWidth/2);
        double randY = (rand() % (int)(special3->getPosn().y+windowHeight/4 - (special3->getPosn().y) + 1)) + (special3->getPosn().y);
        Object* temp = new Object(false,randX,randY,20);
        fl.push_back(temp);
    }
    for(int i=0;i<2;i++)
    {
        double randX = (rand() % (int)(special3->getPosn().x + windowWidth/2 - (special3->getPosn().x - windowWidth/2) + 1)) + (special3->getPosn().x - windowWidth/2);
        double randY = (rand() % (int)(special3->getPosn().y+windowHeight/4 - (special3->getPosn().y) + 1)) + (special3->getPosn().y);
        Object* temp = new Object(true,randX,randY,20);
        el.push_back(temp);
    }
}