#include <iostream>
#include "./Game.h"

EntityManager* manager;
SDL_Renderer* Game::Renderer;

Game::Game(){
  _isRunning = false;
}

Game::~Game(){
}

bool Game::IsRunning() const {
  return _isRunning;
}

void Game::SetDeltaTime(const float deltaTime){
  _deltaTime = deltaTime;
};

float Game::GetDeltaTime() const{
  return _deltaTime;
}

SDL_Window *createWindow(const int width, const int height){
  SDL_Window *window = SDL_CreateWindow(
      "My game!", 
      SDL_WINDOWPOS_CENTERED, 
      SDL_WINDOWPOS_CENTERED, 
      width, 
      height, 
      SDL_WINDOW_BORDERLESS
      );

  if(!window){
    throw "Sorry, could not open a window";
  }

  return window;
}

SDL_Renderer *createRenderer(SDL_Window *window){
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  
  if(!renderer){
    throw "Sorry, could not create renderer";
  }

  return renderer;
}


void Game::Initialize(const int width, const int height){
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cerr << "Sorry, could not initialize SDL" << std::endl;
    return;
  }

  _window = createWindow(width, height);
  Renderer = createRenderer(_window);

  _isRunning = true;
  return;

}

void Game::ProcessInput(){
  SDL_Event event;
  SDL_PollEvent(&event);

  switch(event.type) {
    case SDL_QUIT:
      _isRunning = false;
      break;
    default:
      break;
  }
}

float dotPosX = 0;
float dotPosY = 0;

float dotVelX = 100.0f;
float dotVelY = 100.0f;

const int DOTSIZE = 20;

void moveTestDot(float deltaTime){
  static bool xMovePositive {true};
  static bool xHasReachedMax {false};
  static bool yMovePositive {true};
  static bool yHasReachedMax {false};

  if(dotPosX >= (WINDOW_WIDTH - DOTSIZE) && !xHasReachedMax){
    xMovePositive = false;
    xHasReachedMax = true;
  }

  if(dotPosX <= 0 && xHasReachedMax){
    xMovePositive = true;
    xHasReachedMax = false;
  }

  if(dotPosY >= (WINDOW_HEIGHT - DOTSIZE) && !yHasReachedMax){
    yMovePositive = false;
    yHasReachedMax = true;
  }

  if(dotPosY <= 0 && yHasReachedMax){
    yMovePositive = true;
    yHasReachedMax = false;
  }

  if(xMovePositive){
    dotPosX += dotVelX * deltaTime;
  } else {
    dotPosX -= dotVelX * deltaTime;
  }
  
  if(yMovePositive){
    dotPosY += dotVelY * deltaTime;
  } else {
    dotPosY -= dotVelY * deltaTime;
  }
}

void Game::_updateDeltaTime(){
  _deltaTime = (SDL_GetTicks() - _ticksLastFrame) / 1000.0f;
  _ticksLastFrame = SDL_GetTicks();
  _deltaTime = _deltaTime > 0.05f ? 0.05f : _deltaTime;
}

void Game::_waitForTargetFramerate(){
  int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - _ticksLastFrame);

  if(timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME){
    SDL_Delay(timeToWait);
  }
}

void Game::Update(){
  _waitForTargetFramerate();
  _updateDeltaTime();
  moveTestDot(_deltaTime);
  /* manager->Update(_deltaTime); */
}

//*
// Moving dot to test functionality, will be removed later
//*
void createTestDot(SDL_Renderer *renderer){
  SDL_Rect dot {
    (int)dotPosX,
    (int)dotPosY,
    DOTSIZE,
    DOTSIZE
  };

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &dot);
}

void Game::Render(){
  SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
  SDL_RenderClear(Renderer);
  createTestDot(Renderer);
  SDL_RenderPresent(Renderer);
  /* manager->Render(); */
}

void Game::Destroy(){
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
};
