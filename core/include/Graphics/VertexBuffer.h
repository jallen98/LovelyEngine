#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "System/Types.h"

/// @file VertexBuffer.h
/// @brief High level abstraction of OpenGL VBOs

namespace lov {
    namespace Graphics {
        /// @brief A vertex buffer object that can be bound to OpenGL
        class VertexBuffer {
        public:
            /// @brief Generate the OpenGL buffer for this VertexBuffer
            VertexBuffer();

            /// @brief Deallocate this VertexBuffer
            ~VertexBuffer();

            /// @brief Sends the given data to the OpenGL buffer
            /// @tparam T The type of data to buffer
            /// @param data The data to buffer
            /// @param size The size of the data to buffer
            template <typename T>
            inline void bufferData(const T* data, lov_size size) {
                glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
            }

            /// @brief Bind this VertexBuffer to the OpenGL state
            void bind() const;

            /// @brief Unbind this VertexBuffer from the OpenGL state
            void unbind() const;

        private:
            /// @brief ID of this VertexBuffer
            lov_uint m_id;
        };
    }
}
