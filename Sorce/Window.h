#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include <iostream>

class Window
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        int screenWidth;
        int screenHeight;
        bool isRunning;

    public:
        Window();
        ~Window();

        //Setters
        void SetScreenWidth(int value);
        void SetScreenHeight(int value);
        void SetIsRunning(bool value);
        void SetWindow(SDL_Window* value);
        void SetRenderer(SDL_Renderer* value);

        //Getters
        int GetScreenWidth()const;
        int GetScreenHeight()const;
        bool GetIsRunning()const;
        SDL_Window* GetWindow()const;
        SDL_Renderer* GetRenderer()const;

        /*this will initialized the window and all components 
        to make SDL2 works properly*/
        void Init(const char* title, int w, int h, bool fullScreen);

        //this methods can be override by other classes
        virtual void Run() = 0;
        virtual void HandleEvents() = 0;
        virtual void Update () = 0;
        virtual void Render () = 0;
        virtual void Clean () = 0;
};

#endif //WINDOW_H