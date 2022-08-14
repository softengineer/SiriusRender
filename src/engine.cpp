#include <engine.h>



 
Engine::Engine(/* args */) : window(NULL), renderer(NULL)
{
}

Engine::~Engine()
{
}



int Engine::init() {
   // Unused argc, argv

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL could not be initialized!\n"
                        "SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Initialize SDL image
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if((IMG_Init(flags) & flags) != flags) {
        fprintf(stderr, "SDL_image could not be initialized with JPG and PNG support!\n"
                        "SDL_image Error: %s\n", IMG_GetError());
        return 0;
    }

      // Create window
    window = SDL_CreateWindow(APP_NAME,
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if(!window)
    {
        fprintf(stderr, "Window could not be created!\n"
                        "SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create renderer
    // renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // if(!renderer)
    // {
    //     fprintf(stderr, "Renderer could not be created!\n"
    //                     "SDL_Error: %s\n", SDL_GetError());
        
    //     return -1;
    // }

    return 0;
}

int Engine::run() {
    //Event handler
    SDL_Event e;

    while( !quit )
    {
        //Handle SDL events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        for (GameObjectBase * o : renderObjects) 
        {
            o->render();
        }
        //Update screen
        SDL_RenderPresent( renderer );
    }
   
    return 0;
}

 int Engine::destory() {
    if (renderer != NULL) {
         SDL_DestroyRenderer(renderer);
    }

    if (window != NULL) {
        SDL_DestroyWindow(window);
    }

    return 0;
 }