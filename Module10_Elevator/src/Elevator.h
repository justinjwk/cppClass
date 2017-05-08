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
	Elevator(int, elevator_state);
	virtual ~Elevator();

	static const int MAX_LOAD = 8;
	static const int FLOOR_SPEED_PER_SEC = 10;

	int getCurrentLoad();
	int getCurrentPosition();
	void setCurrentPosition(int);
	int getCurrentFloor();
	elevator_state& getCurrentState();
	direction& getCurrentDirection();

	void takePassengers(int num_of_passengers = 1);
	void removePassengers(int num_of_passengers = 1);
	list<Passenger>& getPassengers();
	void update();

private:
	int current_load;
	int current_floor;
	int current_position;
	elevator_state current_state;
	direction current_direction;
	list<Passenger> passengers;

	int initial_floor;

};

#endif
