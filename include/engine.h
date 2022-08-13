#ifndef ENGINE_H
#define ENGINE_H


#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdbool.h>

#include "SDLRef.h"
#include "constants.h"

#include "gameobject.h"

class Engine
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Engine();
    std::vector<GameObjectBase *> renderObjects;
    

public:
    ~Engine();
    static Engine& getInstance()
    {
        static Engine INSTANCE;
        return INSTANCE;
    }
      /* data */
    int init();
    int run();
    int destory();
};

#endif // ENGINE_H
