#include "Graphics/Window.h"

lov::Window::Window(unsigned int width, unsigned int height, const std::string& title) {
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create GLFW Window
    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    glfwMakeContextCurrent(m_window);

    // Load GLAD
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // Set viewport
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int frameBufferWidth, int frameBufferHeight) {
        glViewport(0, 0, frameBufferWidth, frameBufferHeight);
    });
}

lov::Window::~Window() {
    glfwTerminate();
}

bool lov::Window::isOpen() const {
    return !glfwWindowShouldClose(m_window);
}

void lov::Window::update() {
    // Clear screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Poll events
    glfwPollEvents();

    // Swap buffers
    glfwSwapBuffers(m_window);
}

void lov::Window::setClearColor(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
}
