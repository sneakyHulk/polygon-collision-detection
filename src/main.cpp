#include <array>
#include <iostream>
#include <vector>

#include "../include/generate.h"
#include "../include/gjk.h"
#include "../include/plot.h"
#include "../include/sat.h"
#include "../include/utils.h"

int main() {
	std::vector<std::vector<std::pair<double, double>>> vertices = {generate_random_convex_polygon(5), generate_random_convex_polygon(5)};
	std::vector<std::array<std::pair<double, double>, 2>> lines = {generate_random_line()};

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

	for (unsigned int i = 0; i < vertices.size(); ++i) {
		for (unsigned int j = 0; j < lines.size(); ++j) {
			std::cout << "SAT_LINE: The polygon an line intersect " << std::boolalpha << sat_faster(vertices[i].data(), vertices[i].size(), lines[j].data(), lines[j].size()) << std::endl;
		}
	}

	display(plot(vertices), plot(lines));

	std::vector<std::vector<std::pair<double, double>>> vertices_concave = {generate_random_polygon(5), generate_random_polygon(5)};
	std::vector<std::vector<std::array<std::pair<double, double>, 3>>> vertices_convex(vertices_concave.size());

	for (unsigned int i = 0; i < vertices_concave.size(); ++i) {
		vertices_convex[i] = generate_triangles(vertices_concave[i]);
	}

	for (unsigned int i = 0; i < vertices_convex.size(); ++i) {
		for (unsigned int j = i + 1; j < vertices_convex.size(); ++j) {
			std::cout << "SAT CONCAVE: The polygons intersect " << std::boolalpha << check_collision_sat_concave(vertices_convex[i], vertices_convex[j]) << std::endl;
		}
	}

	for (unsigned int i = 0; i < vertices_convex.size(); ++i) {
		for (unsigned int j = i + 1; j < vertices_convex.size(); ++j) {
			std::cout << "GJK CONCAVE: The polygons intersect " << std::boolalpha << check_collision_gjk_concave(vertices_convex[i], vertices_convex[j]) << std::endl;
		}
	}

	display(plot(vertices_convex));

	return 0;
}