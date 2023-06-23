#include "Graphics/VertexArray.h"

lov::Graphics::VertexArray::VertexArray() {
    // Generate the OpenGL VAO
    glGenVertexArrays(1, &m_id);
}

lov::Graphics::VertexArray::~VertexArray() {
    // Delete the OpenGL VAO
    glDeleteVertexArrays(1, &m_id);
}

void lov::Graphics::VertexArray::linkAttribute(lov_uint location, lov_uint componentCount, LovelyType type, lov_size stride, lov_size offset) const {
    glVertexAttribPointer(location, componentCount, type, GL_FALSE, stride, reinterpret_cast<void*>(offset));
    glEnableVertexAttribArray(location);
}

void lov::Graphics::VertexArray::bind() const {
    // Bind this VAO
    glBindVertexArray(m_id);
}

void lov::Graphics::VertexArray::unbind() const {
    // Unbind this VAO
    glBindVertexArray(0);
}
