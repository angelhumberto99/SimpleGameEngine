#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"

class Game : public Window
{
    private:
        /*this constants are used for capping
         the frames per second in the game*/
        static const int FPS = 60;
        static const int FRAME_DELAY = 1000/FPS;
        int red, green, blue, alpha;

        void Run();
        void HandleEvents();
        void Update();
        void Render();
        void Clean();
        void Restart();

    public:
        Game();
        ~Game();
};

#endif //GAME_H