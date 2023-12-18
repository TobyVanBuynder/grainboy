#pragma once

class GLFWwindow;

class GLRenderer {
    GLFWwindow* m_Window;

public:
    GLRenderer();
    ~GLRenderer();

    int Init();
    void StartRendering();
};