#include "GLRenderer.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

GLRenderer::GLRenderer() {}

GLRenderer::~GLRenderer()
{
    glfwTerminate();
}

int GLRenderer::Init(int width = 800, int height = 600, const char* title = "OpenGL")
{
    if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (m_Window == NULL)
    {
        cout << "Failed to open GLFW window" << endl;
        return -1;
    }
    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

    return 0;
}

void GLRenderer::Render() const
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool GLRenderer::IsWindowClosed() const
{
    return glfwWindowShouldClose(m_Window);
}