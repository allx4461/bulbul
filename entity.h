#include <string>
#include <vector>
class Entity{
public:
    virtual ~Entity() =default;//киллить наследников
    virtual std::vector<int> getinfo()=0;//возвращает вектор из полей
    virtual std::vector<char> getimage()=0;//возвращает спрайт
    virtual void update()=0;};