#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Util/Types.h"

/// @file VertexArray.h
/// @brief High level abstraction of OpenGL VAOs

namespace lov {
    namespace Graphics {
        /// @brief A vertex array object used to define OpenGL vertex buffers
        class VertexArray {
        public:
            /// @brief Generate the OpenGL VAO for this VertexArray
            VertexArray();

            /// @brief Deallocate this VertexArray
            ~VertexArray();

            /// @brief Link an attribute to this VertexArray. Make sure to bind the appropriate VertexBuffer beforehand
            /// @param location The layout location for this attribute in the shader
            /// @param componentCount The number of "LovelyType" components for this attribute
            /// @param type The enumerated type for this attribute
            /// @param stride The stride for this attribute in the VertexBuffer
            /// @param offset The offset of the attribute in the VertexBuffer
            void linkAttribute(lov_uint location, lov_uint componentCount, LovelyType type, lov_size stride, lov_size offset) const;

            /// @brief Bind this VertexArray to the OpenGL state
            void bind() const;

            /// @brief Unbind this VertexArray from the OpenGL state
            void unbind() const;

        private:
            /// @brief The ID for this VertexArray
            lov_uint m_id;
        };
    }
}
