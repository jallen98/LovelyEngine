#include "Graphics/Shader.h"

#include <cstddef>
#include <fstream>
#include <sstream>
#include <string>

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

    // Compile the fragment shader
    unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragShader);

    // Link the shader program
    m_id = glCreateProgram();
    glAttachShader(m_id, vertexShader);
    glAttachShader(m_id, fragShader);
    glLinkProgram(m_id);

    // Cleanup
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}

void lov::Graphics::Shader::compileFromFiles(const char* vertexShaderPath, const char* fragmentShaderPath) {
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

void lov::Graphics::Shader::setUniformBool(const char* name, bool value) {
    setUniformInt(name, value);
}

void lov::Graphics::Shader::setUniformInt(const char* name, int value) {
    glUniform1i(glGetUniformLocation(m_id, name), value);
}

void lov::Graphics::Shader::setUniformFloat(const char* name, float value) {
    glUniform1f(glGetUniformLocation(m_id, name), value);
}
