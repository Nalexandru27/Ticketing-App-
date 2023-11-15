#include "ManagementApp.h"
#include <iostream>

int ManagementApp::numEvents = 0;
int ManagementApp::numLocations = 0;

int ManagementApp::getNumLocations() {
	return ManagementApp::numEvents;
}

int ManagementApp::getNumEvents() {
	return ManagementApp::numLocations;
}

void ManagementApp::incrementNumLocations() {
	ManagementApp::numEvents++;
}
void ManagementApp::incrementNumEvents() {
	ManagementApp::numLocations++;
}

void ManagementApp::decrementNumLocations() {
	ManagementApp::numEvents--;
}
void ManagementApp::decrementNumEvents() {
	ManagementApp::numLocations--;
}