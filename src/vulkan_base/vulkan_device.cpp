#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.h>

struct VulkanContext {
    VkInstance instance = VK_NULL_HANDLE;
};

bool initVulkanInstance(VulkanContext* context)
{
    VkApplicationInfo applicationInfo = { VK_STRUCTURE_TYPE_APPLICATION_INFO };
    applicationInfo.pNext = nullptr;
    applicationInfo.pApplicationName = "Totum";
    applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
    applicationInfo.apiVersion = VK_API_VERSION_1_2;

    // 1. Fetch SDL3 Vulkan instance extensions
    Uint32 extensionCount = 0;
    const char* const* extensionNames = SDL_Vulkan_GetInstanceExtensions(&extensionCount);
    if (!extensionNames) {
        std::cerr << "Failed to get SDL Vulkan extensions: " << SDL_GetError() << std::endl;
        return false;
    }

    VkInstanceCreateInfo createInfo = { VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };
    createInfo.pApplicationInfo = &applicationInfo;
    createInfo.enabledExtensionCount = extensionCount;
    createInfo.ppEnabledExtensionNames = extensionNames;

    // 2. Create the Vulkan Instance
    if (vkCreateInstance(&createInfo, nullptr, &context->instance) != VK_SUCCESS) {
        std::cerr << "Error creating Vulkan instance." << std::endl;
        return false;
    }

    return true;
}

VulkanContext* initVulkan()
{
    VulkanContext* context = new VulkanContext();

    if (!initVulkanInstance(context)) {
        delete context;
        return nullptr;
    }

    return context;
}

void cleanupVulkan(VulkanContext* context)
{
    if (!context) return;

    if (context->instance != VK_NULL_HANDLE) {
        vkDestroyInstance(context->instance, nullptr);
    }
    delete context;
}