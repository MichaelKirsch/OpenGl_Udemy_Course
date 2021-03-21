#include <iostream>
#include "shitty_support_header/shitty_support.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>



const GLint WIDTH = 800, HEIGHT = 700;

using namespace ShittySupportLib;

GLuint VAO,VBO,shader;

const int Framerate = 60;


void createTrangle()
{
    GLfloat vertices[]={
            -1.f,-1.f,0.f,
            1.f,-1.f,0.f,
            0.f,1.f,0.f
    };

    glad_glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);


};



int main() {
    Debugger::instance().log("GLFW init",glfwInit());
    //set that shit to 3.3 -> mayor is first 3 minor is second 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE); // set core
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE); //forward compatability

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH,HEIGHT,"Biatch",NULL,NULL);
    if(!mainWindow)
        glfwTerminate();

    Debugger::instance().log("GLFW window init",mainWindow); //check if main window was created successfully

    //get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow,&bufferWidth,&bufferHeight);
    glfwMakeContextCurrent(mainWindow);
    Debugger::instance().log("Window Buffers",std::string(" X:"+std::to_string(bufferWidth) + "| Y:" + std::to_string(bufferHeight)));
    Debugger::instance().log("GLAD glfw loader function",gladLoadGLLoader((GLADloadproc) glfwGetProcAddress));

    glViewport(0,0,bufferWidth,bufferHeight);
    Debugger::instance().log("Init of all Libs",1);
    Debugger::instance().print_log();
    Debugger::instance().clear_log();

    SimpleClock clock1;




    while (!glfwWindowShouldClose(mainWindow))
    {
            glfwPollEvents();
            glClearColor(1.f,0.2,0.5,0.1);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(mainWindow);
            std::this_thread::sleep_for(std::chrono::milliseconds(int(1000/Framerate)));
    }







    return 0;
}
