#include "Map.h"



Map::Map(std::string startLocationName)
{
	CurrentLocation = new Location(startLocationName);
	_locationsVisited.push(CurrentLocation);
	_startLocationName = startLocationName;
}


Map::~Map()
{
}

void Map::Move(Location *newLocation) 
{	
	_locationsVisited.push(newLocation);
	CurrentLocation = newLocation;
}

std::string Map::GetPathBackToHome()
{
	std::stack<Location *> _tempLocations = _locationsVisited;
	Location * tempCurrent = CurrentLocation;
	std::string pathHome = "Path Home: ";
	while (tempCurrent->GetName() != _startLocationName)
	{
		pathHome += tempCurrent->GetName() + " -> ";
		_tempLocations.pop();
		tempCurrent = _tempLocations.top();
	}
	pathHome += "Home";
	
	return pathHome;
}

void Map::GoHome()
{
	while (CurrentLocation->GetName() != _startLocationName)
	{
		
		_locationsVisited.pop();
		CurrentLocation = _locationsVisited.top();
	}
}
