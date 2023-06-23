#include "Graphics/Window.h"

int main() {
    lov::Window window(800, 600, "Lovely Engine");

    window.setClearColor(0.2f, 0.3f, 0.3f);

    while(window.isOpen()) {
        window.update();
    }
}
