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
	std::string pathHome = "Taking Path Home: ";
	while (CurrentLocation->GetName() != _startLocationName)
	{
		pathHome += CurrentLocation->GetName() + " -> ";
		_locationsVisited.pop();
		CurrentLocation = _locationsVisited.top();
	}
	pathHome += "Home";
	
	return pathHome;
}
