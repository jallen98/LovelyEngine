#pragma once

#include <exception>
#include <string>

/// @file Exceptions.h
/// @brief Defines various custom exceptions that can be thrown

namespace lov {
    namespace Exceptions {
        /// @brief Base exception class
        class Exception : public std::exception {
        public:
            /// @brief Set the message of this exception with a const char*
            /// @param message The message of this exception
            explicit Exception(const char* message);

            /// @brief Set the message of this exception with a string
            /// @param message The message of this exception
            explicit Exception(const std::string& message);

            /// @brief Get the message of this exception
            /// @return The message of this exception
            virtual const char* what() const noexcept;

        protected:
            /// The message of this exception
            std::string message;
        };

        /// @brief Exception involving shaders
        class ShaderException : public Exception {
        public:
            /// @brief Set the message of this exception with a const char*
            /// @param message The message of this exception
            explicit ShaderException(const char* message);

            /// @brief Set the message of this exception with a string
            /// @param message The message of this exception
            explicit ShaderException(const std::string& message);
        };
    }
}
