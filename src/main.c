#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 420
#define WIDTH 640

SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;

const int nL = 2;

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
    if(rand() % 2) // 1 => x, 0=>y
        l->x += ranD *l->len;
    else
        l->y += ranD *l->len;
}


void DrawAndUpdateLine(Line *l){
    int cX = l->x, cY = l->y;
    RandXY(l);
    SDL_SetRenderDrawColor(ren, l->r, l->g, l->b, 255);
    SDL_RenderLine(ren, cX, cY, l->x, l->y);
}

void Update(Line l[]){
    for(int i=0; i<nL; i++){
        DrawAndUpdateLine(&l[i]);
    }
}

int main(int argc, char *args[]){
    srand(time(NULL));
    if(!SDL_CreateWindowAndRenderer("Main-Screen", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE, &win, &ren)){
        SDL_Log("Couldn't Create Window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    Line line[nL];
    for(int i=0; i<nL; i++) LineInitial(&line[i]);

    int running = 1;
    while(running){
        SDL_Event e;
        if(SDL_PollEvent(&e)){
            if(e.type == SDL_EVENT_QUIT)
                running = 0;
        }
        Update(line);
        SDL_RenderPresent(ren);
        SDL_Delay(20);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}