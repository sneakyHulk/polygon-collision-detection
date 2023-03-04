#pragma once

#include <array>
#include <vector>

#include "../include/earcut.h"
#include "../include/gjk.h"
#include "../include/sat.h"

std::vector<std::array<std::pair<double, double>, 3>> generate_triangles(std::vector<std::pair<double, double>> const &polygon) {
	std::vector<std::array<std::pair<double, double>, 3>> res;

	std::vector<std::vector<std::pair<double, double>>> poly = {polygon};
	std::vector<uint32_t> indices = mapbox::earcut<uint32_t>(poly);

	for (unsigned int j = 0; j < indices.size(); j += 3) {
		res.push_back({std::make_pair(polygon[indices[j]].first, polygon[indices[j]].second), std::make_pair(polygon[indices[j + 1]].first, polygon[indices[j + 1]].second),
		    std::make_pair(polygon[indices[j + 2]].first, polygon[indices[j + 2]].second)});
	}

	return res;
}

bool check_collision_sat_concave(std::vector<std::array<std::pair<double, double>, 3>> const &triangles1, std::vector<std::array<std::pair<double, double>, 3>> const &triangles2) {
	for (unsigned int k = 0; k < triangles1.size(); ++k) {
		for (unsigned int l = 0; l < triangles2.size(); ++l) {
			if (sat_faster((std::pair<double, double> const *)triangles1[k].data(), triangles1[k].size(), (std::pair<double, double> const *)triangles2[l].data(), triangles2[l].size())) return true;
		}
	}

	return false;
}

bool check_collision_gjk_concave(std::vector<std::array<std::pair<double, double>, 3>> const &triangles1, std::vector<std::array<std::pair<double, double>, 3>> const &triangles2) {
	for (auto const &k : triangles1) {
		for (auto const &l : triangles2) {
			if (gjk((const vec2 *)k.data(), k.size(), (const vec2 *)l.data(), l.size())) return true;
		}
	}

	return false;
}