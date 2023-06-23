#pragma once

/// @file Texture.h
/// @brief Defines the #lov::Graphics::Texture class that allows OpenGL textures to be created

#include "Util/Types.h"

namespace lov {
    namespace Graphics {
        /// @brief OpenGL texture that can be bound to the OpenGL state
        class Texture {
        public:
            /// @brief Load this Texture with the given file path
            /// @param path The file path of the texture
            Texture(const char* path);

            /// @brief Bind this Texture to the OpenGL state
            void bind() const;

            /// @brief Unbind this Texture from the OpenGL state
            void unbind() const;

        private:
            /// @brief The ID of this Texture
            lov_uint m_id;
        };
    }
}
