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

}
