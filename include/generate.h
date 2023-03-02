#include <random>
#include <vector>

std::vector<std::pair<double, double>> generate_random_convex_polygon(unsigned int n) {
	thread_local static std::random_device rd;
	thread_local static std::mt19937 mt{rd()};
	thread_local static std::uniform_int_distribution<> uniform_bool_distribution(0, 1);
	thread_local static std::uniform_real_distribution<double> uniform_real_distribution;

	std::vector<double> x_pool;
	x_pool.reserve(n);
	std::vector<double> y_pool;
	y_pool.reserve(n);

	for (int i = 0; i < n; i++) {
		x_pool.push_back(uniform_real_distribution(mt));
		y_pool.push_back(uniform_real_distribution(mt));
	}

	std::sort(x_pool.begin(), x_pool.end());
	std::sort(y_pool.begin(), y_pool.end());

	double min_x = x_pool[0];
	double max_x = x_pool[n - 1];
	double min_y = y_pool[0];
	double max_y = y_pool[n - 1];

	std::vector<double> x_vec;
	x_vec.reserve(n);
	std::vector<double> y_vec;
	y_vec.reserve(n);

	double lastTop = min_x, lastBot = min_x;

	for (int i = 1; i < n - 1; i++) {
		double x = x_pool[i];

		if (uniform_bool_distribution(mt)) {
			x_vec.push_back(x - lastTop);
			lastTop = x;
		} else {
			x_vec.push_back(lastBot - x);
			lastBot = x;
		}
	}

	x_vec.push_back(max_x - lastTop);
	x_vec.push_back(lastBot - max_x);

	double lastLeft = min_y, lastRight = min_y;

	for (int i = 1; i < n - 1; i++) {
		double y = y_pool[i];

		if (uniform_bool_distribution(mt)) {
			y_vec.push_back(y - lastLeft);
			lastLeft = y;
		} else {
			y_vec.push_back(lastRight - y);
			lastRight = y;
		}
	}

	y_vec.push_back(max_y - lastLeft);
	y_vec.push_back(lastRight - max_y);

	std::shuffle(y_vec.begin(), y_vec.end(), mt);

	std::vector<std::pair<double, double>> vec;
	vec.reserve(n);

	for (int i = 0; i < n; i++) {
		vec.emplace_back(x_vec[i], y_vec[i]);
	}

	std::sort(vec.begin(), vec.end(), [](std::pair<double, double> const lhs, std::pair<double, double> const rhs) { return std::atan2(lhs.second, lhs.first) < std::atan2(rhs.second, rhs.first); });

	double x = 0, y = 0;
	double min_polygon_x = 0;
	double min_polygon_y = 0;
	std::vector<std::pair<double, double>> points;
	points.reserve(n);

	for (int i = 0; i < n; i++) {
		points.emplace_back(x, y);

		x += vec[i].first;
		y += vec[i].second;

		min_polygon_x = std::min(min_polygon_x, x);
		min_polygon_y = std::min(min_polygon_y, y);
	}

	double x_shift = min_x - min_polygon_x;
	double y_shift = min_y - min_polygon_y;

	for (int i = 0; i < n; i++) {
		points[i].first += x_shift;
		points[i].second += y_shift;
	}

	return points;
}