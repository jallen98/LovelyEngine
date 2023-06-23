#include "Graphics/Window.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main() {
    lov::Graphics::Window window(800, 600, "Lovely Engine");

    window.setClearColor(0.2f, 0.3f, 0.3f);

    float vertices[] = {
        // positions         // colors
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
    };

    lov::Graphics::Shader shader;
    shader.compileFromFiles("/home/jallen/LovelyEngine/core/res/Shaders/basic.vs", "/home/jallen/LovelyEngine/core/res/Shaders/basic.fs");
    shader.bind();

    lov::Graphics::VertexArray vao;
    lov::Graphics::VertexBuffer vbo;

    vao.bind();
    vbo.bind();
    vbo.bufferData(vertices, sizeof(vertices));

    vao.linkAttribute(0, 3, lov::LOV_FLOAT, 6 * sizeof(float), 0);
    vao.linkAttribute(1, 3, lov::LOV_FLOAT, 6 * sizeof(float), 3 * sizeof(float));

    while(window.isOpen()) {
        if (window.getKeyState(lov::Input::KEY_ESCAPE)) {
            window.close();
        }

        window.clear();

        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.update();
    }
}
