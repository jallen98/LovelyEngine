#include "Graphics/Shader.h"

#include <cstddef>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
lov::Graphics::Shader::~Shader() {
    // Delete the OpenGL shader program
    glDeleteProgram(m_id);
}

void lov::Graphics::Shader::bind() const {
    // Bind this shader
    glUseProgram(m_id);
}

void lov::Graphics::Shader::unbind() const {
    // Unbind this shader
    glUseProgram(0);
}

void lov::Graphics::Shader::compileFromText(const char* vertexShaderSource, const char* fragmentShaderSource) {
    // Compile the vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);


    int success;
    char infoLog[512];

    // Compile the fragment shader
    unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragShader);

    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    // Link the shader program
    m_id = glCreateProgram();
    glAttachShader(m_id, vertexShader);
    glAttachShader(m_id, fragShader);
    glLinkProgram(m_id);

    // Cleanup
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}

void lov::Graphics::Shader::compileFromFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    // Open the files
    std::ifstream vertexShaderFile(vertexShaderPath);
    std::ifstream fragmentShaderFile(fragmentShaderPath);

    // Read the contents of the files
    std::stringstream vertexShaderStream;
    vertexShaderStream << vertexShaderFile.rdbuf();

    std::stringstream fragmentShaderStream;
    fragmentShaderStream << fragmentShaderFile.rdbuf();

    // Close the files
    vertexShaderFile.close();
    fragmentShaderFile.close();

    // Compile the shaders
    std::string vertexShaderSource = vertexShaderStream.str();
    std::string fragmentShaderSource = fragmentShaderStream.str();
    compileFromText(vertexShaderSource.c_str(), fragmentShaderSource.c_str());
}

void lov::Graphics::Shader::setUniformBool(const std::string& name, bool value) {
    setUniformInt(name, value);
}

void lov::Graphics::Shader::setUniformInt(const std::string& name, int value) {
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
}

void lov::Graphics::Shader::setUniformFloat(const std::string& name, float value) {
    glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
}

void lov::Graphics::Shader::setUniformVector3(const std::string& name, const Vector3f& value) {
    glUniform3fv(glGetUniformLocation(m_id, name.c_str()), 1, &value[0]);
}

void lov::Graphics::Shader::setUniformTransform(const std::string& name, const Transform& value) {
    glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &value[0][0]);
}
