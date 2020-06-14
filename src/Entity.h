#ifndef ENTITY_H
#define ENTITY_H

#include "./EntityManager.h"
#include "./Component.h"

class Entity{
  private:
    EntityManager& _manager;
    bool _isActive;
    std::vector<Component*> _components;
    std::string _name;

  public:
    bool IsActive() const;
    std::string GetName() const;
    void SetName(std::string name);
    Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name);
    void Update(float deltaTime);
    void Render();
    void Destroy();
};

#endif
