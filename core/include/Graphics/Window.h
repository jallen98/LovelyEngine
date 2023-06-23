#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace lov {
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
         * @brief Terminate GLFW
        */
        ~Window();

        /**
         * @brief Is this window considered open?
         * @return Whether the window is open
        */
        bool isOpen() const;

        /**
         * @brief Swap buffers and and poll events for this window
        */
        void update();

        /**
         * @brief Set the clear color of the window
         * @param red The red component
         * @param green The green component
         * @param blue The blue component
         * @param alpha The optional alpha component
        */
        void setClearColor(float red, float green, float blue, float alpha = 1.0f);

    private:
        /**
         * Internal pointer to a GLFW window
        */
        GLFWwindow* m_window;
    };
}
