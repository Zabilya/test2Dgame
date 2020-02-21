//
// Created by Ilya on 19.02.2020.
//

#ifndef LOFI_PING_PONG_SPRITERENDERER_H
#define LOFI_PING_PONG_SPRITERENDERER_H

#include "../shader/Shader.h"
#include "../../dependencies/glm/glm.hpp"
#include "../../dependencies/glm/gtc/matrix_transform.hpp"
#include "../../dependencies/glm/gtc/type_ptr.hpp"

class SpriteRenderer {
public:
    SpriteRenderer(Shader shader);
    ~SpriteRenderer();

    void drawSprite(unsigned int texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color);

private:
    Shader shader;
    GLuint quadVAO;
    void initRenderData();
};


#endif //LOFI_PING_PONG_SPRITERENDERER_H
