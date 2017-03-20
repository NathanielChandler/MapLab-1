#pragma once
#include <string>
class Location
{
private:
	std::string _name;
	
public:
	Location(std::string name, int xInt, int yInt);
	~Location();
	std::string DisplayLocationInfo();
	std::string GetName();

	Location *North = nullptr;
	Location *South = nullptr;
	Location *East = nullptr;
	Location *West = nullptr;

	int x;
	int y;
};

