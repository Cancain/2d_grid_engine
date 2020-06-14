#include "./Entity.h"

bool Entity::IsActive() const {
  return _isActive;
}

std::string Entity::GetName() const {
  return _name;
}

void Entity::SetName(std::string name){
  _name = name;
}

Entity::Entity(EntityManager& manager, std::string name) 
  :_manager(manager), _name(name){
    _isActive = true;
  };

Entity::Entity(EntityManager& manager): _manager(manager){
  _isActive = true;
}

void Entity::Update(float deltaTime){
  for (auto& component : _components){
    component->Update(deltaTime);
  }
}

void Entity::Render(){
  for(auto& component : _components){
    component->Render();
  }
}

void Entity::Destroy(){
  _isActive = false;
}

