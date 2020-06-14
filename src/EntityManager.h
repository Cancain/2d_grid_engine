#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <string>
#include "./Entity.h"
#include "./Component.h"

class EntityManager{
  private:
    std::vector<Entity*> _entities; 

  public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntities() const;
    Entity& AddEntity(std::string entityName);
    std::vector<Entity*> GetEntities() const;
    unsigned int GetEntityCount() const;
};

#endif

