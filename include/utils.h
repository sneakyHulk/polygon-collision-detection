#pragma once

#include <array>
#include <vector>

#include "../include/earcut.h"
#include "../include/gjk.h"
#include "../include/sat.h"

namespace mapbox::util {
	template <>
	struct nth<0, vec2> {
		inline static auto get(const vec2 &t) { return t.x; };
	};
	template <>
	struct nth<1, vec2> {
		inline static auto get(const vec2 &t) { return t.y; };
	};
}  // namespace mapbox::util

std::vector<std::array<vec2, 3>> generate_triangles(std::vector<vec2> const &polygon) {
	std::vector<std::array<vec2, 3>> res;

	std::vector<std::vector<vec2>> poly = {polygon};
	std::vector<uint32_t> indices = mapbox::earcut<uint32_t>(poly);

	for (unsigned int j = 0; j < indices.size(); j += 3) {
		res.push_back({vec2{polygon[indices[j]].x, polygon[indices[j]].y}, vec2{polygon[indices[j + 1]].x, polygon[indices[j + 1]].y}, vec2{polygon[indices[j + 2]].x, polygon[indices[j + 2]].y}});
	}

	return res;
}

bool check_collision_sat_concave(std::vector<std::array<vec2, 3>> const &triangles1, std::vector<std::array<vec2, 3>> const &triangles2) {
	for (unsigned int k = 0; k < triangles1.size(); ++k) {
		for (unsigned int l = 0; l < triangles2.size(); ++l) {
			if (sat_faster(triangles1[k].data(), triangles1[k].size(), triangles2[l].data(), triangles2[l].size())) return true;
		}
	}

	return false;
}

bool check_collision_gjk_concave(std::vector<std::array<vec2, 3>> const &triangles1, std::vector<std::array<vec2, 3>> const &triangles2) {
	for (auto const &k : triangles1) {
		for (auto const &l : triangles2) {
			if (gjk(k.data(), k.size(), l.data(), l.size())) return true;
		}
	}

	return false;
}