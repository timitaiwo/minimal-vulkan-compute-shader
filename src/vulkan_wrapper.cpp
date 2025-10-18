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


////////////////////////////////////////////////////////////////////////
//                          PHYSICAL DEVICE                           //
////////////////////////////////////////////////////////////////////////
	vk::PhysicalDevice PhysicalDevice = Instance.enumeratePhysicalDevices().front();
	vk::PhysicalDeviceProperties DeviceProps = PhysicalDevice.getProperties();

    
////////////////////////////////////////////////////////////////////////
//                            QUEUE FAMILY                            //
////////////////////////////////////////////////////////////////////////
	std::vector<vk::QueueFamilyProperties> QueueFamilyProps = PhysicalDevice.getQueueFamilyProperties();
	auto PropIt = std::find_if(QueueFamilyProps.begin(), QueueFamilyProps.end(), [](const vk::QueueFamilyProperties& Prop) {
		return Prop.queueFlags & vk::QueueFlagBits::eCompute;
	});
	const uint32_t ComputeQueueFamilyIndex = std::distance(QueueFamilyProps.begin(), PropIt);
    

////////////////////////////////////////////////////////////////////////
//                               DEVICE                               //
////////////////////////////////////////////////////////////////////////
	float queuePriorities = 1.0f;
	vk::DeviceQueueCreateInfo DeviceQueueCreateInfo(
			vk::DeviceQueueCreateFlags(),   // Flags
			ComputeQueueFamilyIndex,        // Queue Family Index
			1,                              // Number of Queues
			&queuePriorities
			);
	vk::DeviceCreateInfo DeviceCreateInfo(
			vk::DeviceCreateFlags(),   // Flags
			1,
			&DeviceQueueCreateInfo      // Device Queue Create Info struct
			);
	vk::Device Device = PhysicalDevice.createDevice(DeviceCreateInfo);