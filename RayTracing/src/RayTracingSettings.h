#pragma once
#include "Layer.h"

class RayTracingSettings : public Layer {
public:
	RayTracingSettings() {}

	virtual void OnUIRender() override {
		ImGui::Begin("Settings");

		ImGui::Text("Testing");

		ImGui::End();
	}
};