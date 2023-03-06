#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../include/generate.h"
#include "../include/gjk.h"
#include "../include/plot.h"
#include "../include/sat.h"
#include "../include/utils.h"

std::vector<double> test = {-1.5, 0.0, -1.0, -1.0, 0.0, 1.0, 0.4, 0.5, 0.5, 0.6, 0.9, 2.0};

std::vector<sf::VertexArray> plot(vec2 const *const line_strip, unsigned int const count) {
	std::vector<sf::VertexArray> shapes(1, sf::VertexArray(sf::LineStrip, count));

	for (unsigned int i = 0; i < count; ++i) {
		shapes[0][i].position.x = line_strip[i].x;
		shapes[0][i].position.y = line_strip[i].y;
		shapes[0][i].color = sf::Color::Black;
	}

	return shapes;
}

bool sat_line_strip(vec2 const *const poly, unsigned int const count1, vec2 const *const line_strip, unsigned int count2) {
	bool *testing = new bool[count2 - 1];
	std::fill(testing, testing + count2 - 1U, true);

	for (unsigned int i = 0U; i < count1; ++i) {
		unsigned int j = (i + 1U) % count1;
		std::pair<double, double> axis = {-(poly[j].y - poly[i].y), poly[j].x - poly[i].x};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly = std::numeric_limits<double>::infinity(), max_poly = -std::numeric_limits<double>::infinity();
		for (unsigned int k = 0U; k < count1; ++k) {
			double dot = (poly[k].x * axis.first + poly[k].y * axis.second);
			min_poly = std::min(min_poly, dot);
			max_poly = std::max(max_poly, dot);
		}

		for (unsigned int k = 0U; k < count2 - 1U; ++k) {
			if (!testing[k]) continue;

			double dot1 = (line_strip[k].x * axis.first + line_strip[k].y * axis.second);
			double dot2 = (line_strip[k + 1U].x * axis.first + line_strip[k + 1U].y * axis.second);

			double min_line = std::min(dot1, dot2);
			double max_line = std::max(dot1, dot2);

			if (!(max_line >= min_poly && max_poly >= min_line)) testing[k] = false;
		}

		if (std::none_of(testing, testing + count2 - 1U, [](bool const pred) { return pred; })) return false;
	}

	for (unsigned int i = 0U; i < count2 - 1U; ++i) {
		if (!testing[i]) continue;
		for (unsigned int j = 1; j <= 2; ++j) {
			std::pair<double, double> axis = {-(line_strip[i + (j % 2)].y - line_strip[i + ((j + 1) % 2)].y), line_strip[i + (j % 2)].x - line_strip[i + ((j + 1) % 2)].x};
			double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
			axis = {axis.first / norm, axis.second / norm};

			double min_poly = std::numeric_limits<double>::infinity(), max_poly = -std::numeric_limits<double>::infinity();
			for (unsigned int k = 0U; k < count1; ++k) {
				double dot = (poly[k].x * axis.first + poly[k].y * axis.second);
				min_poly = std::min(min_poly, dot);
				max_poly = std::max(max_poly, dot);
			}

			double dot1 = (line_strip[i].x * axis.first + line_strip[i].y * axis.second);
			double dot2 = (line_strip[i + 1U].x * axis.first + line_strip[i + 1U].y * axis.second);

			double min_line = std::min(dot1, dot2);
			double max_line = std::max(dot1, dot2);

			if (!(max_line >= min_poly && max_poly >= min_line)) {
				testing[i] = false;
				break;
			}
		}
		if (std::none_of(testing, testing + count2 - 1U, [](bool const pred) { return pred; })) return false;
	}

	return true;
}

bool sat_line_strip_faster(vec2 const *const poly, unsigned int const count1, vec2 const *const line_strip, unsigned int count2) {
	for (unsigned int i = 0U; i < count1 - 1U; ++i) {
		if (sat_faster(poly, count1, line_strip + i, 2U)) return true;
	}

	return false;
}

int main() {
	std::vector<std::vector<vec2>> vertices = {generate_random_convex_polygon(5), generate_random_convex_polygon(5)};

	for (unsigned int i = 0; i < vertices.size(); ++i) {
		std::cout << "SAT_LINE_STRIP: The polygon an line intersect " << std::boolalpha << sat_line_strip_faster(vertices[i].data(), vertices[i].size(), (vec2 const *)test.data(), test.size() / 2U) << std::endl;
	}

	display(plot(vertices), plot((vec2 const *)test.data(), test.size() / 2));
}