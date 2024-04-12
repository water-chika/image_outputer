#pragma once
#include <cstdint>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <execution>

namespace water {
	void output_ppm_image(uint32_t width, uint32_t height, auto get_pixel_value) {
		std::cout << "P3" << std::endl;
		std::cout << width << ' ' << height << std::endl;
		std::cout << "255" << std::endl;
		std::vector<std::tuple<double,double,double>> image_data(width* height);
		std::vector<std::pair<uint32_t, uint32_t>> coords(width * height);

		for (uint32_t j = 0; j < height; j++) {
			for (uint32_t i = 0; i < width; i++) {
				coords[j * width + i] = { i, j };
			}
		}
		std::clog << "begin get pixel_value" << std::endl;
		std::for_each(
			std::execution::seq,
			coords.begin(), coords.end(),
			[&get_pixel_value, &image_data, width](auto coord) {
				auto [x, y] = coord;
				image_data[y * width + x] = get_pixel_value(x, y);
			});
		std::clog << "output image" << std::endl;
		std::ranges::for_each(
			image_data,
			[](auto color) {
				auto [r, g, b] = color;
				int ir = static_cast<int>(255.999 * r);
				int ig = static_cast<int>(255.999 * g);
				int ib = static_cast<int>(255.999 * b);
				std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
			}
		);
	}
}