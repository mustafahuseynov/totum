#include <vulkan/vulkan.h>

struct VulkanContext {
	VkInstance instance; // first vulkan object, i am very scawed
};

VulkanContext* initVulkan();

void cleanupVulkan(VulkanContext* context);