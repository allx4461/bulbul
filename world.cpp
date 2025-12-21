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
        entitiy->update(*this, dt); //обновляем состояние сущности(координаты, направление)
    }
}

void World::render(Canvas& canvas){
    drawBack(canvas); // рисуем фон

    for (Entity* entity:w_entities){
        entity->draw(canvas); // отрисовываем каждую сущность
    }
}

void World::addEntity(std::unique_ptr<Entity> entitiy){   
    w_entities.push_back(std::move(entity)); //добавляем в массив

}


void World::removeEntity(Entity* entity){
    for (int i=0; i<w_entities.size(); ++i){
        if (w_entities[w_entities.begin()+i] == entity){
            w_entities.erase(w_entities.begin()+i); //удаляем сущность из массива сущностей
        }
    }
}

void World::clear(){
    w_entities.clear(); //чистим массив
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
