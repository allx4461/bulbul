#include "world.h"
#include <vector>

World::World(float width, float height): w_width(width), w_height(height){}

World::~World(){
    if (entities.size() != 0):
        for (auto& entity:entities){
            delete entity;
        }
}

void World::update(float dt){
    for (auto& entity:w_entities){
        entitiy->update(*this, dt);
    }
    applyAdd();
    applyRemove();
}

void World::render(Canvas& canvas){
    drawBack(canvas);

    for (Entity* entity:w_entities){
        entity->draw(canvas);
    }
}

void World::addEntity(std::unique_ptr<Entity> entitiy){
    queue_add.push_back(std::move(entity));

}


void World::removeEntity(Entity* entity){
    queue_remove.push_back(entity);

}

void World::clear(){
    w_entities.clear();
    queue_add.clear();
    queue_remove.clear();
}

int World::width(){
    return w_width;
}

int World::height(){
    return w_height;
}

bool World::inside(int x, int y){
    return (x>=0 && x<=w_width) && (y>=0 && y<= w_height);
}

void World::applyAdds(){
    if (queue_add.empty()) return;

    for (auto& entity:queue_add){
        w_entities.push_back(std::move(entity));
    }
    queue_add.clear();
}

void World::applyRemoves(){
    if (queue_remove.empty()) return;

    for (auto* entity:queue_remove){
        delete
    }
}