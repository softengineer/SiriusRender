#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDLRef.h"
#include <stdio.h>
#include <string>

class Texture
{
    private:

        SDL_Renderer *renderer;
    
        // Loaded texture
        SDL_Texture *texture;

        // Original width and height
        int w, h;

        // Current coordinates, width and height
        SDL_Rect rect;

    public :
        bool imageLoad(  const char *file);
        void imageDestroy();

        void imageRender(); 
        void imageRenderCrop(SDL_Rect *crop, SDL_Point *pos);
        SDL_Surface*  imageLoad(SDL_Surface * surface, std::string path);

        Texture(SDL_Renderer *renderer) {
            this->renderer = renderer;
        };
};


#endif