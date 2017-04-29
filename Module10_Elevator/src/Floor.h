#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <queue>
#include "Updateable.h"
#include "Passenger.h"

using namespace std;

class Floor : public Updateable {

public:

	Floor();
	~Floor();

	void update();

	queue<Passenger>& getPassengers();
	void addPassenger(Passenger&);

private:
	queue<Passenger> passengers;

};


#endif
