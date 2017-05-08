#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include "Updateable.h"
#include "ElevatorEnum.h"

using namespace std;

class Passenger : public Updateable {

public:

	//Construct passenger with destination floor
	Passenger(int, int);
	virtual ~Passenger();

	int& getWaitTime();
	void addWaitTime(int);
	int& getTravelTime();
	void addTravelTime(int);
	void update();
	void startTravelTime();
	void startWaitTime();
	int& getDestinationFloor();
	passenger_state& getCurrentState();
	void setCurrentState(passenger_state&);

	direction& getDirection();

private:

	int wait_time;
	int travel_time;
	int start_floor;
	int destination_floor;
	passenger_state current_state;
	direction heading;
};

#endif
