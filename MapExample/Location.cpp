#include "Location.h"



Location::Location(std::string name) : _name(name)
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
