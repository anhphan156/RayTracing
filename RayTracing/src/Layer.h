#pragma once
#ifndef LAYER_H
#define LAYER_H

#include "Common.h"

class Layer {
public:
	Layer(){}
	virtual ~Layer() = default;

	virtual void OnUIRender() = 0;
};

#endif
