#include <iostream>
#include <list>
#include "Elevator.h"

using namespace std;

Elevator::Elevator() {

}

Elevator::Elevator(int init_floor, elevator_direction cur_direction) {
	initial_floor = init_floor;
	current_direction = cur_direction;
	current_load = 0;
}

Elevator::~Elevator() {

}

int Elevator::getCurrentLoad() {
	return current_load;
}

float Elevator::getCurrentFloor() {
	return current_floor;
}

elevator_state& Elevator::getCurrentState() {
	return current_state;
}

elevator_direction& Elevator::getCurrentDirection() {
	return current_direction;
}

void Elevator::setCurrentDirection(elevator_direction direction){
	current_direction = direction;
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
	if(current_direction == UP) {
		if(current_floor > 100.0) {
			current_floor -= 0.1;
			current_direction = DOWN;
		}
		else {
			current_floor += 0.1;
		}
	}
	else {
		if(current_floor < 0.0) {
			current_floor += 0.1;
			current_direction = UP;
		}
		else {
			current_floor -= 0.1;
		}
	}

	//Iterate list of passengers
	list<Passenger>::iterator passengers_it;
	for(passengers_it= passengers.begin(); passengers_it != passengers.end(); ++passengers_it) {
		cout << passengers_it->getDestinationFloor() << endl;

		passengers_it->addTravelTime(1);
	}
}
