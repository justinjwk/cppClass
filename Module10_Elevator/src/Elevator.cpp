#include <iostream>
#include <list>
#include <queue>
#include "Elevator.h"
#include "Common.h"

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

direction& Elevator::getCurrentDirection() {
	return current_direction;
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
	// Update elevator state
	switch (current_state) {
		case MOVING_UP:
			// when the elevator reaches top of the building
			// change the direction to down
			if((current_position / FLOOR_SPEED_PER_SEC) == 99) {
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

	// Give passengers a chance to get off
	for (list<Passenger>::iterator passengers_it = passengers.begin(); passengers_it != passengers.end(); ++passengers_it) {

		// Passenger arrived at destination floor and getting out
		if (pasengers_it->getDestinationFloor() == getCurrentFloor()) {

			// Update wait and travel times
			wait_times.push_back(passengers_it->getWaitTime());

			travel_times.push_back(passengers_it->getTravelTime());

			passengers.erase(passengers_it);
		}

		passengers_it->addTravelTime(1);
	}

	// Give passengers a chance to get on
	// if current capacity allows
	if(current_position % FLOOR_SPEED_PER_SEC == 0) {

		deque<Passenger> ps = floors.at(getCurrentFloor()).getPassengers();
		for (deque<Passenger>::iterator passenger = ps.begin(); passenger != ps.end(); ++passenger) {
			if (getCurrentLoad() < MAX_LOAD) {
				if (passenger->getDirection() == getCurrentDirection()) {
					passengers.push_back(*passenger);
					ps.erase(passenger);
				}
			}
		}
	}
}
