
#include "gameobject.h"

void GameObjectBase::start() 
{

}

void GameObjectBase::update() 
{
    
}

void GameObjectBase::render()
{
    if (!started) {
        this->start();
        this->started = true;
    }

    this->update();
}