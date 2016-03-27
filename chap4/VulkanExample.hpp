#ifndef VULKAN_EXAMPLE_HPP
#define VULKAN_EXAMPLE_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <vulkan/vulkan.h>
#if defined(_WIN32)
#include <Windows.h>
#elif defined (_LINUX)
#include <xcb/xcb.h>
#endif

class VulkanExample {
private:
    void exitOnError(const char * msg);
    void initInstance();
    void initDevices();

    const char * applicationName = "Vulkan Example";
    const char * engineName = "Vulkan Engine";

    const int windowWidth = 1280;
    const int windowHeight = 720;

    VkInstance instance;
    VkPhysicalDevice physicalDevice;
    VkDevice device;
#if defined (_WIN32)
    HINSTANCE windowInstance;
    HWND window;
#elif defined(__linux__)
    xcb_connection_t * connection;
    xcb_window_t window;
    xcb_screen_t * screen;
    xcb_atom_t wmProtocols;
    xcb_atom_t wmDeleteWin;
#endif
public:
    VulkanExample();
    virtual ~VulkanExample();

#if defined(_WIN32)
    void initWindow(HINSTANCE hInstance);
#elif defined (__linux)
    void initWindow();
#endif
    void renderLoop();
};

#endif // VULKAN_EXAMPLE_HPP
