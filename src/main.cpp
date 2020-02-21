#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window_manager/windowManager.h"
#include "game/Game.h"
#include <iostream>
#include "utils/utils.h"
#include "key_handler/keyHandler.h"

using namespace std;

const GLuint SCREEN_WIDTH = 800;
const GLuint SCREEN_HEIGHT = 600;

int main() {
    if (!glfwInit()) {
        exit(1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "window", NULL, NULL);
    if (!window)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initializing GLEW (this library give us all ogl functions) */
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        cout << "ERROR with GLEW" << endl;
        cout << glewGetErrorString(err) << endl;
        return -1;
    }
    showOpenglVersion();

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    /* for resizing window */
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
    game.init();

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while(!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        processInput(window, &game, deltaTime);

        game.update();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        game.render();

//        switch (game.state) {
//            case MENU:
//                glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
//                glClear(GL_COLOR_BUFFER_BIT);
//                break;
//            case PAUSE:
//                glClearColor(0.0f, 0.2f, 0.0f, 1.0f);
//                glClear(GL_COLOR_BUFFER_BIT);
//                break;
//            case IN_GAME:
//                glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
//                glClear(GL_COLOR_BUFFER_BIT);
//                break;
//        }

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}