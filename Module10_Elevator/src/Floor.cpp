#include <iostream>
#include <deque>
#include "Passenger.h"
#include "Floor.h"

Floor::Floor() {


}

Floor::~Floor() {

}

queue<Passenger>& Floor::getPassengers() {
	return passengers;
}

void Floor::addPassenger(Passenger& p) {
	passengers.push(p);
}

void Floor::update() {
	for (deque<Passenger>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
		it->addWaitTime(1);
	}
}
