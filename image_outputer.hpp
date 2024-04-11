#pragma once
#include <cstdint>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace water {
	void output_ppm_image(uint32_t width, uint32_t height, auto get_pixel_value) {
		std::cout << "P3" << std::endl;
		std::cout << width << ' ' << height << std::endl;
		std::cout << "255" << std::endl;
		for (uint32_t j = 0; j < height; j++) {
			for (uint32_t i = 0; i < width; i++) {
				auto [r, g, b] = get_pixel_value(i, j);
				int ir = static_cast<int>(255.999 * r);
				int ig = static_cast<int>(255.999 * g);
				int ib = static_cast<int>(255.999 * b);
				std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
			}
		}
	}
}