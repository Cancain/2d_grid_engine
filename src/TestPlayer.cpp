#include "./TestPlayer.h"


TestPlayer::TestPlayer(SDL_Renderer *renderer, const unsigned int yPos, const unsigned int xPos)
  :_yPos(yPos), _xPos(xPos), _velocity(0.05f){
    _body.x = _xPos;
    _body.y = _yPos;
    _body.h = 100;
    _body.w = 100;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &_body);
    SDL_RenderPresent(renderer);
  }

TestPlayer::TestPlayer(SDL_Renderer *renderer): 
  TestPlayer(renderer, 0, 0){}

void TestPlayer::SetXPos(const unsigned int x){
  _xPos = x;
}

void TestPlayer::SetYPos(const unsigned int y){
  _yPos = y;
}

unsigned int TestPlayer::GetXPos() const {
  return _xPos;
}

unsigned int TestPlayer::GetYPos() const {
  return _yPos;
}
