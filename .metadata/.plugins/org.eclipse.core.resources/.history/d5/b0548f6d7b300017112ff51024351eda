#ifndef __ELEVATOR_H__
#define __ELEVATOR_H__

#include <list>
#include "Passenger.h"
#include "ElevatorEnum.h"
#include "Updateable.h"

using namespace std;

class Elevator : public Updateable {

public:

	Elevator();
	Elevator(int, elevator_direction);
	~Elevator();

	static const int MAX_LOAD = 8;

	int getCurrentLoad();
	float getCurrentFloor();
	elevator_state& getCurrentState();
	elevator_direction& getCurrentDirection();

	void setCurrentDirection(elevator_direction);
	void takePassengers(int num_of_passengers = 1);
	void removePassengers(int num_of_passengers = 1);
	list<Passenger>& getPassengers();
	void update();

private:
	int current_load;
	float current_floor;
	elevator_state current_state;

	list<Passenger> passengers;

	int initial_floor;
	elevator_direction current_direction;

	static const float travel_speed = 1.0 / 10.0;

};

#endif
