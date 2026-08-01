cmake_minimum_required(VERSION 3.16)

project(totum LANGUAGES CXX)

# Modern C++ standard (recommended for Vulkan & SDL3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

set(SOURCE_FILES src/main.cpp src/vulkan_base/vulkan_device.cpp)

# 1. Force SDL3 to build statically before adding its directory
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
add_subdirectory(libs/SDL)

# 2. Find Vulkan SDK
find_package(Vulkan REQUIRED)

# 3. Executable setup
add_executable(totum ${SOURCE_FILES})

# 4. Link using modern target names (automatically manages includes & paths)
target_link_libraries(totum 
    PRIVATE 
        SDL3::SDL3-static
        Vulkan::Vulkan
)