#include "Graphics/VertexBuffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

lov::Graphics::VertexBuffer::VertexBuffer() {
    // Generate the OpenGL buffer
    glGenBuffers(1, &m_id);
}

lov::Graphics::VertexBuffer::~VertexBuffer() {
    // Delete the OpenGL VBO
    glDeleteBuffers(1, &m_id);
}

void lov::Graphics::VertexBuffer::bind() const {
    // Bind this buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void lov::Graphics::VertexBuffer::unbind() const {
    // Unbind this buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
