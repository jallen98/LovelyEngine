#include "Graphics/Window.h"

lov::Graphics::Window::Window(unsigned int width, unsigned int height, const std::string& title) {
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

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
}

lov::Graphics::Window::~Window() {
    glfwTerminate();
}

bool lov::Graphics::Window::isOpen() const {
    return !glfwWindowShouldClose(m_window);
}

void lov::Graphics::Window::close() {
    glfwSetWindowShouldClose(m_window, true);
}

void lov::Graphics::Window::setClearColor(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
}

void lov::Graphics::Window::clear() {
    // Clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void lov::Graphics::Window::update() {
    // Swap buffers
    glfwSwapBuffers(m_window);

    // Poll events
    glfwPollEvents();
}

lov::Input::KeyState lov::Graphics::Window::getKeyState(const Input::KeyCode& key) {
    int state = glfwGetKey(m_window, key);

    if (state == GLFW_PRESS) {
        return Input::KEY_PRESS;
    }

    return Input::KEY_RELEASE;
}
