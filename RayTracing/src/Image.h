#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#include "Common.h"

class Image {
public:
	Image();
	Image(int w, int h, unsigned int* image_data);
	virtual ~Image();

	GLuint GetImage() { return m_image; }
	
private:
	GLuint m_image = 0;
	unsigned int* m_image_data;
	int m_w, m_h;
};

#endif // !IMAGE_H

