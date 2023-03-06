#pragma once

#include <cmath>
#include <limits>
#include <numeric>
#include <vector>

using Polygon = std::vector<vec2>;
using Triangle = std::array<vec2, 3>;

bool sat_faster(vec2 const *const poly1, unsigned int const count1, vec2 const *const poly2, unsigned int const count2) {
	for (unsigned int i = 0; i < count1; ++i) {
		unsigned int j = (i + 1) % count1;
		vec2 axis = {-(poly1[j].y - poly1[i].y), poly1[j].x - poly1[i].x};
		double norm = std::sqrt(axis.x * axis.x + axis.y * axis.y);
		axis = {axis.x / norm, axis.y / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (unsigned int k = 0; k < count1; ++k) {
			double dot = (poly1[k].x * axis.x + poly1[k].y * axis.y);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (unsigned int k = 0; k < count2; ++k) {
			double dot = (poly2[k].x * axis.x + poly2[k].y * axis.y);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	for (unsigned int i = 0; i < count2; ++i) {
		unsigned int j = (i + 1) % count2;
		vec2 axis = {-(poly2[j].y - poly2[i].y), poly2[j].x - poly2[i].x};
		double norm = std::sqrt(axis.x * axis.x + axis.y * axis.y);
		axis = {axis.x / norm, axis.y / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (unsigned int k = 0; k < count1; ++k) {
			double dot = (poly1[k].x * axis.x + poly1[k].y * axis.y);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (unsigned int k = 0; k < count2; ++k) {
			double dot = (poly2[k].x * axis.x + poly2[k].y * axis.y);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	return true;
}

bool sat(Polygon const &poly1, Polygon const &poly2) {
	for (unsigned int i = 0; i < poly1.size(); ++i) {
		unsigned int j = (i + 1) % poly1.size();
		std::pair<double, double> axis = {-(poly1[j].y - poly1[i].y), poly1[j].x - poly1[i].x};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (auto v : poly1) {
			double dot = (v.x * axis.first + v.y * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (auto v : poly2) {
			double dot = (v.x * axis.first + v.y * axis.second);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	for (unsigned int i = 0; i < poly2.size(); ++i) {
		unsigned int j = (i + 1) % poly2.size();
		std::pair<double, double> axis = {-(poly2[j].y - poly2[i].y), poly2[j].x - poly2[i].x};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (auto v : poly1) {
			double dot = (v.x * axis.first + v.y * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (auto v : poly2) {
			double dot = (v.x * axis.first + v.y * axis.second);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	return true;
}

bool sat(Triangle const &poly1, Triangle const &poly2) {
	for (unsigned int i = 0; i < poly1.size(); ++i) {
		unsigned int j = (i + 1) % poly1.size();
		std::pair<double, double> axis = {-(poly1[j].y - poly1[i].y), poly1[j].x - poly1[i].x};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (auto v : poly1) {
			double dot = (v.x * axis.first + v.y * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (auto v : poly2) {
			double dot = (v.x * axis.first + v.y * axis.second);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	for (unsigned int i = 0; i < poly2.size(); ++i) {
		unsigned int j = (i + 1) % poly2.size();
		std::pair<double, double> axis = {-(poly2[j].y - poly2[i].y), poly2[j].x - poly2[i].x};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (auto v : poly1) {
			double dot = (v.x * axis.first + v.y * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (auto v : poly2) {
			double dot = (v.x * axis.first + v.y * axis.second);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	return true;
}