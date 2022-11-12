#pragma once
#include "Layer.h"
#include "Common.h"

class RayTracingSettings : public Layer {
public:
	RayTracingSettings() {}

	virtual void OnUIRender() override;

};