#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDLRef.h"

class GameObjectBase
{
friend class Engine;
private:
    SDL_Renderer *renderer;
    void render();
    bool started;
    
public:
    //game object position
    Vector2 transform;

    GameObjectBase();
    ~GameObjectBase();

   
protected:
    virtual void start ();
    virtual void update ();

};


#endif