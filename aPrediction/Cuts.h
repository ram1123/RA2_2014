#ifndef Cuts_H
#define Cuts_H
#include "vector"
#include "string"
#include "fstream"
#include "map"
#include <iostream>
#include "stdlib.h"
#include "algorithm"
class Cuts
{
public:
	Cuts(std::string Variable);
	~Cuts();
private:
	std::string Variable_;
};

#endif