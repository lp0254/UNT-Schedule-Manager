#include<string> 
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <sstream> 

using namespace std;

class room
{
private:
	string buildingName;
	long roomN;
	long size;
public:
	std::string GetBuildingName()
    	{
		return buildingName;
    	}
    	void SetBuildingName(std::string building)
    	{
    		buildingName = building;
    	}
	long GetRoomNumber()
	{
		return roomN;
	}
	void SetRoomNumber(int roomNumber)
	{
		roomN = roomNumber;
	}
	long GetCompacity()
	{
		return size;
	}
	void SetCompacity(int compacity)
	{
		size = compacity;
	}

};