#include "RayTracingSettings.h"
#include "Image.h"

void RayTracingSettings::OnUIRender() {
	ImGui::Begin("Settings");

	int w = 512;
	int h = 256;

	unsigned int* image_data = new unsigned int[w * h];

	for (int u = 0; u < w * h; u++) {
		image_data[u] = 0xff0000ff;
	}

	Image image(w, h, image_data);

	ImGui::Image((void*)(intptr_t)image.GetImage(), ImVec2(w, h));

	ImGui::End();
}

