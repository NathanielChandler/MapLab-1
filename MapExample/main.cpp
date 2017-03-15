#include <iostream>
#include "Map.h"
using namespace std;

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);


int main()
{
	auto map = Map("Home");
	int choice = -1;
	while (choice != 0) 
	{
		system("cls");
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go west" << endl;
		cout << "6) Path To Home" << endl;
		cout << "0) Exit" << endl;
		cin >> choice;

		switch (choice) 
		{
		case 1: cout << "Current Location: " << map.CurrentLocation->DisplayLocationInfo(); break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: system("cls");  cout << map.GetPathBackToHome() << endl; break;
		case 0: break;
		default: cout << "Enter a valid option"; break;
		}
		system("pause");
	}
	
	return 0;
}

void GoNorth(Map &map) 
{
	auto newLocation = map.CurrentLocation->North;
	if (newLocation == nullptr) 
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "This place is now called: " + name << endl;
		
	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->South = map.CurrentLocation;
	map.Move(newLocation);	
	return;
}

void GoEast(Map &map)
{
	auto newLocation = map.CurrentLocation->East;
	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "This place is now called: " + name << endl;

	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->West = map.CurrentLocation;
	map.Move(newLocation);
	return;
}

void GoSouth(Map &map)
{
	auto newLocation = map.CurrentLocation->South;
	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "This place is now called: " + name << endl;

	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->North = map.CurrentLocation;
	map.Move(newLocation);
	return;
}

void GoWest(Map &map)
{
	auto newLocation = map.CurrentLocation->West;
	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "This place is now called: " + name << endl;

	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->East = map.CurrentLocation;
	map.Move(newLocation);
	return;
}