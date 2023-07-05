#pragma once

#include <string>

#include "Graphics/Transform.h"
#include "System/Types.h"

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
            /// @throws #lov::Exceptions::ShaderException if compile or linking fails
            void compileFromText(const char* vertexShaderSource, const char* fragmentShaderSource);

            /// @brief Load a shader from files
            /// @param vertexShaderPath Path to the vertex shader source
            /// @param fragmentShaderPath Path to the fragment shader source
            /// @throws #lov::Exceptions::ShaderException if compile or linking fails
            void compileFromFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

            /// @brief Set a uniform boolean with the given name and value
            /// @param name Name of the uniform
            /// @param value Value to set
            void setUniformBool(const std::string& name, bool value);

            /// @brief Set a uniform integer with the given name and value
            /// @param name Name of the uniform
            /// @param value Value to set
            void setUniformInt(const std::string& name, int value);

            /// @brief Set a uniform float with the given name and value
            /// @param name Name of the uniform
            /// @param value Value to set
            void setUniformFloat(const std::string& name, float value);

            /// @brief Set a uniform Vector3f with the given name and value
            /// @param name Name of the uniform
            /// @param value Value to set
            void setUniformVector3(const std::string& name, const Vector3f& value);

            /// @brief Set a uniform transform with the given name and value
            /// @param name Name of the uniform
            /// @param value Value to set
            void setUniformTransform(const std::string& name, const Transform& value);

        private:
            /// @brief ID for this shader program
            lov_uint m_id;
        };
    }
}
