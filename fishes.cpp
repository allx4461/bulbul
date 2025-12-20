#include "fishes.h"
#include <cstdlib>


fish1::fish1(int worldWidth, int worldHeight)
    : Actor(
        rand() % worldWidth,   // x
        rand() % worldHeight,  // y
        0,                     // v — по x не двигается
    {
        "         ,        .",
        "        /(.._,,_./|",
        "   _.-\"\"%%%%%%%%%%|",
        " .´¤%}}}%%%%.-'-'\\|",
        "´v-----\\|--'      '" 
    }
    )
{}

fish2::fish2(int worldWidth, int worldHeight)
    : Actor(
        rand() % worldWidth,   // x
        rand() % worldHeight,  // y
        0,                     // v — по x не двигается
    {
  "__  ",
  "|\\ /%.\\ ",
  "|%X%%%%)",
  "|/ \\V_/"
}
    )
{}


fish3::fish3(int worldWidth, int worldHeight)
    : Actor(
        rand() % worldWidth,   // x
        rand() % worldHeight,  // y
        0,                     // v — по x не двигается
    {
"         ,--,_",
"__    _\\.---'-.",
"\\ '.-\"     // o\\",
"/_.'-._    \\  /",
"       `\"--(/`",

}
    )
{}


fish4::fish4(int worldWidth, int worldHeight)
    : Actor(
        rand() % worldWidth,   // x
        rand() % worldHeight,  // y
        0,                     // v — по x не двигается
    {
":<> ><>",
"  :<>  ><>",
" ><> ><> :<>",
"><> :<> :<>",
"  :<> ><> ><>",
"><> :<> ><>",
" ><>  :<>",
}
    )
{}