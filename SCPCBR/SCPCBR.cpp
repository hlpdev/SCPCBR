#include <iostream>
#include <Windows.h>

#include "GameAssembly/GameAssembly.h"
#include "Launcher/Launcher.h"
#include "Localization/Localization.h"
#include "SteamWrapper/SteamWrapper.h"

#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <GLAD/glad.h>

#include <string>

int main(int argc, char* argv[])
{
    // Hide console window
    ShowWindowAsync(GetConsoleWindow(), SW_HIDE);

    SteamWrapper* steam = new SteamWrapper();
    
    // Initialize GLFW
    if (!glfwInit()) {
        exit(EXIT_FAILURE);  // NOLINT(concurrency-mt-unsafe)
    }

    // Set OpenGL & GLFW info
    const char* glsl_version = "#version 130";
    //glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create GLFW window
    GLFWwindow* window = glfwCreateWindow(640, 410, GameWindowTitle, 0, 0);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Set window context
    glfwMakeContextCurrent(window);

    // Disable vSync
    glfwSwapInterval(0);

    // Set window icon
    Window::SetWindowIcon(window, GameWindowIcon);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Setup ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.IniFilename = "uicfg.ini";

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    Localization::Init();
    Launcher::Init();
    
    while (!glfwWindowShouldClose(window)) {
        steam->RunCallbacks();
        
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        Launcher::Render(window);

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        glfwSwapBuffers(window);
    }

    Launcher::Free();
    Localization::Free();

    glfwTerminate();

    delete steam;
    
    exit(EXIT_SUCCESS);  // NOLINT(concurrency-mt-unsafe)
}
