#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
    if (!glfwInit())
        exit(EXIT_FAILURE);

    GLFWwindow* window = glfwCreateWindow(400, 400, "Example", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetFramebufferSizeCallback(window,
        [](GLFWwindow*, int width, int height) -> void {
        glViewport(0, 0, width, height);
    });

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
            glVertex2f(-0.5f, -0.5f); glColor3f(1, 0, 0);
            glVertex2f(0.0f, 0.5f); glColor3f(0, 1, 0);
            glVertex2f(0.5f, -0.5f); glColor3f(0, 0, 0);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}