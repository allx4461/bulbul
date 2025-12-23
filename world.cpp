#include "world.h"
#include "canvas.h"
#include "entity.h"
#include <vector>

World::World(float width, float height): w_width(width), w_height(height){}

void World::update(){
    for (auto& entity:w_entities){
        entity->update(*this); //обновляем состояние сущности(координаты, направление)
    }
}

void World::render(Canvas& canvas){
    drawBack(canvas); // рисуем фон

    for (Entity* entity:w_entities){
        entity->draw(canvas); // отрисовываем каждую сущность
    }
}

void World::addEntity(std::unique_ptr<Entity> entity){   
    w_entities.push_back(std::move(entity)); //добавляем в массив

}


void World::removeEntity(Entity* entity){
    for (int i=w_entities.begin(); i!=w_entities.end(); ++i){
        if (w_entities[i] == entity){
            w_entities.erase(i); //удаляем сущность из массива сущностей
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
    return (x>=0 && x<=w_width) && (y>=0 && y<= w_height);//проверка не вывалилась ли рыбка за аквариум
}
