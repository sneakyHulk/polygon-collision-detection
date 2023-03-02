#include <benchmark/benchmark.h>

#include <array>
#include <vector>

#include "../include/generate.h"
#include "../include/gjk.h"
#include "../include/sat.h"
#include "../include/utils.h"

std::vector<std::vector<std::pair<double, double>>> vertices = {generate_random_convex_polygon(3), generate_random_convex_polygon(4), generate_random_convex_polygon(5), generate_random_convex_polygon(6)};
std::vector<std::vector<std::pair<double, double>>> vertices_concave = {generate_random_polygon(3), generate_random_polygon(4), generate_random_polygon(5), generate_random_polygon(6)};

static void SAT(benchmark::State& state) {
	for (auto _ : state) {
		for (unsigned int i = 0; i < vertices.size(); ++i) {
			for (unsigned int j = i + 1; j < vertices.size(); ++j) {
				benchmark::DoNotOptimize(sat(vertices[i], vertices[j]));
			}
		}
	}
}
BENCHMARK(SAT);

static void GJK(benchmark::State& state) {
	for (auto _ : state) {
		for (unsigned int i = 0; i < vertices.size(); ++i) {
			for (unsigned int j = i + 1; j < vertices.size(); ++j) {
				benchmark::DoNotOptimize(gjk((const vec2*)vertices[i].data(), vertices[i].size(), (const vec2*)vertices[j].data(), vertices[j].size()));
			}
		}
	}
}
BENCHMARK(GJK);

static void SAT_CONCAVE(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<std::vector<std::array<std::pair<double, double>, 3>>> vertices_convex(vertices_concave.size());

		for (unsigned int i = 0; i < vertices_concave.size(); ++i) {
			vertices_convex[i] = generate_triangles(vertices_concave[i]);
		}

		for (unsigned int i = 0; i < vertices_convex.size(); ++i) {
			for (unsigned int j = i + 1; j < vertices_convex.size(); ++j) {
				benchmark::DoNotOptimize(check_collision_sat_concave(vertices_convex[i], vertices_convex[j]));
			}
		}
	}
}
BENCHMARK(SAT_CONCAVE);

static void GJK_CONCAVE(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<std::vector<std::array<std::pair<double, double>, 3>>> vertices_convex(vertices_concave.size());

		for (unsigned int i = 0; i < vertices_concave.size(); ++i) {
			vertices_convex[i] = generate_triangles(vertices_concave[i]);
		}

		for (unsigned int i = 0; i < vertices_convex.size(); ++i) {
			for (unsigned int j = i + 1; j < vertices_convex.size(); ++j) {
				benchmark::DoNotOptimize(check_collision_gjk_concave(vertices_convex[i], vertices_convex[j]));
			}
		}
	}
}
BENCHMARK(GJK_CONCAVE);

BENCHMARK_MAIN();