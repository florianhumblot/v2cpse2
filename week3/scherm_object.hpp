#ifndef V2CPSE2_SCHERM_OBJECT_HPP
#define V2CPSE2_SCHERM_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "ostream"
#include "factory_exceptions.hpp"

class scherm_object {
public:
	virtual void draw(sf::RenderWindow &w) = 0;

	virtual void move(const sf::Vector2f &delta) = 0;

	virtual sf::RectangleShape getShape() = 0;

	virtual std::string &to_string() = 0;

	friend std::ostream &operator<<(std::ostream &out, scherm_object *obj) {
		return out << obj->to_string();
	}

};

extern std::string &operator+=(std::string &output, sf::Color &rhs);

#endif //V2CPSE2_SCHERM_OBJECT_HPP
