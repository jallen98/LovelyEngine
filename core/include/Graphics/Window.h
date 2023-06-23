#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Input/Keyboard.h"

/**
 * @file Window.h
 * @brief Defines the #lovely::Graphics::Window class used for creating a display window
*/

namespace lovely {
    namespace Graphics {
        /**
         * @brief A window that encapsulates the window and OpenGL context
        */
        class Window {
        public:
            /**
             * @brief Create and open a new window
             * @param width The width of the window
             * @param height The height of the window
             * @param title The name dispalyed at the top of the window
            */
            Window(unsigned int width, unsigned int height, const std::string& title);

            /**
             * @brief Terminate OpenGL and the window context
            */
            ~Window();

            /**
             * @brief Is this window considered open?
             * @return Whether the window is open
            */
            bool isOpen() const;

            /**
             * @brief Flag this window to close
            */
            void close();

            /**
             * @brief Set the clear color of the window
             * @param red The red component
             * @param green The green component
             * @param blue The blue component
             * @param alpha The optional alpha component
            */
            void setClearColor(float red, float green, float blue, float alpha = 1.0f);

            /**
             * @brief Clear this windows buffer
            */
            void clear();

            /**
             * @brief Swap buffers and and poll events for this window
            */
            void update();

            /**
             * @brief Get the state of a key for this window
             * @param key The #lovely::Input::KeyCode for which to check the state
             * @return One of KEY_PRESSED or KEY_RELEASED, see #lovely::Input::KeyState
            */
            Input::KeyState getKeyState(const Input::KeyCode& key);

        private:
            GLFWwindow* m_window; ///< Internal pointer to GLFW window
        };
    }
}
