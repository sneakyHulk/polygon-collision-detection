#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

std::vector<sf::ConvexShape> plot(std::vector<std::vector<std::pair<double, double>>> const& vertices) {
	std::vector<sf::ConvexShape> shapes(vertices.size());

	for (unsigned int i = 0; i < vertices.size(); ++i) {
		shapes[i].setPointCount(vertices[i].size());
		for (unsigned int j = 0; j < vertices[i].size(); ++j) {
			shapes[i].setPoint(j, {static_cast<float>(vertices[i][j].first), static_cast<float>(vertices[i][j].second)});
		}

		switch (i % 7) {
			case 0:
				shapes[i].setFillColor(sf::Color::Blue);
				break;
			case 1:
				shapes[i].setFillColor(sf::Color::Red);
				break;
			case 2:
				shapes[i].setFillColor(sf::Color::Green);
				break;
			case 3:
				shapes[i].setFillColor(sf::Color::Yellow);
				break;
			case 4:
				shapes[i].setFillColor(sf::Color::Magenta);
				break;
			case 5:
				shapes[i].setFillColor(sf::Color::Cyan);
				break;
			case 6:
				shapes[i].setFillColor(sf::Color::Black);
				break;
		}
	}

	return shapes;
}

std::vector<sf::ConvexShape> plot(std::vector<std::vector<std::array<std::pair<double, double>, 3>>> const& triangles) {
	std::vector<sf::ConvexShape> shapes(triangles.size() * 3);

	for (unsigned int i = 0, idx = 0; i < triangles.size(); ++i) {
		for (unsigned int j = 0; j < triangles[i].size(); ++j, ++idx) {
			shapes[idx].setPointCount(3);
			for (unsigned int k = 0; k < 3; ++k) {
				shapes[idx].setPoint(k, {static_cast<float>(triangles[i][j][k].first), static_cast<float>(triangles[i][j][k].second)});
			}

			switch (idx % 7) {
				case 0:
					shapes[idx].setFillColor(sf::Color::Blue);
					break;
				case 1:
					shapes[idx].setFillColor(sf::Color::Red);
					break;
				case 2:
					shapes[idx].setFillColor(sf::Color::Green);
					break;
				case 3:
					shapes[idx].setFillColor(sf::Color::Yellow);
					break;
				case 4:
					shapes[idx].setFillColor(sf::Color::Magenta);
					break;
				case 5:
					shapes[idx].setFillColor(sf::Color::Cyan);
					break;
				case 6:
					shapes[idx].setFillColor(sf::Color::Black);
					break;
			}
		}
	}

	return shapes;
}

std::vector<sf::VertexArray> plot(std::vector<std::array<std::pair<double, double>, 2>> const& lines) {
	std::vector<sf::VertexArray> shapes(lines.size(), sf::VertexArray(sf::LineStrip, 2));

	for (unsigned int i = 0; i < lines.size(); ++i) {
		shapes[i][0].position.x = lines[i][0].first;
		shapes[i][0].position.y = lines[i][0].second;

		shapes[i][1].position.x = lines[i][1].first;
		shapes[i][1].position.y = lines[i][1].second;

		switch (i % 7) {
			case 0:
				shapes[i][0].color = sf::Color::Blue;
				shapes[i][1].color = sf::Color::Blue;
				break;
			case 1:
				shapes[i][0].color = sf::Color::Red;
				shapes[i][1].color = sf::Color::Red;
				break;
			case 2:
				shapes[i][0].color = sf::Color::Green;
				shapes[i][1].color = sf::Color::Green;
				break;
			case 3:
				shapes[i][0].color = sf::Color::Yellow;
				shapes[i][1].color = sf::Color::Yellow;
				break;
			case 4:
				shapes[i][0].color = sf::Color::Magenta;
				shapes[i][1].color = sf::Color::Magenta;
				break;
			case 5:
				shapes[i][0].color = sf::Color::Cyan;
				shapes[i][1].color = sf::Color::Cyan;
				break;
			case 6:
				shapes[i][0].color = sf::Color::Black;
				shapes[i][1].color = sf::Color::Black;
				break;
		}
	}

	return shapes;
}

void display(std::vector<sf::ConvexShape> const& shapes, std::vector<sf::VertexArray> const& lines = {}) {
	sf::RenderWindow window(sf::VideoMode(1200, 780), "Hello From SFML");

	sf::View view({0.5, 0.5}, {3.5, -3.5});

	window.setView(view);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::White);

		for (auto const& shape : shapes) {
			window.draw(shape);
		}

		for (auto const& line : lines) {
			window.draw(line);
		}

		window.display();
	}
}