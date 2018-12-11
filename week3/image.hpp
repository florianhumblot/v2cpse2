//
// Created by djrel on 12/11/2018.
//

#ifndef V2CPSE2_IMAGE_HPP
#define V2CPSE2_IMAGE_HPP

#include "SFML/Graphics.hpp"
#include "scherm_object.hpp"

class image : public scherm_object {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	std::string path;
	std::string string_repr;
public:
	image(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &path) : position(position),
																							 size(size), path(path) {}

	void draw(sf::RenderWindow &w) override {
		sf::Texture texture;
		texture.loadFromFile(path);
		texture.setSmooth(true);
		sf::Sprite sprite(texture);
		sprite.setPosition(position);
		w.draw(sprite);
	}

	void move(const sf::Vector2f &delta) override {
		position += delta;
	}

	sf::RectangleShape getShape() override {
		sf::RectangleShape tmp(size);
		tmp.setPosition(position);
		return tmp;
	}

	std::string &to_string() override {
		string_repr = "(";
		string_repr += std::to_string((int) position.x);
		string_repr += ", ";
		string_repr += std::to_string((int) position.y);
		string_repr += ") PICTURE (";
		string_repr += std::to_string((int) size.x);
		string_repr += ", ";
		string_repr += std::to_string((int) size.y);
		string_repr += ") ";
		string_repr += path;
		return string_repr;
	}
};

#endif //V2CPSE2_IMAGE_HPP
