#pragma once

#include <cmath>
#include <limits>
#include <vector>

using Polygon = std::vector<std::pair<double, double>>;
using Triangle = std::array<std::pair<double, double>, 3>;

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
			double q = (v.first * axis.first + v.second * axis.second);
			min_poly2 = std::min(min_poly2, q);
			max_poly2 = std::max(max_poly2, q);
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
			double q = (v.first * axis.first + v.second * axis.second);
			min_poly2 = std::min(min_poly2, q);
			max_poly2 = std::max(max_poly2, q);
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
			double q = (v.first * axis.first + v.second * axis.second);
			min_poly2 = std::min(min_poly2, q);
			max_poly2 = std::max(max_poly2, q);
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
			double q = (v.first * axis.first + v.second * axis.second);
			min_poly2 = std::min(min_poly2, q);
			max_poly2 = std::max(max_poly2, q);
		}

		if (!(max_poly2 >= min_poly1 && max_poly1 >= min_poly2)) return false;
	}

	return true;
}