#include "./EntityManager.h"

void EntityManager::ClearData(){
  for (auto& entity : _entities){
    entity->Destroy();
  }
}

void EntityManager::Update(float deltaTime){
  for (auto& entity : _entities){
    entity->Update(deltaTime);
  }
}

void EntityManager::Render(){
  for (auto& entity : _entities){
    entity->Render();
  }
}

bool EntityManager::HasNoEntities() const{
  return _entities.size() <= 0;
}

Entity& EntityManager::AddEntity(std::string entityName){
  Entity* newEntity = new Entity(*this, entityName);
  _entities.push_back(newEntity);
  return *newEntity;
}

std::vector<Entity*> EntityManager::GetEntities() const {
  return _entities;
}

unsigned int EntityManager::GetEntityCount() const {
  return _entities.size();
}
