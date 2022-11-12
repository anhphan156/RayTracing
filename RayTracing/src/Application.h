#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Common.h"

class Application {
public:
	Application();
	virtual ~Application();

	void Run();

private:
	GLFWwindow* m_window = nullptr;
	vector<shared_ptr<class Layer>> m_layers;
};

#endif
