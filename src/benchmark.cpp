#include <benchmark/benchmark.h>

#include "../include/generate.h"
#include "../include/gjk.h"
#include "../include/sat.h"

std::vector<std::vector<std::pair<double, double>>> vertices = {generate_random_convex_polygon(3), generate_random_convex_polygon(4), generate_random_convex_polygon(5), generate_random_convex_polygon(6)};

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

BENCHMARK_MAIN();