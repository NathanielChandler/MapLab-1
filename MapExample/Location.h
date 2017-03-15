#pragma once
#include <string>
class Location
{
private:
	std::string _name;
	
public:
	Location(std::string name);
	~Location();
	std::string DisplayLocationInfo();
	std::string GetName();

	Location *North = nullptr;
	Location *South = nullptr;
	Location *East = nullptr;
	Location *West = nullptr;
};

