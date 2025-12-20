#ifndef CANVAS_H
#define CANVAS_H

#include <vector>

class Canvas:
private:
    c_height = 0;
    c_width = 0;

public:
    Canvas(int width, int height);
    ~Canvas();

    void clear();
    void addSprite(const std::vector<std::vector<char>>& entity, int x, int y);
    void viewPresent();
    void drawBorder();



#endif //CANVAS_H