#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

bool handleMessage()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return false; // Exit the loop
        }
    }
	return true; // Continue the loop
}

int main(int argc, char* argv[])
{
    // Initialize SDL3 Video
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create SDL3 Window (Title, Width, Height, Flags)
    SDL_Window* window = SDL_CreateWindow("Totum", 800, 600, SDL_WINDOW_VULKAN);
    if (!window) {
        std::cerr << "Window Creation Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    std::cout << "Hello, World! SDL3 window created successfully." << std::endl;

    while (handleMessage())
    {

    }

    // Clean up
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}