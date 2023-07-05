#include "Graphics/Window.h"

#include "System/Exceptions.h"

lov::Graphics::Window::Window(unsigned int width, unsigned int height, const std::string& title):
    m_mousePos(0.0f, 0.0f),
    m_previousMousePos(0.0f, 0.0f),
    m_mouseOffset(0.0f, 0.0f),
    m_mouseMoved(false),
    m_recentFrameTime(0.0f)
{
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create GLFW Window
    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (m_window == NULL) {
        glfwTerminate();
        throw Exceptions::WindowException("Failed to create lov::Graphics::Window");
    }

    this->makeCurrent();

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw Exceptions::WindowException("Failed to load OpenGL function pointers");
    }

    // Set viewport
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int frameBufferWidth, int frameBufferHeight) {
        glViewport(0, 0, frameBufferWidth, frameBufferHeight);
    });

    // Set callback to get mouse position
    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y) {
        Window* handler = static_cast<Window*>(glfwGetWindowUserPointer(window));
        float xpos = static_cast<float>(x);
        float ypos = static_cast<float>(y);

        if (handler) {
            if (!handler->m_mouseMoved) {
                handler->m_previousMousePos = { xpos, ypos };
            }

            handler->m_mouseMoved = true;
            handler->m_mousePos = { xpos, ypos };
        }
    });

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
}

lov::Graphics::Window::~Window() {
    glfwTerminate();
}

void lov::Graphics::Window::makeCurrent() {
    glfwMakeContextCurrent(m_window);
    glfwSetWindowUserPointer(m_window, this);
}

void lov::Graphics::Window::hideCursor(bool hidden) {
    if (hidden) {
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }
    else {
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
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

float lov::Graphics::Window::getDeltaTime() {
    // Update delta time
    float currentFrameTime = glfwGetTime();
    float dt = currentFrameTime - m_recentFrameTime;
    m_recentFrameTime = currentFrameTime;
    return dt;
}

lov::Input::KeyState lov::Graphics::Window::getKeyState(const Input::KeyCode& key) {
    int state = glfwGetKey(m_window, key);

    if (state == GLFW_PRESS) {
        return Input::KEY_PRESS;
    }

    return Input::KEY_RELEASE;
}

lov::Vector2f lov::Graphics::Window::getCursorPosition() const {
    return m_mousePos;
}

lov::Vector2f lov::Graphics::Window::getCursorOffset() {
    Vector2f mouseOffset(0.0f, 0.0f);

    if (m_mouseMoved) {
        mouseOffset.x = m_mousePos.x - m_previousMousePos.x;
        mouseOffset.y = m_previousMousePos.y - m_mousePos.y;
        m_previousMousePos = m_mousePos;
    }

    return mouseOffset;
}
