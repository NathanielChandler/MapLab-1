#include "Location.h"



Location::Location(std::string name, int xInt, int yInt) : _name(name) , x(xInt), y(yInt)
{
}


Location::~Location()
{
}

std::string Location::DisplayLocationInfo()
{
	return "Location is " + _name + "\n";
}

std::string Location::GetName()
{
	return _name;
}
