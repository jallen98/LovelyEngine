#include "Graphics/Window.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Graphics/ElementBuffer.h"
#include "System/Vector.h"
#include "Graphics/Transform.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main() {
    lov::Graphics::Window window(800, 600, "Lovely Engine");

    window.setClearColor(0.2f, 0.3f, 0.3f);

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    lov::Vector3f cubePositions[] = {
        lov::Vector3f( 0.0f,  0.0f,  0.0f),
        lov::Vector3f( 2.0f,  5.0f, -15.0f),
        lov::Vector3f(-1.5f, -2.2f, -2.5f),
        lov::Vector3f(-3.8f, -2.0f, -12.3f),
        lov::Vector3f( 2.4f, -0.4f, -3.5f),
        lov::Vector3f(-1.7f,  3.0f, -7.5f),
        lov::Vector3f( 1.3f, -2.0f, -2.5f),
        lov::Vector3f( 1.5f,  2.0f, -2.5f),
        lov::Vector3f( 1.5f,  0.2f, -1.5f),
        lov::Vector3f(-1.3f,  1.0f, -1.5f)
    };

    lov::Graphics::Shader shader;
    shader.compileFromFiles("/home/jallen/LovelyEngine/res/Shaders/basic.vs", "/home/jallen/LovelyEngine/res/Shaders/basic.fs");
    shader.bind();

    lov::Graphics::VertexArray vao;
    lov::Graphics::VertexBuffer vbo;

    vao.bind();
    vbo.bind();
    vbo.bufferData(vertices, sizeof(vertices));

    vao.linkAttribute(0, 3, lov::LOV_FLOAT, 5 * sizeof(float), 0);
    vao.linkAttribute(1, 2, lov::LOV_FLOAT, 5 * sizeof(float), 3 * sizeof(float));

    shader.setUniformInt("texture1", 0);
    shader.setUniformInt("texture2", 1);

    lov::Graphics::Texture woodTexture("/home/jallen/LovelyEngine/res/Textures/container.jpg");
    woodTexture.bind(0);

    lov::Graphics::Texture faceTexture("/home/jallen/LovelyEngine/res/Textures/awesomeface.png");
    faceTexture.bind(1);

    lov::Graphics::Transform view;
    view = view.translate(0.0f, 0.0f, -3.0f);
    shader.setUniformTransform("view", view);

    lov::Graphics::Transform projection(lov::Util::toRadians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    shader.setUniformTransform("projection", projection);

    while(window.isOpen()) {
        if (window.getKeyState(lov::Input::KEY_ESCAPE)) {
            window.close();
        }
        window.clear();

        woodTexture.bind(0);
        faceTexture.bind(1);

        for (int i = 0; i < 10; i++) {
            lov::Graphics::Transform model;
            model = model.translate(cubePositions[i]);
            float angle = 20.0f * i;
            model = model.rotate(1.0f, 0.3f, 0.5f, lov::Util::toRadians(angle));
            shader.setUniformTransform("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        window.update();
    }
}
