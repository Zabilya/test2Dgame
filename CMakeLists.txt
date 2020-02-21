cmake_minimum_required(VERSION 3.8)
project(lofi_ping_pong)

set(CMAKE_CXX_STANDARD 14)

find_package (OpenGL REQUIRED)
find_package (glfw3 REQUIRED)
find_package(glew REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp  src/utils/utils.cpp src/window_manager/windowManager.cpp src/key_handler/keyHandler.cpp
        src/game/Game.cpp  src/textures/textures_util.cpp dependencies/stb_image/stb_image.cpp src/shader/Shader.cpp
        src/game/SpriteRenderer.cpp src/textures/Texture2D.cpp src/textures/Texture2D.h)

add_executable(lofi_ping_pong ${SOURCE_FILES})

target_link_libraries(lofi_ping_pong assimp)

target_link_libraries (lofi_ping_pong
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARY} glew32
        ${GLFW_LIBRARY} glfw
        )