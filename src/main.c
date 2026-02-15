#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 720
#define WIDTH 720

SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;
SDL_Texture *canvas = NULL;

const int nL = 4;

typedef struct{
    int x, y, len;
    int r, g, b;
} Line;

void LineInitial(Line *l){
    l->x = WIDTH/2;
    l->y = HEIGHT/2;
    l->len = 10;
    l->r = rand() % 256;
    l->g = rand() % 256;
    l->b = rand() % 256;
}

void RandXY(Line *l){
    int ranD = (rand() % 2)? 1:-1;
    if(rand() % 2){ // 1 => x, 0=>y
        int newX = l->x + ranD *l->len;
        if(newX >= 0 && newX <= WIDTH)
            l->x = newX;
        else
            l->x -= ranD *l->len;
    }
    else{
        int newY = l->y + ranD *l->len;
        if(newY>=0 && newY<=HEIGHT)
            l->y = newY;
        else
            l->y -= ranD *l->len;
    }
}


void DrawAndUpdateLine(Line *l){
    int cX = l->x, cY = l->y;
    RandXY(l);
    SDL_SetRenderDrawColor(ren, l->r, l->g, l->b, 255);
    SDL_RenderLine(ren, cX, cY, l->x, l->y);
}

void Update(Line l[]){
    for(int i=0; i<nL; i++)
        DrawAndUpdateLine(&l[i]);
}

int main(int argc, char *args[]){
    srand(time(NULL));
    if(!SDL_CreateWindowAndRenderer("Main-Screen", WIDTH, HEIGHT, SDL_WINDOW_MAXIMIZED, &win, &ren)){
        SDL_Log("Couldn't Create Window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    canvas = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);
    SDL_SetRenderTarget(ren, canvas);
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    SDL_SetRenderTarget(ren, NULL);

    Line line[nL];
    for(int i=0; i<nL; i++) LineInitial(&line[i]);

    int running = 1;
    while(running){
        SDL_Event e;
        if(SDL_PollEvent(&e))
            if(e.type == SDL_EVENT_QUIT)
                running = 0;
        
        SDL_SetRenderTarget(ren, canvas);

        Update(line);

        SDL_SetRenderTarget(ren, NULL);
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);

        SDL_RenderTexture(ren, canvas, NULL, NULL);
        SDL_RenderPresent(ren);
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}