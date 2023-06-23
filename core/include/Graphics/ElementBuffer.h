#pragma once

#include "Util/Types.h"

/// @file ElementBuffer.h
/// @brief Defines the lov::Graphics::ElementBuffer class used to create an OpenGL EBO

namespace lov {
    namespace Graphics {
        /// @brief An OpenGL EBO used to define indices for a vertex buffer
        class ElementBuffer {
        public:
            /// @brief Generate the OpenGL buffer
            ElementBuffer();

            /// @brief Deallocate the OpenGL buffer
            ~ElementBuffer();

            /// @brief Buffer the indices for this ElementBuffer
            /// @param indices An array of indices
            /// @param size The size of the given array
            void bufferIndices(const lov_uint* indices, lov_size size);

            /// @brief Bind this ElementBuffer
            void bind() const;

            /// @brief Unbind this ElementBuffer
            void unbind() const;

        private:
            /// @brief The ID of this EBO
            lov_uint m_id;
        };
    }
}
