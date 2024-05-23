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
#include "System/Exceptions.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <iostream>

#include <fstream>

int main(int argc, char *argv[]) {
    std::string resPath = "";

    // Parse arguments
    if (argc < 2) {
        std::cerr << "Absolute path to 'res' directory required - see README" << std::endl;
        return -1;
    }
    else {
        resPath = argv[1];
    }

    // Filepaths
    std::string containerDiffusePath = resPath + "/Textures/container_diffuse.png";
    std::string containerSpecularPath = resPath + "/Textures/container_specular.png";
    std::string basicShaderVertexPath = resPath + "/Shaders/basic.vs";
    std::string basicShaderFragPath = resPath + "/Shaders/basic.fs";
    std::string lightShaderVertexPath = resPath + "/Shaders/light.vs";
    std::string lightShaderFragPath = resPath + "/Shaders/light.fs";

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

    lov::Vector3f pointLightPositions[] = {
        lov::Vector3f(0.7f, 0.2f, 2.0f),
        lov::Vector3f(2.3f, -3.3f, -4.0f),
        lov::Vector3f(-4.0f, 2.0f, -12.0f),
        lov::Vector3f(0.0f, 0.0f, -3.0f)
    };

    float attenuationConstant = 1.0f;
    float attenuationLinear = 0.09f;
    float attenuationQuadratic = 0.032f;

    lov::Graphics::Texture containerDiffuse(containerDiffusePath.c_str());
    lov::Graphics::Texture containerSpecular(containerSpecularPath.c_str());

    lov::Graphics::Material containerMaterial;
    containerMaterial.diffuseMapID = containerDiffuse.getID();
    containerMaterial.specularMapID = containerSpecular.getID();

    lov::Graphics::Shader mainShader;
    try {
        mainShader.compileFromFiles(basicShaderVertexPath, basicShaderFragPath);
    }
    catch (lov::Exceptions::ShaderException e) {
        std::cout << "Failed to compile main shader: " << e.what() << std::endl;
    }

    lov::Graphics::Shader lightShader;
    try {
        lightShader.compileFromFiles(lightShaderVertexPath, lightShaderFragPath);
    }
    catch (lov::Exceptions::ShaderException e) {
        std::cout << "Failed to compile light shader: " << e.what() << std::endl;
    }

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

    // Set projection matrix
    mainShader.setUniform("projection", projection);

    // Set point lights
    for (int i = 0; i < 4; i++) {
        std::string indexedLight = "pointLights[" + std::to_string(i) + "]";

        mainShader.setUniform(indexedLight + ".position", pointLightPositions[i]);

        mainShader.setUniform(indexedLight + ".ambient", lov::Vector3f(0.05f, 0.05f, 0.05f));
        mainShader.setUniform(indexedLight + ".diffuse", lov::Vector3f(0.8f, 0.8f, 0.8f));
        mainShader.setUniform(indexedLight + ".specular", lov::Vector3f(1.0f, 1.0f, 1.0f));

        mainShader.setUniform(indexedLight + ".attenuationConstant", attenuationConstant);
        mainShader.setUniform(indexedLight + ".attenuationLinear", attenuationLinear);
        mainShader.setUniform(indexedLight + ".attenuationQuadratic", attenuationQuadratic);
    }

    // Set directional light (the sun)
    mainShader.setUniform("sun.direction", { -0.2f, -1.0f, -0.3f });
    mainShader.setUniform("sun.ambient", lov::Vector3f(0.05f, 0.05f, 0.05f));
    mainShader.setUniform("sun.diffuse", lov::Vector3f(0.4f, 0.4f, 0.4f));
    mainShader.setUniform("sun.specular", lov::Vector3f(0.5f, 0.5f, 0.5f));

    // Set flashlight
    mainShader.setUniform("flashlight.ambient", lov::Vector3f(0.0f, 0.0f, 0.0f));
    mainShader.setUniform("flashlight.diffuse", lov::Vector3f(1.0f, 1.0f, 1.0f));
    mainShader.setUniform("flashlight.specular", lov::Vector3f(1.0f, 1.0f, 1.0f));

    mainShader.setUniform("flashlight.innerCutoff", cosf(lov::Util::toRadians(12.5f)));
    mainShader.setUniform("flashlight.outerCutoff", cosf(lov::Util::toRadians(17.5f)));

    mainShader.setUniform("flashlight.attenuationConstant", attenuationConstant);
    mainShader.setUniform("flashlight.attenuationLinear", attenuationLinear);
    mainShader.setUniform("flashlight.attenuationQuadratic", attenuationQuadratic);

    // Set material
    mainShader.setUniform("material.diffuse", 0);
    mainShader.setUniform("material.specular", 1);
    mainShader.setUniform("material.shininess", 64.0f);

    lightShader.bind();
    lightShader.setUniform("projection", projection);

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
        mainShader.setUniform("view", cam.getViewMatrix());
        mainShader.setUniform("flashlight.position", cam.getPosition());
        mainShader.setUniform("flashlight.direction", cam.getFront());

        lightShader.bind();
        lightShader.setUniform("view", cam.getViewMatrix());

        mainShader.bind();
        for (int i = 0; i < 10; i++) {
            mainShader.setUniform("cameraPos", cam.getPosition());

            lov::Graphics::Transform containerTransform;
            containerTransform = containerTransform.translate(cubePositions[i]);
            containerTransform = containerTransform.rotate(1.0f, 0.3f, 0.5f, 20.0f * i);
            mainShader.setUniform("model", containerTransform);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        lightShader.bind();
        for (int i = 0; i < 4; i++) {
            lov::Graphics::Transform lightTransform;
            lightTransform = lightTransform.translate(pointLightPositions[i]).scale(0.2f, 0.2f, 0.2f);

            lightShader.setUniform("model", lightTransform);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        window.update();
    }
}
