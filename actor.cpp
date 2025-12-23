#pragma once//https://en.cppreference.com/w/cpp/preprocessor/impl.html
#include "actor.h"

Actor::Actor(int x, int y, int v, const std::vector<std::string>& sprite)
    : x(x), y(y), v(v), spriteRight(sprite)//инициализация полей - поле(параметр конструктора)
{                      
    spriteLeft = SpriteUtils::flipHorizontally(spriteRight);

    auto [ww, hh] = SpriteUtils::getSize(spriteRight); //std::pair<int,int> вместо first,second
    w = ww;//^^ https://en.cppreference.com/w/cpp/utility/pair.html
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

void Actor::update(World& world){ 
    move();
    if !(world.inside(getinfo()[0],getinfo()[1])){
        v=-v;}}

void Actor::draw(Canvas& canvas){ 
    std::vector<std::vector<char>> sprite = getSprite(); 
    int x = this->x;
    int y = this->y; 
    canvas.addSprite(sprite,x,y,Color::Blue);
}