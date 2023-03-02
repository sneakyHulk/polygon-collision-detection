#include <iostream>
#include <vector>

#include "../include/gjk.h"
#include "../include/plot.h"
#include "../include/sat.h"
#include "../include/generate.h"

int main() {
	std::vector<std::vector<std::pair<double, double>>> vertices = {generate_random_convex_polygon(5), generate_random_convex_polygon(5)};

	for (unsigned int i = 0; i < vertices.size(); ++i) {
		for (unsigned int j = i + 1; j < vertices.size(); ++j) {
			std::cout << "SAT: The polygons intersect " << std::boolalpha << sat(vertices[i], vertices[j]) << std::endl;
		}
	}

	for (unsigned int i = 0; i < vertices.size(); ++i) {
		for (unsigned int j = i + 1; j < vertices.size(); ++j) {
			std::cout << "GJK: The polygons intersect " << std::boolalpha << gjk((const vec2 *)vertices[i].data(), vertices[i].size(), (const vec2 *)vertices[j].data(), vertices[j].size()) << std::endl;
		}
	}

	display(plot(vertices));
}