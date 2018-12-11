#ifndef V2CPSE2_FACTORY_HPP
#define V2CPSE2_FACTORY_HPP

#include "SFML/Graphics.hpp"
#include "scherm_object.hpp"
#include <iostream>
#include <fstream>
#include "string"
#include "exception"
#include "factory_exceptions.hpp"
#include "ball.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "image.hpp"

std::ifstream &operator>>(std::ifstream &input, sf::Color &rhs) {
	std::string s;
	input >> s;
	const struct {
		const char *name;
		sf::Color color;
	} colors[]{
			{"YELLOW",  sf::Color::Yellow},
			{"RED",     sf::Color::Red},
			{"MAGENTA", sf::Color::Magenta},
	};

	for (auto const &color : colors) {
		if (color.name == s) {
			rhs = color.color;
			return input;
		}
	}
	if (s.empty()) {
		throw unexpected_eof_exception();
	}
	throw unknown_color_exception(s);
}


std::ifstream &operator>>(std::ifstream &input, sf::Vector2f &rhs) {
	char c;
	if (!(input >> c)) { throw unexpected_eof_exception(); }
	if (c != '(') { throw invalid_position(c); }
	if (!(input >> rhs.x)) { throw invalid_value(c); }
	if (!(input >> c)) { throw unexpected_eof_exception(); }
	if (c != ',') { throw invalid_position(c); }
	if (!(input >> rhs.y)) { throw invalid_value(c); }
	if (!(input >> c)) { throw unexpected_eof_exception(); }
	if (c != ')') { throw invalid_position(c); }
	return input;
}


scherm_object *createFromFile(std::ifstream &filehandle) {
	if (!filehandle.is_open()) {
		throw file_open_failed_exception();
	}
	sf::Vector2f position;
	std::string name;
	filehandle >> position >> name;
	if (name == "CIRCLE") {
		float radius;
		sf::Color color;
		filehandle >> radius;
		filehandle >> color;
		return new ball(position, sf::Vector2f(0, 0), radius, color);
	} else if (name == "RECTANGLE") {
		sf::Vector2f size;
		sf::Color color;
		filehandle >> size >> color;
		return new rectangle(position, size, color);
	} else if (name == "LINE") {
		sf::Vector2f end;
		sf::Color color;
		filehandle >> end >> color;
		return new line(position, end, color);
	} else if (name == "PICTURE") {
		sf::Vector2f size;
		std::string path;
		filehandle >> size >> path;
		return new image(position, size, path);
	} else if (name == "") {
		throw unexpected_eof_exception();
	}

	throw unknown_shape_exception(name);
}


#endif //V2CPSE2_FACTORY_HPP
