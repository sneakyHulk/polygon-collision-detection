#include <SFML/Graphics.hpp>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/register/linestring.hpp>
#include <boost/geometry/geometries/register/point.hpp>

// #include <boost/foreach.hpp>
// #include <boost/geometry.hpp>
// #include <boost/geometry/extensions/algorithms/closest_point.hpp>
// #include <boost/geometry/geometries/linestring.hpp>
// #include <boost/geometry/geometries/multi_point.hpp>
// #include <boost/geometry/geometries/multi_polygon.hpp>
// #include <boost/geometry/geometries/point_xy.hpp>
// #include <boost/geometry/geometries/polygon.hpp>
// #include <boost/geometry/geometries/register/linestring.hpp>
// #include <boost/geometry/geometries/register/point.hpp>
// #include <boost/geometry/strategies/cartesian/distance_projected_point.hpp>
// #include <boost/geometry/strategies/strategies.hpp>
#include <iostream>
#include <list>
// #include <boost/geometry/algorithms/closest_points.hpp>

#include "../include/plot.h"

typedef boost::geometry::model::d2::point_xy<double> point_type;
typedef boost::geometry::model::polygon<point_type> polygon_type;
typedef boost::geometry::model::linestring<point_type> linestring_type;
typedef boost::geometry::model::multi_point<point_type> multi_point_type;

std::vector<sf::VertexArray> plot(linestring_type const& line) {
	std::vector<sf::VertexArray> shapes(1, sf::VertexArray(sf::LineStrip, line.size()));

	for (unsigned int i = 0; i < line.size(); ++i) {
		shapes[0][i].position.x = line[i].x();
		shapes[0][i].position.y = line[i].y();
		shapes[0][i].color = sf::Color::Black;
	}

	return shapes;
}

BOOST_GEOMETRY_REGISTER_POINT_2D(vec2, double, boost::geometry::cs::cartesian, x, y)
BOOST_GEOMETRY_REGISTER_LINESTRING(std::vector<vec2>)

int main() {
	point_type p(1, 1);
	polygon_type poly;
	linestring_type line;
	multi_point_type mp;

	boost::geometry::read_wkt(
	    "POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3)"
	    "(4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))",
	    poly);
	line.push_back(point_type(0, 0));
	line.push_back(point_type(0, 3));
	mp.push_back(point_type(0, 0));
	mp.push_back(point_type(3, 3));

	std::cout << "Point-Poly: " << boost::geometry::distance(p, poly) << std::endl << "Point-Line: " << boost::geometry::distance(p, line) << std::endl << "Point-MultiPoint: " << boost::geometry::distance(p, mp) << std::endl;

	display({}, plot(line));

	boost::geometry::strategy::distance::projected_point projectedPoint;

	auto x = boost::geometry::distance(p, line, projectedPoint);
	std::cout << x;

	std::vector<vec2> test = {{-1.5, 0.0}, {-1.0, -1.0}, {0.0, 1.0}, {0.4, 0.5}, {0.5, 0.6}, {0.9, 2.0}};

	sf::VertexArray curve(sf::PrimitiveType::LinesStrip);
	sf::VertexArray curve2(sf::PrimitiveType::LinesStrip, 2);
	curve2[0] = sf::Vertex(sf::Vector2f(1, 1), sf::Color::Blue);
	curve2[1] = sf::Vertex(sf::Vector2f(1, 2), sf::Color::Blue);
	sf::VertexArray curve3(sf::PrimitiveType::LinesStrip, 2);
	curve3[0] = sf::Vertex(sf::Vector2f(0.643396, 1.10189), sf::Color::Green);
	curve3[1] = sf::Vertex(sf::Vector2f(0.8, 1.3), sf::Color::Green);

	for (auto e : test) curve.append(sf::Vertex(sf::Vector2f(e.x, e.y), sf::Color::Black));

	display({}, {curve, curve2, curve3});

	//boost::geometry::closest_point_result<vec2> p2;
	//boost::geometry::closest_point(p, test, p2);
//
	//std::cout << p2.closest_point.x << "/" << p2.closest_point.y << std::endl;

	boost::geometry::model::segment<vec2> sout1;
	boost::geometry::closest_points(p, test, sout1);

	std::cout << sout1.first.x << "/" << sout1.first.y << ", " << sout1.second.x << "/" << sout1.second.y << std::endl;

	return 0;
}