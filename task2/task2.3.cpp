#include <iostream>
#include <SDL.h>
#include <task2.0.h>
#include <vector>
#include <ctime>


int main(int arg, char* args[])
{
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;

    int arr_t[4] = { 255, 0, 50, 255 };
    int arr_c[4] = { 0, 0, 255, 0 };
    int arr_r[4] = { 0, 100, 255, 255 };

    vector<Shape*>shapes;    
   
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            int low = 60;
            int randx = low + rand() % 400;
            int randy = low + rand() % 300;
            int size_x = low + rand() % 250;
            int size_y = low + rand() % 250;
            int size_rad = low + rand() % 250;

            Point2D p(randx, randy);
            switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    
                    case SDLK_c: {
                        Circle c(p, arr_c, size_rad);
                        shapes.push_back(&c);
                        int len = shapes.size()-1;
                        shapes[len]->render(renderer);
                    }
                    break;

                    case SDLK_t: {
                        Triangle t(p, arr_t, size_x, size_y);
                        shapes.push_back(&t);
                        int len = shapes.size()-1;
                        shapes[len]->render(renderer);
                    }
                    break;

                    case SDLK_r: {
                        Rectangle r(p, arr_r, size_x, size_y);
                        shapes.push_back(&r);
                        int len = shapes.size()-1;
                        shapes[len]->render(renderer);
                    }
                    break;
                    case SDLK_q: {
                        quit = 1;
                    }
                    break;
                    case SDLK_x: {
                        shapes.clear();
                    }
                    break;    
                    default:
                        break;
                    }

                break;              
            }
        }
    
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}   