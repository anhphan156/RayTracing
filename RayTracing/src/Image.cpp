#include "Image.h"

Image::Image() {
	m_image_data = nullptr;
	m_w = 0;
	m_h = 0;
}

Image::~Image() {
	delete[] m_image_data;
}

Image::Image(int w, int h, unsigned int* image_data) 
	: m_w(w), m_h(h), m_image_data(image_data)
{
	glGenTextures(1, &m_image);
	glBindTexture(GL_TEXTURE_2D, m_image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_image_data);
}
