#include "texture.h"



SDL_Texture* Texture::imageLoad( std::string path ) 
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        return NULL;
    }
    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface );
    if( newTexture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        return NULL;
    }

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

    return newTexture;
}

void Texture::imageDestroy()
{
    SDL_DestroyTexture(texture);
    //memset(texture, 0, sizeof(texture));
}

void Texture::imageRender()
{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Texture::imageRenderCrop(SDL_Rect *crop, SDL_Point *pos)
{
    SDL_Rect rect;
    rect.w = crop->w;
    rect.h = crop->h;

    if(pos)
    {
        rect.x = pos->x;
        rect.y = pos->y;
    }

    SDL_RenderCopy(renderer, texture, crop, &rect);
}


bool Texture::load_png(const char *file)
{
    // Load image
    texture = IMG_LoadTexture(renderer, file);
    if(!texture)
    {
        printf("Unable to load image '%s'!\n"
               "SDL_image Error: %s", file, IMG_GetError());
        return false;
    }

    // Get dimensions
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    rect.w = w;
    rect.h = h;

    return true;
}
