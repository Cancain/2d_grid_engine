#ifndef ENTITY_H
#define ENTITY_H

#include "./EntityManager.h"
#include "./Component.h"

class Entity{
  private:
    EntityManager& _manager;
    bool _isActive;
    std::vector<Component*> _Components;
    std::string _name;

  public:
    Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name);
    void Update(float deltaTime);
    void Render();
    void Destroy();
    bool IsActive() const;
    std::string GetName() const;
};

#endif
