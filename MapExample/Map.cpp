#include "Map.h"



Map::Map(std::string startLocationName)
{
	CurrentLocation = new Location(startLocationName, 0 , 0);
	_HashTable.emplace("0,0", CurrentLocation);
	_locationsVisited.push(CurrentLocation);
	_startLocationName = startLocationName;
}


Map::~Map()
{
}

void Map::Move(Location *newLocation) 
{	
	std::string checkNorth = std::to_string(newLocation->x)
		+ "," + std::to_string(newLocation->y + 1);
	std::string checkSouth = std::to_string(newLocation->x) 
		+ "," + std::to_string(newLocation->y - 1);
	std::string checkEast = std::to_string(newLocation->x + 1) 
		+ "," + std::to_string(newLocation->y);
	std::string checkWest = std::to_string(newLocation->x - 1) 
		+ "," + std::to_string(newLocation->y);

	if (_HashTable.count(checkNorth) == 1)
	{
		newLocation->North = _HashTable.at(checkNorth);
	}
	if (_HashTable.count(checkSouth) == 1)
	{
		newLocation->South = _HashTable.at(checkSouth);
	}
	if (_HashTable.count(checkEast) == 1)
	{
		newLocation->East = _HashTable.at(checkEast);
	}
	if (_HashTable.count(checkWest) == 1)
	{
		newLocation->West = _HashTable.at(checkWest);
	}
	_locationsVisited.push(newLocation);
	_HashTable.emplace(std::to_string(newLocation->x)
		+ "," + std::to_string(newLocation->y), newLocation);
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
