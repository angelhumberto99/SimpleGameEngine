#include "Window.h"

Window::Window() : window(nullptr), renderer(nullptr){}
Window::~Window(){}

//Setters
void Window::SetScreenWidth(int value)
{ screenWidth = value; }

void Window::SetScreenHeight(int value)
{ screenHeight = value;}

void Window::SetIsRunning(bool value)
{ isRunning = value; }
void Window::SetWindow(SDL_Window* value)
{ window = value; }

void Window::SetRenderer(SDL_Renderer* value)
{ renderer = value; }

//Getters
int Window::GetScreenWidth()const
{ return screenWidth; }

int Window::GetScreenHeight()const
{ return screenHeight; }

bool Window::GetIsRunning()const
{ return isRunning; }

SDL_Window* Window::GetWindow()const
{ return window; }

SDL_Renderer* Window::GetRenderer()const
{ return renderer; }

/*this will initialized the window and all components 
to make SDL2 works properly*/
void Window::Init(const char* title, int w, int h, bool fullScreen)
{
    int flags = 0;
    if (fullScreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (!SDL_Init(SDL_INIT_EVERYTHING)){
        screenWidth = w;
        screenHeight = h;
        window = SDL_CreateWindow(title,
                        SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED,
                        screenWidth,
                        screenHeight,
                        flags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        if(renderer){
            isRunning = true;
        }
        else{
            std::cout<<"Couldn't initialize the renderer "<<SDL_GetError();
        }
    }
}