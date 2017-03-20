#pragma once
#include <stack>
#include <unordered_map>
#include "Location.h"
class Map
{
private:
	std::stack<Location *> _locationsVisited;
	std::unordered_map<std::string, Location*> _HashTable;
	std::string _startLocationName;

public:
	Map(std::string startLocationName);
	~Map();

	Location * CurrentLocation = nullptr;
	std::string GetPathBackToHome();
	void GoHome();
	void Move(Location *newLocation);
};

