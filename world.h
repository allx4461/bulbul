#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "entity.h"

class World{
public:
    World(float worldWidth, float worldHeight);
    ~World()=default;

    void update();//обновляет состояние
    void render(Canvas& canvas);

    void addEntity(std::unique_ptr<Entity> entity);
    void removeEntity(Entity* entity);
    void clear();

    int width() const;
    int height() const;
    bool inside(int x, int y) const; 

private:
    void applyAdds();
    void applyRemoves();

    void drawBack();

private:
    int w_width = 0;
    int w_height = 0;

    std::vector<std::unique_ptr<Entity>> w_entities;

    std::vector<std::unique_ptr<Entity>> queue_add;
    std::vector<Entity*> queue_remove;


}

#endif //WORLD_H