#include "Graphics/Window.h"

int main() {
    lovely::Graphics::Window window(800, 600, "Lovely Engine");

    window.setClearColor(0.2f, 0.3f, 0.3f);

    while(window.isOpen()) {
        if (window.getKeyState(lovely::Input::KEY_ESCAPE)) {
            window.close();
        }

        window.clear();
        window.update();
    }
}
