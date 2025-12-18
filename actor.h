#pragma once
#include "entity.h"
#include "sprite_utils.h"
#include <vector>
#include <string>

class Actor : public Entity {
protected:
    int x, y, w, h;
    int v; // -1 влево, +1 вправо
    std::vector<std::string> spriteRight;
    std::vector<std::string> spriteLeft;

public:
    Actor(int x, int y, int v, const std::vector<std::string>& sprite)
        : x(x), y(y), v(v), spriteRight(sprite)
    {
        spriteLeft = SpriteUtils::flipHorizontally(spriteRight);
        auto [ww, hh] = SpriteUtils::getSize(spriteRight);//std::pair<int,int> вместо first,second
        w = ww;
        h = hh;}

    virtual void move() {x += v;}

    std::vector<int> getinfo() override {
        return {x, y, w, h, v};}

    std::vector<char> getimage() override {
        const auto& src = (v >= 0 ? spriteRight : spriteLeft);//условие ? если_истина : если_ложь
        std::vector<char> res;
        res.reserve(w * h);//выделили память
        for (const auto& row : src) {res.insert(res.end(), row.begin(), row.end());}
        return res;}

    void update() override { move();}
};
