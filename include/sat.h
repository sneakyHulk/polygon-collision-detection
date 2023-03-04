#pragma once

#include <cmath>
#include <limits>
#include <numeric>
#include <vector>

using Polygon = std::vector<std::pair<double, double>>;
using Triangle = std::array<std::pair<double, double>, 3>;
using Line = std::array<std::pair<double, double>, 2>;

bool sat_line(Polygon const &poly, Line const &line) {
	for (unsigned int i = 0; i < poly.size(); ++i) {
		unsigned int j = (i + 1) % poly.size();
		std::pair<double, double> axis = {-(poly[j].second - poly[i].second), poly[j].first - poly[i].first};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly = std::numeric_limits<double>::infinity(), max_poly = -std::numeric_limits<double>::infinity();
		for (auto v : poly) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_poly = std::min(min_poly, dot);
			max_poly = std::max(max_poly, dot);
		}

		double min_line = std::numeric_limits<double>::infinity(), max_line = -std::numeric_limits<double>::infinity();
		for (auto v : line) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_line = std::min(min_line, dot);
			max_line = std::max(max_line, dot);
		}

		if (!(max_line >= min_poly && max_poly >= min_line)) return false;
	}

	for (unsigned int i = 0; i < line.size(); ++i) {
		unsigned int j = (i + 1) % line.size();
		std::pair<double, double> axis = {-(line[j].second - line[i].second), line[j].first - line[i].first};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly = std::numeric_limits<double>::infinity(), max_poly = -std::numeric_limits<double>::infinity();
		for (auto v : poly) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_poly = std::min(min_poly, dot);
			max_poly = std::max(max_poly, dot);
		}

		double min_line = std::numeric_limits<double>::infinity(), max_line = -std::numeric_limits<double>::infinity();
		for (auto v : line) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_line = std::min(min_line, dot);
			max_line = std::max(max_line, dot);
		}

		if (!(max_line >= min_poly && max_poly >= min_line)) return false;
	}

	return true;
}

bool sat_faster(std::pair<double, double> const *const poly1, unsigned int const count1, std::pair<double, double> const *const poly2, unsigned int const count2) {
	for (unsigned int i = 0; i < count1; ++i) {
		unsigned int j = (i + 1) % count1;
		std::pair<double, double> axis = {-(poly1[j].second - poly1[i].second), poly1[j].first - poly1[i].first};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (unsigned int k = 0; k < count1; ++k) {
			double dot = (poly1[k].first * axis.first + poly1[k].second * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (unsigned int k = 0; k < count2; ++k) {
			double dot = (poly2[k].first * axis.first + poly2[k].second * axis.second);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	for (unsigned int i = 0; i < count2; ++i) {
		unsigned int j = (i + 1) % count2;
		std::pair<double, double> axis = {-(poly2[j].second - poly2[i].second), poly2[j].first - poly2[i].first};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (unsigned int k = 0; k < count1; ++k) {
			double dot = (poly1[k].first * axis.first + poly1[k].second * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (unsigned int k = 0; k < count2; ++k) {
			double dot = (poly2[k].first * axis.first + poly2[k].second * axis.second);
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
		std::pair<double, double> axis = {-(poly1[j].second - poly1[i].second), poly1[j].first - poly1[i].first};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (auto v : poly1) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (auto v : poly2) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	for (unsigned int i = 0; i < poly2.size(); ++i) {
		unsigned int j = (i + 1) % poly2.size();
		std::pair<double, double> axis = {-(poly2[j].second - poly2[i].second), poly2[j].first - poly2[i].first};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (auto v : poly1) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (auto v : poly2) {
			double dot = (v.first * axis.first + v.second * axis.second);
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
		std::pair<double, double> axis = {-(poly1[j].second - poly1[i].second), poly1[j].first - poly1[i].first};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (auto v : poly1) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (auto v : poly2) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	for (unsigned int i = 0; i < poly2.size(); ++i) {
		unsigned int j = (i + 1) % poly2.size();
		std::pair<double, double> axis = {-(poly2[j].second - poly2[i].second), poly2[j].first - poly2[i].first};
		double norm = std::sqrt(axis.first * axis.first + axis.second * axis.second);
		axis = {axis.first / norm, axis.second / norm};

		double min_poly1 = std::numeric_limits<double>::infinity(), max_poly1 = -std::numeric_limits<double>::infinity();
		for (auto v : poly1) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_poly1 = std::min(min_poly1, dot);
			max_poly1 = std::max(max_poly1, dot);
		}

		double min_poly2 = std::numeric_limits<double>::infinity(), max_poly2 = -std::numeric_limits<double>::infinity();
		for (auto v : poly2) {
			double dot = (v.first * axis.first + v.second * axis.second);
			min_poly2 = std::min(min_poly2, dot);
			max_poly2 = std::max(max_poly2, dot);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	return true;
}