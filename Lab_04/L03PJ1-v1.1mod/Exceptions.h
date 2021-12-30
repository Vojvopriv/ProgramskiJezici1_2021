#pragma once
#include <iostream>
#include <exception>

class InvalidAdd : public std::exception {
	
public:
	InvalidAdd() : std::exception("Can't add duplicate in set!") {}
};

class InvalidRemove : public std::exception {

public:
	InvalidRemove() : std::exception("Can't remove element that doesn't exist!") {}
};
