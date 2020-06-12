#include <iostream>
#include "./Game.h"

Game::Game(){
  isRunning = false;
}

Game::~Game(){
}

bool Game::IsRunning() const {
  return isRunning;
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

  window = createWindow(width, height);
  renderer = createRenderer(window);

  isRunning = true;
  return;

}

void Game::ProcessInput(){
  SDL_Event event;
  SDL_PollEvent(&event);

  switch(event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
  }
}

void Game::Update(){}

void Game::Render(){}

void Game::Destroy(){};
