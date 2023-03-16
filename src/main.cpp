#include <array>
#include <iostream>
#include <vector>

#include "../include/generate.h"
#include "../include/gjk.h"
#include "../include/plot.h"
#include "../include/sat.h"
#include "../include/utils.h"

int main() {
	std::vector<double> test1 = {3.6359316617978648, 1.6616158809531851, 3.6568293348335579, 1.7797822351395325, 3.8931620432062521, 1.7379868890681467, 3.9721199128689642, 1.7176679522209553, 3.9484756819793754, 1.6000203838413249,
	    3.7131805452201148, 1.6473088456205025, 3.6359316617978648, 1.6616158809531851};

	std::vector<double> test2 = {1.9649999955009012, 2.9199999977504505, 2.0849999955009011, 2.9200000022495489, 2.0850000044990984, 2.6800000022495492, 1.9650000044990987, 2.6799999977504507, 1.9649999955009012, 2.9199999977504505};

	std::cout << std::boolalpha << sat_faster(reinterpret_cast<const vec2* const>(test1.data()), test1.size() / 2, reinterpret_cast<const vec2* const>(test2.data()), test2.size() / 2) << std::endl;
	display(plot(reinterpret_cast<const vec2* const>(test1.data()), test1.size() / 2, reinterpret_cast<const vec2* const>(test2.data()), test2.size() / 2));

	std::vector<std::vector<vec2>> vertices = {generate_random_convex_polygon(5), generate_random_convex_polygon(5)};
	std::vector<std::array<vec2, 2>> lines = {generate_random_line()};

	for (unsigned int i = 0; i < vertices.size(); ++i) {
		for (unsigned int j = i + 1; j < vertices.size(); ++j) {
			std::cout << "SAT: The polygons intersect " << std::boolalpha << sat_faster(vertices[i].data(), vertices[i].size(), vertices[j].data(), vertices[j].size()) << std::endl;
		}
	}

	for (unsigned int i = 0; i < vertices.size(); ++i) {
		for (unsigned int j = i + 1; j < vertices.size(); ++j) {
			std::cout << "GJK: The polygons intersect " << std::boolalpha << gjk(vertices[i].data(), vertices[i].size(), vertices[j].data(), vertices[j].size()) << std::endl;
		}
	}

	for (unsigned int i = 0; i < vertices.size(); ++i) {
		for (unsigned int j = 0; j < lines.size(); ++j) {
			std::cout << "SAT_LINE: The polygon an line intersect " << std::boolalpha << sat_faster(vertices[i].data(), vertices[i].size(), lines[j].data(), lines[j].size()) << std::endl;
		}
	}

	display(plot(vertices), plot(lines));

	std::vector<std::vector<vec2>> vertices_concave = {generate_random_polygon(5), generate_random_polygon(5)};
	std::vector<std::vector<std::array<vec2, 3>>> vertices_convex(vertices_concave.size());

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