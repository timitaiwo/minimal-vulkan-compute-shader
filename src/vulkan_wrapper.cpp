#include <vulkan_wrapper.hpp>

////////////////////////////////////////////////////////////////////////
//                          VULKAN INSTANCE                           //
////////////////////////////////////////////////////////////////////////
	vk::ApplicationInfo AppInfo{
		"VulkanCompute",      // Application Name
		1,                    // Application Version
		nullptr,              // Engine Name or nullptr
		0,                    // Engine Version
		VK_API_VERSION_1_1    // Vulkan API version
	};

	const std::vector<const char*> Layers = { "VK_LAYER_KHRONOS_validation" };
	vk::InstanceCreateInfo InstanceCreateInfo(
			vk::InstanceCreateFlags(), // Flags
			&AppInfo,                  // Application Info
			Layers.size(),             // Layers count
			Layers.data()              // Layers
			);
	vk::Instance Instance = vk::createInstance(InstanceCreateInfo);