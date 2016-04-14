#ifndef VULKAN_EXAMPLE_HPP
#define VULKAN_EXAMPLE_HPP

#include <cassert>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <vulkan/vulkan.h>
#if defined(_WIN32)
#include <Windows.h>
#elif defined(__linux__)
#include <xcb/xcb.h>
#endif

#include "VulkanTools.hpp"
#include "VulkanSwapchain.hpp"

class VulkanExample {
 private:
  void initInstance();
  void initDevices();

  VkInstance instance;
  VkPhysicalDevice physicalDevice;
  VkDevice device;
  VulkanSwapchain swapchain;
#if defined(_WIN32)
  HINSTANCE windowInstance;
  HWND window;
#elif defined(__linux__)
  xcb_connection_t *connection;
  xcb_window_t window;
  xcb_screen_t *screen;
  xcb_atom_t wmProtocols;
  xcb_atom_t wmDeleteWin;
#endif
 public:
  VulkanExample();
  virtual ~VulkanExample();

#if defined(_WIN32)
  void initWindow(HINSTANCE hInstance);
#elif defined(__linux__)
  void initWindow();
#endif
  void initSwapchain();
  void renderLoop();
};

#endif  // VULKAN_EXAMPLE_HPP
