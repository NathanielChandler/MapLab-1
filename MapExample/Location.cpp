#include "Location.h"



Location::Location(std::string name, int xInt, int yInt) : _name(name) , x(xInt), y(yInt)
{
}


Location::~Location()
{
}

std::string Location::DisplayLocationInfo()
{
	return "Location: " + _name + "\nCoordinates: (" + std::to_string(x) + "," + std::to_string(y) + ")\n";
}

std::string Location::GetName()
{
	return _name;
}
