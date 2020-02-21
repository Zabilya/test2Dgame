//
// Created by Илья Заболотний on 24/08/2019.
//

#include "keyHandler.h"

void processInput(GLFWwindow *window, Game *game, float deltaTime) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
//    } if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
//        game->processKeyboard(Q);
//    } if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//        game->processKeyboard(FORWARD);
//    } if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
//        game->processKeyboard(LEFT);
//    } if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
//        game->processKeyboard(RIGHT);
    }
}

