#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <SDL2/SDL.h>
#include "../EntityManager.h"
#include "../../lib/glm/glm.hpp"
#include "../Game.h"

class TransformComponent : public Component {
  public:
    glm::vec2 _position;
    glm::vec2 _velocity;
    int _width;
    int _height;
    int _scale;

    TransformComponent(
        int posX,
        int posY,
        int velX,
        int velY,
        int width,
        int height,
        int scale
        ){
      _position = glm::vec2(posX, posY);
      _velocity = glm::vec2(velX, velY);
      _width = width;
      _height = height;
      _scale = scale;
    }
    void Initialize() override{

    }

    void Update(float deltaTime) override {

    }

    void Render() override {
      SDL_Rect transformRectangle{
        (int) _position.x,
        (int) _position.y,
        _height,
        _width
      };

      SDL_SetRenderDrawColor(Game::_renderer, 255, 255, 255, 255);
      SDL_RenderFillRect(Game::_renderer, &transformRectangle);
    }

};

#endif
