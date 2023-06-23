#pragma once

#include "Util/Types.h"

/// @file Shader.h
/// @brief Contains #lov::Graphics::Shader class to create OpenGL shaders

namespace lov {
    namespace Graphics {
        /// @brief An OpenGL shader that can be loaded with strings or files
        class Shader {
        public:
            /// @brief Deallocate resources from this Shader
            ~Shader();

            /// @brief Bind this Shader as the active shader
            void bind() const;

            /// @brief Unbind this Shader
            void unbind() const;

            /// @brief Load a shader from text
            /// @param vertexShaderSource The source code of the vertex shader
            /// @param fragmentShaderSource The source code of the fragment shader
            void compileFromText(const char* vertexShaderSource, const char* fragmentShaderSource);

            /// @brief Load a shader from files
            /// @param vertexShaderPath Path to the vertex shader source
            /// @param fragmentShaderPath Path to the fragment shader source
            void compileFromFiles(const char* vertexShaderPath, const char* fragmentShaderPath);

        private:
            /// @brief ID for this shader program
            lov_uint m_id;
        };
    }
}
