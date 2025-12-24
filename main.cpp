#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime> 
#include "fishes.h"
#include "world.h"
#include "canvas.h"
#include "sprite_utils.h"
#include "entity.h"
#include "bubble.h"

int main(){
    srand(time(0));
    World world(38, 170);
    Canvas canvas(world.width(), world.height());
    std::unique_ptr<fish3> entity = std::make_unique<fish3>(world.width(), world.height());
    world.addEntity(std::move(entity));
    std::cout << world.size() << std::endl;
    std::cout << "\033[?25l";
    for (int i=0; i<150; ++i){
        std::cout << "\033[H"; 
        canvas.clear();
        world.update();
        world.render(canvas);
        canvas.present();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "\033[?25h";
    return 0;
}

// #include <iostream>
// #include <thread>
// #include <chrono>

// int main() {
//     int x = 0;  // Начальная позиция рыбки

//     // Двигаем рыбку 10 раз
//     for (int i = 0; i < 10; ++i) {
//         // Возвращаем курсор в верхний левый угол
         

//         // Отображаем рыбку на текущей позиции
//         for (int j = 0; j < x; ++j) std::cout << " ";  // Пробелы
//         std::cout << "><*>" << std::endl;  // Рыбка

//         // Двигаем рыбку на 1 позицию вправо
//         x += 1;

//         // Задержка 500 миллисекунд
//         std::this_thread::sleep_for(std::chrono::milliseconds(500));
//     }

//     return 0;
// }