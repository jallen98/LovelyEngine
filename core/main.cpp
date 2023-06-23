#include "Graphics/Window.h"

int main() {
    lov::Window window(800, 600, "Lovely Engine");

    while(window.isOpen()) {
        window.update();
    }
}
