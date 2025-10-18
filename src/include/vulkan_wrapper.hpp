
#ifndef __VK_WRAPPER__
#define __VK_WRAPPER__

#include <vulkan/vulkan.hpp>

extern vk::Instance Instance;

extern vk::PhysicalDevice PhysicalDevice;
extern vk::PhysicalDeviceProperties DeviceProps;

extern std::vector<vk::QueueFamilyProperties> QueueFamilyProps;
extern const uint32_t ComputeQueueFamilyIndex;

extern vk::Device Device;

#endif