#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


const GLint WIDTH = 800, HEIGHT = 700;

int main() {

    if(!glfwInit())
    {
        std::cout << "OMG GLFW NOT WORKING !!1!!!" << std::endl;
        glfwTerminate();
    }
    //set that shit to 3.3 -> mayor is first 3 minor is second 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE); // set core
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE); //forward compatability

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH,HEIGHT,"Biatch",NULL,NULL);
    if(!mainWindow)
    {
        std::cout << "OMG Window NOT WORKING !!1!!!" << std::endl;
        glfwTerminate();
    }

    //get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow,&bufferWidth,&bufferHeight);
    glfwMakeContextCurrent(mainWindow);

    //allow modern extension features
    glewExperimental = GL_TRUE;

    if(!glewInit()){
        std::cout << "OMG Window NOT WORKING !!1!!!" << std::endl;
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
    }


    return 0;
}
