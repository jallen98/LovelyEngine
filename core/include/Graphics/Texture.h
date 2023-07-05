#pragma once

/// @file Texture.h
/// @brief Defines the #lov::Graphics::Texture class that allows OpenGL textures to be created

#include "System/Types.h"

namespace lov {
    namespace Graphics {
        /// @brief OpenGL texture that can be bound to the OpenGL state
        class Texture {
        public:
            /// @brief Load this Texture with the given file path
            /// @param path The file path of the texture
            Texture(const char* path);

            /// @brief Bind this Texture to the OpenGL state
            /// @param unit Optionally set the texture unit to activate when binding this texture. Default is GL_TEXTURE0
            void bind(lov_uint unit = 0) const;

            /// @brief Unbind this Texture from the OpenGL state
            void unbind() const;

            /// @brief Get the OpenGL ID of this texture
            /// @return The ID of this texture
            lov_uint getID() const;

        private:
            /// @brief The ID of this Texture
            lov_uint m_id;
        };
    }
}
