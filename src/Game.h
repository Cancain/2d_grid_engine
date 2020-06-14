#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "./Constants.h"
#include "./EntityManager.h"

class Game {
  private:
    bool _isRunning;
    SDL_Window *_window;
    float _deltaTime;
    int _ticksLastFrame;
    void _updateDeltaTime();
    void _waitForTargetFramerate();

  public:
    Game();
    ~Game();
    bool IsRunning() const;
    void Initialize(const int width,const int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
    void SetPlayer(SDL_Rect *player);
    SDL_Rect *GetPlayer();
    void SetDeltaTime(const float deltaTime);
    float GetDeltaTime() const;
    static SDL_Renderer *Renderer;

};

#endif
