#include "GameAssembly.h"

#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

void Window::SetWindowIcon(GLFWwindow* window, std::string iconPath) {
    GLFWimage images[1];
    images[0].pixels = stbi_load(iconPath.c_str(), &images[0].width, &images[0].height, 0, 4);
    glfwSetWindowIcon(window, 1, images);
    stbi_image_free(images[0].pixels);
}
