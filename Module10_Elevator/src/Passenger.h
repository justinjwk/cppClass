#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include "Updateable.h"

using namespace std;

class Passenger : public Updateable {

public:

	//Construct passenger with destination floor
	Passenger(int);
	~Passenger();

	int& getWaitTime();
	void addWaitTime(int);
	int& getTravelTime();
	void addTravelTime(int);
	void update();
	void startTravelTime();
	void startWaitTime();
	int& getDestinationFloor();

private:

	int wait_time;
	int travel_time;
	int destination_floor;
};

#endif
