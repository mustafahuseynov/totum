#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#include "vulkan_base/vulkan_base.h"

bool handleMessage()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Totum", 800, 600, SDL_WINDOW_VULKAN);
    if (!window) {
        std::cerr << "Window Creation Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    std::cout << "SDL3 window created successfully." << std::endl;

    VulkanContext* context = initVulkan();
    if (!context) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    std::cout << "Vulkan instance created successfully!" << std::endl;

    while (handleMessage()) {
        // Main loop logic here
    }

    // Clean up Vulkan & SDL in reverse order of creation
    cleanupVulkan(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}