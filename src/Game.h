#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game{
  private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

  public:
    Game();
    ~Game();
    bool IsRunning() const;
    void Initialize(const int width,const int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

};

#endif
