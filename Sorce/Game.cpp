#include "Game.h"

Game::Game()
{
    red = 0;
    green = 0;
    blue = 0;
    alpha = 255;
    
    Init("Game", 800, 600, false);
    TTF_Init();
    Run();
}

Game::~Game(){}

void Game::Run()
{
    unsigned int frameStart;
    unsigned int frameTime;

    while(GetIsRunning()){
        frameStart = SDL_GetTicks();
        HandleEvents();
        Update();
        Render();
        frameTime = SDL_GetTicks() - frameStart;
        if(FRAME_DELAY > frameTime){
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }
    Clean();
}

void Game::HandleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch (event.type) {
            //ends the program when the x on the window is clicked
            case SDL_QUIT: 
                SetIsRunning(false);
            break;

            default:
            break;
        }   
    }   
}

void Game::Update()
{
}

void Game::Render()
{   
    SDL_RenderClear(GetRenderer());
    SDL_SetRenderDrawColor(GetRenderer(), --red%255, --green%255, --blue%255, alpha);
    SDL_RenderPresent(GetRenderer());
}

void Game::Clean()
{
    TTF_Quit();
    SDL_DestroyWindow(GetWindow());
    SDL_DestroyRenderer(GetRenderer());
    SDL_Quit();
}

void Game::Restart()
{    
}