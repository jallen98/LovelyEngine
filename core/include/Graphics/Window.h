#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace lov {
    class Window {
    public:
        Window(unsigned int width, unsigned int height, const std::string& title);
        ~Window();

        bool isOpen() const;
        void update();

    private:
        GLFWwindow* m_window;
    };
}
