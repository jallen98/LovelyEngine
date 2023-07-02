#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Input/Keyboard.h"
#include "System/Vector.h"

/// @file Window.h
/// @brief Defines the #lov::Graphics::Window class used for creating a display window

namespace lov {
    namespace Graphics {
        /// @brief A window that encapsulates the window and OpenGL context
        class Window {
        public:
            /// @brief Create and open a new window
            /// @param width The width of the window
            /// @param height The height of the window
            /// @param title The name dispalyed at the top of the window
            Window(unsigned int width, unsigned int height, const std::string& title);

            /// @brief Terminate OpenGL and the window context
            ~Window();

            /// @brief Set this window's context as the current context
            void makeCurrent();

            /// @brief Should the cursor be hidden, keeping it at the center of the window?
            /// @param hide Whether the cursor should be hidden
            void hideCursor(bool hide);

            /// @brief Is this window considered open?
            /// @return Whether the window is open
            bool isOpen() const;

            /// @brief Flag this window to close
            void close();

            /// @brief Set the clear color of the window
            /// @param red The red component
            /// @param green The green component
            /// @param blue The blue component
            /// @param alpha The optional alpha component
            void setClearColor(float red, float green, float blue, float alpha = 1.0f);

            /// @brief Clear this windows buffer
            void clear();

            /// @brief Swap buffers and and poll events for this window
            void update();

            /// @brief Gets the difference in time between this call and the previous call of this function
            /// @return The time difference in seconds
            float getDeltaTime();

            /// @brief Get the state of a key for this window
            /// @param key The #lov::Input::KeyCode for which to check the state
            /// @return One of KEY_PRESSED or KEY_RELEASED, see #lov::Input::KeyState
            Input::KeyState getKeyState(const Input::KeyCode& key);

            /// @brief Get the position of the mouse cursor in screen space for this window
            /// @return The mouse cursor's position
            Vector2f getCursorPosition() const;

            /// @brief Get the difference between the current cursor position and the position of the cursor during the last call of this function
            /// @return The difference between the current cursor position and the previous
            Vector2f getCursorOffset();

        private:
            ///Internal pointer to GLFW window
            GLFWwindow* m_window;

            // Mouse cursor position
            Vector2f m_mousePos;

            // Previous cursor position
            Vector2f m_previousMousePos;

            // Mouse cursor offset
            Vector2f m_mouseOffset;

            // Has the mouse moved yet?
            bool m_mouseMoved;

            // Time of the most recent frame
            float m_recentFrameTime;
        };
    }
}
