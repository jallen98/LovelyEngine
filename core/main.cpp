#include "Graphics/Window.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Graphics/ElementBuffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main() {
    lov::Graphics::Window window(800, 600, "Lovely Engine");

    window.setClearColor(0.2f, 0.3f, 0.3f);

    float vertices[] = {
         // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
    };

    unsigned int indices[] = {
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    lov::Graphics::Shader shader;
    shader.compileFromFiles("/home/jallen/LovelyEngine/res/Shaders/basic.vs", "/home/jallen/LovelyEngine/res/Shaders/basic.fs");
    shader.bind();

    lov::Graphics::VertexArray vao;
    lov::Graphics::VertexBuffer vbo;

    vao.bind();
    vbo.bind();
    vbo.bufferData(vertices, sizeof(vertices));

    vao.linkAttribute(0, 3, lov::LOV_FLOAT, 8 * sizeof(float), 0);
    vao.linkAttribute(1, 3, lov::LOV_FLOAT, 8 * sizeof(float), 3 * sizeof(float));
    vao.linkAttribute(2, 2, lov::LOV_FLOAT, 8 * sizeof(float), 6 * sizeof(float));

    lov::Graphics::ElementBuffer ebo;
    ebo.bind();
    ebo.bufferIndices(indices, sizeof(indices));

    shader.setUniformInt("texture1", 0);
    shader.setUniformInt("texture2", 1);

    lov::Graphics::Texture woodTexture("/home/jallen/LovelyEngine/res/Textures/container.jpg");
    woodTexture.bind(0);

    lov::Graphics::Texture faceTexture("/home/jallen/LovelyEngine/res/Textures/awesomeface.png");
    faceTexture.bind(1);

    while(window.isOpen()) {
        if (window.getKeyState(lov::Input::KEY_ESCAPE)) {
            window.close();
        }

        window.clear();

        woodTexture.bind(0);
        faceTexture.bind(1);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        window.update();
    }
}
