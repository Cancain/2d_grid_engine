#ifndef _TestPlayer_h
#define _TestPlayer_h

#include <SDL2/SDL.h>

class TestPlayer {
  private:
    unsigned int _yPos;
    unsigned int _xPos;
    float _velocity;
    SDL_Rect _body;


  public: 
    TestPlayer(SDL_Renderer *renderer);
    TestPlayer(SDL_Renderer *renderer, unsigned int yPos, const unsigned int xPos);
    ~TestPlayer();
    void SetXPos(const unsigned int x);
    void SetYPos(const unsigned int y);
    unsigned int GetYPos() const;
    unsigned int GetXPos() const;
    void RenderPlayer(SDL_Renderer *renderer);
    float GetVelocity();
};

#endif
