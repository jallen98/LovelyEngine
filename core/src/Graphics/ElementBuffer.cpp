#include "Graphics/ElementBuffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

lov::Graphics::ElementBuffer::ElementBuffer() {
    // Generate the OpenGL buffer
    glGenBuffers(1, &m_id);
}

lov::Graphics::ElementBuffer::~ElementBuffer() {
    // Delete the OpenGL buffer
    glDeleteBuffers(1, &m_id);
}

void lov::Graphics::ElementBuffer::bufferIndices(const lov_uint* indices, lov_size size) {
    // Buffer the indices
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void lov::Graphics::ElementBuffer::bind() const {
    // Bind this ElementBuffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void lov::Graphics::ElementBuffer::unbind() const {
    // Unbind this ElementBuffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
