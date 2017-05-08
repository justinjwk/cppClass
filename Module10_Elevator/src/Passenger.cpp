#include "ElevatorEnum.h"
#include "Passenger.h"

Passenger::Passenger(int star_floor, int dest_floor) {
	start_floor = star_floor;
	destination_floor = dest_floor;
	current_state = WAITING;
	wait_time = 0;
	travel_time = 0;

	if (destination_floor > start_floor) {
		heading = DOWN;
	}
	else {
		heading = UP;
	}
}

Passenger::~Passenger() {

}

void Passenger::addWaitTime(int wt) {
	wait_time = wt;
}

int& Passenger::getWaitTime() {
	return wait_time;
}

int& Passenger::getTravelTime() {
	return travel_time;
}

void Passenger::addTravelTime(int tt) {
	travel_time = tt;
}

void Passenger::update() {

}

int& Passenger::getDestinationFloor() {
	return destination_floor;
}

passenger_state& Passenger::getCurrentState() {
	return current_state;
}

direction& Passenger::getDirection() {
	return heading;
}

void Passenger::setCurrentState(passenger_state& pass_state) {
	current_state = pass_state;
}
