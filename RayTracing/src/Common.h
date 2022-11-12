#pragma once
#ifndef COMMON_H
#define COMMON_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw.h"
#include "../vendor/imgui/imgui_impl_opengl3.h"
//#include "../vendor/imgui/imgui_impl_opengl3_loader.h"

#include <memory>
#include <vector>
#include <string>

using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::string;

#endif
