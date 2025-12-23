#include "fishes.h"
#include <cstdlib>


fish1::fish1(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-19)),   // x
        (rand() % (worldHeight-7))+2,  // y
        1,                     
    {
  ".        ,         ",
  "|\\._,,_..)\\      ",
  "|%%%%%%%%%%\"\"-._ ",
  "|/'-'-.%%%%{{{%* ´. ",
  "'      '--|/-----v´ "
}

    )
{}

fish2::fish2(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-9)),   // x
        (rand() % (worldHeight-6))+2,  // y
        1,                     // 
    {
  "__       ",
  "|\\ /%.\\",
  "|%X%%%%) ",
  "|/ \\V_/ "
}
    )
{}


fish3::fish3(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-19)),   // x
        (rand() % (worldHeight-7))+2,  // y
        1,                     // 
    {
"         ,--,_     ",
"__    _\\.---'-.   ",
"\\ '.-\"%%%%%//%o\\",
"/_.'-._%%%%\\%%/%\" ",
"       `\"--(/`\"   ",

}
    )
{}


fish4::fish4(int worldWidth, int worldHeight)
    : Actor(
        (rand() % (worldWidth-13)),   // x
        (rand() % (worldHeight-9))+2 ,  // y
        1,                     // v —
    {
"  :<>%><>    ",
"  :<>%%><>   ",
" ><>%><>%:<> ",
"><>%:<>%:<>  ",
"  :<>%><>%><>",
"><>%:<>%><>  ",
" ><>%%:<>    ",
}
    )
{}