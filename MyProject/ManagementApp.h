#pragma once
#include<iostream>
class ManagementApp
{
private:
	static int numLocations;
	static int numEvents;
public: 
	static int getNumLocations();
	static int getNumEvents();

	void static incrementNumLocations();

	void static incrementNumEvents();

	void static decrementNumLocations();
	void static decrementNumEvents();
};

