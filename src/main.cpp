#include "core/render/GLRenderer.h"

int main() {
    auto* renderer = new GLRenderer();
    if (renderer->Init() > -1) {
        renderer->StartRendering();
    }
    delete renderer;
    return 0;
}