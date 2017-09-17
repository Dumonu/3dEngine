#include <SDL.h>
#include <SDL_video.h>
#include <SDL_events.h>
#include <ctime>
#include "global.h"
#include "geo/vector.h"
#include "geo/point.h"

SDL_Window* win;
SDL_Renderer* renderer;

Point points[100];

void redrawScreen()
{
    SDL_SetRenderDrawColor(renderer, 100, 139, 237, 255);
    SDL_RenderFillRect(renderer, nullptr);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int i = 0; i < 100; ++i)
    {
        points[i].draw();
    }

    SDL_RenderPresent(renderer);
}

int main()
{
    //Boilerplate
    SDL_Init(SDL_INIT_VIDEO);
    win = SDL_CreateWindow("3D Graphics Engine", 100, 100, 300, 300, SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(win, -1, 0);
    SDL_SetRenderDrawColor(renderer, 100, 139, 237, 255);
    SDL_RenderFillRect(renderer, nullptr);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    std::srand(std::time(0));

    //Initialization
    for (int i = 0; i < 100; ++i)
    {
        int winWidth = 300;
        int winHeight = 300;
        SDL_GetWindowSize(win, &winWidth, &winHeight);
        double x = ((double)std::rand() / RAND_MAX) * winWidth - winWidth / 2;
        double y = ((double)std::rand() / RAND_MAX) * winHeight - winHeight / 2;
        double z = ((double)std::rand() / RAND_MAX) * winWidth - winWidth / 2;
        points[i] = Point(x, y, z);
    }

    redrawScreen();

    //Event handling
    while(1)
    {
        SDL_Event e;
        if(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
                break;
            if(e.type == SDL_KEYDOWN)
            {
                SDL_Keycode key = e.key.keysym.sym;

                switch(key)
                {
                case SDLK_d:
                    redrawScreen();
                    break;
                case SDLK_a:
                    {
                        Point origin(0,0,0);

                        Vector tempVector;
                        for (int i = 0; i < 100; ++i)
                        {
                            //store the current vector address for the point and set the point
                            tempVector = points[i] - origin;
                            // reset the point so that the scaled vector can be added
                            points[i] = origin;
                            // scale the vector and set the point to its new, scaled location
                            points[i] = points[i] + tempVector.scale(0.5, 0.5, 0.5);
                        }
                        redrawScreen();
                        break;
                    }
                case SDLK_s:
                    {
                        Point origin(0,0,0);

                        Vector tempVector;
                        for (int i = 0; i < 100; ++i)
                        {
                            //store the current vector address for the point and set the point
                            tempVector = points[i] - origin;
                            // reset the point so that the scaled vector can be added
                            points[i] = origin;
                            // scale the vector and set the point to its new, scaled location
                            points[i] = points[i] + tempVector.scale(2, 2, 2);
                        }
                        redrawScreen();
                        break;
                    }
                case SDLK_r:
                    {
                        Point origin(0,0,0);

                        Vector tempVector;
                        for (int i = 0; i < 100; ++i)
                        {
                            //store the current vector address for the point and set the point
                            tempVector = points[i] - origin;
                            // reset the point so that the rotated vector can be added
                            points[i] = origin;
                            // rotate the vector and set the point to its new, rotated location
                            points[i] = points[i] + tempVector.rotateXY(15);
                        }
                        redrawScreen();
                        break;
                    }
                case SDLK_ESCAPE:
                    SDL_Event exit;
                    exit.type = SDL_QUIT;
                    SDL_PushEvent(&exit);
                    break;
                }
            }
        }
    }
    SDL_Quit();
}
