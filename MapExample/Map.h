#pragma once
#include <stack>
#include "Location.h"
class Map
{
private:
	std::stack<Location *> _locationsVisited;
	std::string _startLocationName;

public:
	Map(std::string startLocationName);
	~Map();

	Location * CurrentLocation = nullptr;
	std::string GetPathBackToHome();
	void Move(Location *newLocation);
};

