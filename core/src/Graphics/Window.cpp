#include "Graphics/Window.h"

lovely::Graphics::Window::Window(unsigned int width, unsigned int height, const std::string& title) {
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

lovely::Graphics::Window::~Window() {
    glfwTerminate();
}

bool lovely::Graphics::Window::isOpen() const {
    return !glfwWindowShouldClose(m_window);
}

void lovely::Graphics::Window::close() {
    glfwSetWindowShouldClose(m_window, true);
}

void lovely::Graphics::Window::setClearColor(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
}

void lovely::Graphics::Window::clear() {
    // Clear buffers
    glClear(GL_COLOR_BUFFER_BIT);
}

void lovely::Graphics::Window::update() {
    // Poll events
    glfwPollEvents();

    // Swap buffers
    glfwSwapBuffers(m_window);
}

lovely::Input::KeyState lovely::Graphics::Window::getKeyState(const Input::KeyCode& key) {
    int state = glfwGetKey(m_window, key);

    if (state == GLFW_PRESS) {
        return Input::KEY_PRESS;
    }

    return Input::KEY_RELEASE;
}
