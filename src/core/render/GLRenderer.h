#pragma once

class GLFWwindow;

class GLRenderer {
    GLFWwindow* m_Window;

public:
    GLRenderer();
    ~GLRenderer();

    int Init(int width, int height, const char* title);
    void Render() const;
    bool IsWindowClosed() const;
};