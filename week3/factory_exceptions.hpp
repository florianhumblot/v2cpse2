//
// Created by djrel on 12/11/2018.
//

#ifndef V2CPSE2_FACTORY_EXCEPTIONS_HPP
#define V2CPSE2_FACTORY_EXCEPTIONS_HPP

#include "iostream"
#include "exception"

class file_open_failed_exception : public std::exception {
public:
	explicit file_open_failed_exception(const std::string &__arg = "File open failed") {}

	const char *what() const throw() override {
		return "Couldn't open file";
	}
};

class unexpected_eof_exception : public std::exception {
public:
	explicit unexpected_eof_exception(const std::string &__arg = "Unexpected end of file") {}

	const char *what() const throw() override {
		return "Unexpected end of file";
	}
};

class unknown_shape_exception : public std::exception {
	std::string name;
public:
	explicit unknown_shape_exception(const std::string &__arg = "Unknown shape") : name(
			std::string("No matching shape for name \'" + __arg + "\' found")) {}

	const char *what() const throw() override {
		return name.c_str();
	}
};

class unknown_color_exception : public std::exception {
	std::string name;
public:
	explicit unknown_color_exception(const std::string &__arg = "Unknown color") : name(
			std::string("No matching color for name \'" + __arg + "\' found ")) {}

	const char *what() const throw() override {
		return name.c_str();
	}
};

class invalid_position : public std::exception {
	std::string name;
public:
	explicit invalid_position(char __arg) : name(std::string("Invalid position for character found")) {}

	const char *what() const throw() override {
		return name.c_str();
	}

};

class invalid_value : public std::exception {
	std::string name;
public:
	explicit invalid_value(char __arg) : name(std::string("Invalid value entered")) {}

	const char *what() const throw() override {
		return name.c_str();
	}
};


#endif //V2CPSE2_FACTORY_EXCEPTIONS_HPP
