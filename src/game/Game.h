//
// Created by Ilya on 17.02.2020.
//

#ifndef LOFI_PING_PONG_GAME_H
#define LOFI_PING_PONG_GAME_H

#include "SpriteRenderer.h"
#include "../shader/Shader.h"
#include "../textures/textures_util.h"
#include "../../dependencies/glm/glm.hpp"
#include "../../dependencies/glm/gtc/matrix_transform.hpp"
#include "../../dependencies/glm/gtc/type_ptr.hpp"

enum GAME_STATE {
    MENU,
    PAUSE,
    IN_GAME
};

enum INPUT {
//    RIGHT,
//    LEFT,
//    FORWARD,
//    Q
};

class Game {
public:
    float width;
    float height;
    GAME_STATE state;

    //functions
    Game(float width, float height);
    void init();
    void processKeyboard(INPUT input);
    void update();
    void render();
};


#endif //LOFI_PING_PONG_GAME_H
