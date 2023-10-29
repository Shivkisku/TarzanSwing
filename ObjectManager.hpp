#ifndef OBJECT_MANAGER_HPP
#define OBJECT_MANAGER_HPP

#include"Me.hpp"
#include"Object.hpp"

class ObjectManager{
    private:
        int windowWidth;
        int windowHeight;
        Me* mainObject;
        vector<Object*> specialFriendList;
    public:
        ObjectManager(int ww, int wh, Me* m);          
        void Spawn(vector<Object*>& el, vector<Object*>& fl, int bias);          
};

#endif