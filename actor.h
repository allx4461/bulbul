#include "entity.h"
#include <vector>
class Actor: public Entity{
private:
    int x;//верхний левый горизонталь
    int y;//верхний левый вертикаль
    int w;//ширина в символах
    int h;//высота в символах
    int v; //отвечает за направление и порядок отрисовки
    std::vector<std::string> sprite; //хранит строчные спрайты
public:
    virtual void move();
    std::vector<int> getinfo() override {
        return {x, y, w, h, v};
    }
};