//
// Created by Ilya on 17.02.2020.
//

#include "Game.h"

SpriteRenderer *renderer;
unsigned int textureId;

Game::Game(float width, float height) {
    state = MENU;
    this->width = width;
    this->height = height;
}

void Game::init() {
    Shader spriteShader("../res/shaders/first.glsl");
    spriteShader.use();
    glm::mat4 projection = glm::ortho(0.0f, this->width, this->height, 0.0f, -1.0f, 1.0f);
    spriteShader.setInt("image", 0);
    spriteShader.setMat4("projection", projection);
    textureId = loadTexture("../res/textures/awesomefacepng.png");
    renderer = new SpriteRenderer(spriteShader);
}

void Game::processKeyboard(INPUT input) {
//    switch (state) {
//        case MENU:
//            if (input == RIGHT) {
//                state = IN_GAME;
//            }
//            break;
//        case PAUSE:
//            if (input == RIGHT) {
//                state = IN_GAME;
//            } else if (input == LEFT) {
//                state = MENU;
//            }
//            break;
//        case IN_GAME:
//            if (input == Q) {
//                state = PAUSE;
//            }
//            break;
//    }
}

void Game::update() {

}

void Game::render() {
    renderer->drawSprite(textureId, glm::vec2(200, 200), glm::vec2(300, 400),
            45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}
