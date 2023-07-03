#include "Graphics/Window.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Graphics/ElementBuffer.h"
#include "System/Vector.h"
#include "Graphics/Transform.h"
#include "Graphics/Camera.h"
#include "Graphics/Material.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <iostream>

#include <fstream>

int main() {
    lov::Graphics::Window window(800, 600, "Lovely Engine");
    lov::Graphics::Camera cam({ 0.0f, 0.0f, 3.0f }, { 0.0f, 1.0f, 0.0f }, 0.0f, -90.0f);
    cam.clampPitch(true);

    window.setClearColor(0.1f, 0.1f, 0.1f);
    window.hideCursor(true);

    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
    };

    lov::Graphics::Texture containerDiffuse("/home/jallen/LovelyEngine/res/Textures/container_diffuse.png");
    lov::Graphics::Texture containerSpecular("/home/jallen/LovelyEngine/res/Textures/container_specular.png");

    lov::Graphics::Material containerMaterial;
    containerMaterial.diffuseMapID = containerDiffuse.getID();
    containerMaterial.specularMapID = containerSpecular.getID();

    lov::Graphics::Transform cubeTransform;
    lov::Graphics::Transform lightTransform;

    lightTransform = lightTransform.translate(1.2f, 1.0f, 2.0f).scale(0.2f, 0.2f, 0.2f);

    lov::Graphics::Shader mainShader;
    mainShader.compileFromFiles("/home/jallen/LovelyEngine/res/Shaders/basic.vs", "/home/jallen/LovelyEngine/res/Shaders/basic.fs");

    lov::Graphics::Shader lightShader;
    lightShader.compileFromFiles("/home/jallen/LovelyEngine/res/Shaders/light.vs", "/home/jallen/LovelyEngine/res/Shaders/light.fs");

    lov::Graphics::VertexArray vao;
    lov::Graphics::VertexBuffer vbo;

    vao.bind();
    vbo.bind();
    vbo.bufferData(vertices, sizeof(vertices));

    vao.linkAttribute(0, 3, lov::LOV_FLOAT, 8 * sizeof(float), 0);
    vao.linkAttribute(1, 3, lov::LOV_FLOAT, 8 * sizeof(float), 3 * sizeof(float));
    vao.linkAttribute(2, 2, lov::LOV_FLOAT, 8 * sizeof(float), 6 * sizeof(float));

    lov::Graphics::Transform projection = lov::Graphics::Transform::perspective(lov::Util::toRadians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    mainShader.bind();
    mainShader.setUniformTransform("model", cubeTransform);
    mainShader.setUniformTransform("projection", projection);

    mainShader.setUniformVector3("light.position", { 1.2f, 1.0f, 2.0f });
    mainShader.setUniformVector3("light.ambient", { 0.2f, 0.2f, 0.2f });
    mainShader.setUniformVector3("light.diffuse", { 0.5f, 0.5f, 0.5f });
    mainShader.setUniformVector3("light.specular", { 1.0f, 1.0f, 1.0f });

    mainShader.setUniformInt("material.diffuse", 0);
    mainShader.setUniformInt("material.specular", 1);
    mainShader.setUniformFloat("material.shininess", 64.0f);

    lightShader.bind();
    lightShader.setUniformTransform("model", lightTransform);
    lightShader.setUniformTransform("projection", projection);

    while(window.isOpen()) {
        float deltaTime = window.getDeltaTime();

        if (window.getKeyState(lov::Input::KEY_ESCAPE)) {
            window.close();
        }
        window.clear();

        float cameraSpeed = 2.5f * deltaTime;
        if (window.getKeyState(lov::Input::KEY_W) == lov::Input::KEY_PRESS) cam.move(cam.getFront(), cameraSpeed);
        if (window.getKeyState(lov::Input::KEY_S) == lov::Input::KEY_PRESS) cam.move(-cam.getFront(), cameraSpeed);
        if (window.getKeyState(lov::Input::KEY_A) == lov::Input::KEY_PRESS) cam.move(-cam.getRight(), cameraSpeed);
        if (window.getKeyState(lov::Input::KEY_D) == lov::Input::KEY_PRESS) cam.move(cam.getRight(), cameraSpeed);

        float mouseSens = 0.1f;
        lov::Vector2f c = window.getCursorOffset();
        cam.rotate(c.x, c.y, mouseSens);

        containerDiffuse.bind(0);
        containerSpecular.bind(1);

        mainShader.bind();
        mainShader.setUniformTransform("view", cam.getViewMatrix());

        lightShader.bind();
        lightShader.setUniformTransform("view", cam.getViewMatrix());

        mainShader.bind();
        mainShader.setUniformVector3("cameraPos", cam.getPosition());
        glDrawArrays(GL_TRIANGLES, 0, 36);

        lightShader.bind();
        glDrawArrays(GL_TRIANGLES, 0, 36);

        window.update();
    }
}
