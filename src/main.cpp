#include <iostream>
#include <stdlib.h>
#define GLFW_DLL
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window,int key,int scancode, int action,int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window,GL_TRUE);
}

int main() {
    int width, height;
//    float colorR,colorB,colorG;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(1200,800,"LearnOpenGl", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwGetFramebufferSize(window,&width,&height);
    glViewport(0,0,width,height);
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glfwSetKeyCallback(window, key_callback);
        glfwPollEvents();
//        glClearColor((double)(rand())/RAND_MAX,(double)(rand())/RAND_MAX,(double)(rand())/RAND_MAX,(double)(rand())/RAND_MAX);
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
