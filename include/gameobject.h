#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDLRef.h"

class GameObjectBase
{
private:
    SDL_Renderer *renderer;
    void render();
public:
    GameObjectBase();
    ~GameObjectBase();

   
// protected:
//     void start () = 0;
//     void update () = 0;
};


#endif