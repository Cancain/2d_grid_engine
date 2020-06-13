#include <iostream>
#include "./Game.h"

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
      SDL_WINDOW_FULLSCREEN
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
  _renderer = createRenderer(_window);

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

float dotVelX = 0.01f;
float dotVelY = 0.01f;

void moveTestDot(){
  dotPosX += dotVelX;
  dotPosY += dotVelY;
}

void Game::Update(){
  moveTestDot();


}

void createTestDot(SDL_Renderer *renderer){
  SDL_Rect dot {
    (int)dotPosX,
    (int)dotPosY,
    20,
    20
  };

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_RenderFillRect(renderer, &dot);
}

void Game::Render(){
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  SDL_RenderClear(_renderer);

  createTestDot(_renderer);

  SDL_RenderPresent(_renderer);
}

void Game::Destroy(){
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
};
