#include "GameAssembly.h"
#include "../Options/Options.h"

#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

void Window::SetWindowIcon(GLFWwindow* window, std::string iconPath) {
    GLFWimage images[1];
    images[0].pixels = stbi_load(iconPath.c_str(), &images[0].width, &images[0].height, 0, 4);
    glfwSetWindowIcon(window, 1, images);
    stbi_image_free(images[0].pixels);
}

void WindowFocusedCallback(GLFWwindow* window, int state) {
    if (state == GLFW_TRUE) {
        glfwRestoreWindow(window);
    } else {
        glfwIconifyWindow(window);
    }
}

void Window::SetWindowDisplayMode(GLFWwindow* window, int displayMode) {
    Options::WriteIntOption("Graphics", "DisplayMode", displayMode);
    switch (displayMode) {  // NOLINT(hicpp-multiway-paths-covered)
        case 0: {
            // windowed
            glfwRestoreWindow(window);
            glfwSetWindowFocusCallback(window, nullptr);
            
            glfwMaximizeWindow(window);
            glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_TRUE);
            glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_TRUE);
            glfwSetWindowAttrib(window, GLFW_FLOATING, GLFW_FALSE);

            glfwSetWindowSizeLimits(window, 1280, 915, 7680, 4320);
            break;
        }
        default: {
            // borderless
            const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

            glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_FALSE);
            glfwSetWindowPos(window, 0, 0);
            glfwSetWindowSize(window, mode->width, mode->height);

            glfwSetWindowFocusCallback(window, WindowFocusedCallback);
            break;
        }
    }
}
