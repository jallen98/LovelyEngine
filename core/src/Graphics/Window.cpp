#include "Graphics/Window.h"

lov::Window::Window(unsigned int width, unsigned int height, const std::string& title) {
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create GLFW Window
    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    // Load GLAD
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

lov::Window::~Window() {
    glfwTerminate();
}

bool lov::Window::isOpen() const {
    return !glfwWindowShouldClose(m_window);
}

void lov::Window::update() {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}
