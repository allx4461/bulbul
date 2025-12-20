#include "actor.h"

Actor::Actor(int x, int y, int v, const std::vector<std::string>& sprite)
    : x(x), y(y), v(v), spriteRight(sprite)//инициализация полей - поле(параметр конструктора)
{                      
    spriteLeft = SpriteUtils::flipHorizontally(spriteRight);

    auto [ww, hh] = SpriteUtils::getSize(spriteRight); //std::pair<int,int> вместо first,second
    w = ww;
    h = hh;
}

std::vector<int> Actor::getinfo() {return {x, y, w, h, v};}

void Actor::move(){x += v;}

std::vector<char> Actor::getimage() {
        const auto& src = (v >= 0 ? spriteRight : spriteLeft);//условие ? если истина : если ложь
        std::vector<char> res;
        res.reserve(w * h);//выделили память
        for (const auto& row : src) {res.insert(res.end(), row.begin(), row.end());}  
        return res;}

void Actor::update(){ move();}