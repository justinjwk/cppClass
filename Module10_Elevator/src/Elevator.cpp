#include <iostream>
#include <list>
#include "Elevator.h"

using namespace std;

Elevator::Elevator() {

}

Elevator::Elevator(int init_floor, elevator_state cur_state) {
	current_state = cur_state;
	current_position = init_floor * FLOOR_SPEED_PER_SEC;;
	current_load = 0;
}

Elevator::~Elevator() {

}

int Elevator::getCurrentLoad() {
	return current_load;
}

int Elevator::getCurrentPosition() {
	return current_position;
}

void Elevator::setCurrentPosition(int cur_pos) {
	current_position = cur_pos;
}

int Elevator::getCurrentFloor() {
	return current_position /FLOOR_SPEED_PER_SEC;
}

elevator_state& Elevator::getCurrentState() {
	return current_state;
}

void Elevator::takePassengers(int num_of_passengers) {
	current_load += num_of_passengers;
}

void Elevator::removePassengers(int num_of_passengers) {
	current_load -= num_of_passengers;
}

list<Passenger>& Elevator::getPassengers() {
	return passengers;
}

void Elevator::update() {

	switch (current_state) {
		case MOVING_UP:
			// when the elevator reaches top of the building
			// change the direction to down
			if((current_position / FLOOR_SPEED_PER_SEC) == 100) {
				current_position -= 1;
				current_state = MOVING_DOWN;
			}
			// or keep moving up
			else {
				current_position += 1;
			}
			break;
		case MOVING_DOWN:
			if(current_position == 0) {
				current_position += 1;
				current_state = MOVING_UP;
			}
			else {
				current_position -= 1;
			}
			break;
		case STOPPING:
			break;
		case STOPPED:
			break;
	}

	//Iterate list of passengers
	list<Passenger>::iterator passengers_it;
	for(passengers_it= passengers.begin(); passengers_it != passengers.end(); ++passengers_it) {
		cout << passengers_it->getDestinationFloor() << endl;

		// Shift passengers between floor and elevator based on floor location
		if (passengers_it->getDestinationFloor() == getCurrentFloor()) {

		}
		passengers_it->addTravelTime(1);
	}
}
