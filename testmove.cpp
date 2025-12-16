#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Твоя картинка (обрати внимание: слэши/бэкслэши экранированы)
    std::vector<std::string> sprite = {
        " WW",
        " /..\\",
        " \\  /",
        "///\\\\\\"
    };

    // вычислим ширину спрайта
    int sprite_w = 0;
    for (auto &s : sprite) sprite_w = std::max(sprite_w, (int)s.size());

    const int term_w = 80;                    // условная ширина терминала
    const int max_x  = std::max(0, term_w - sprite_w - 1);

    // очистить экран + спрятать курсор
    std::cout << "\x1b[2J\x1b[?25l" << std::flush;

    for (int x = 0; x <= max_x; ++x) {
        std::cout << "\x1b[H";                // курсор в левый верх

        for (const auto& line : sprite) {
            std::cout << std::string(x, ' ') << line << "\n";
        }

        std::cout << "\nCtrl+C to stop\n" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }

    // показать курсор обратно (если цикл закончился сам)
    std::cout << "\x1b[?25h" << std::flush;
    return 0;
}
