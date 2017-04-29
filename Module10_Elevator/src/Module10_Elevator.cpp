#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <cmath>
#include <vector>

#include "ElevatorEnum.h"
#include "Elevator.h"
#include "Passenger.h"
#include "Floor.h"

using namespace std;

map<int, map<string, int> > getData() {
	map<int, map<string, int> > records;

	ifstream infile("Mod10_Assignment_Elevators.csv");

	while(infile) {
		string s;
		if(!getline(infile, s)) {
			break;
		}


		istringstream ss(s);

		int start_time;
		int start_floor;
		int end_floor;
		int value;
		int index = 0;
		while(ss >> value) {
			switch(index) {
			case 0: start_time = value;
					break;
			case 1: start_floor = value;
					break;
			case 2: end_floor = value;
					break;
			}

			if(ss.peek() == ',') {
				ss.ignore();
			}

			index++;
		}

		map<string, int> record;

		record["start_floor"] = start_floor;
		record["end_floor"] = end_floor;
		records[start_time] = record;
	}

	return records;

}

int main() {
	vector<Floor> floors;
	for(int floor_number = 0; floor_number < 100; floor_number++) {
		floors.push_back(Floor());
	}

	list<int> wait_times;
	list<int> travel_times;

	map<int, queue<Passenger> > building;

	map<int, map<string, int> > records = getData();

	/*
	// For debugging only
	for (map<int, map<string,int>>::iterator o_it = records.begin(); o_it != records.end(); ++o_it) {
		cout << o_it->first << endl;

		cout << o_it->second["start_floor"] << " - " << o_it->second["end_floor"] << endl;

		for (map<string, int>::iterator i_it = o_it->second.begin(); i_it != o_it->second.end(); ++i_it) {
			cout << i_it->first << " - " << i_it->second << endl;
		}
	}
	*/

	// Initialize all four elevators
	list<Elevator> elevators;

	Elevator e1(0, UP);
	Elevator e2(100, DOWN);
	Elevator e3(25, UP);
	Elevator e4(75, DOWN);

	elevators.push_front(e1);
	elevators.push_front(e2);
	elevators.push_front(e3);
	elevators.push_front(e4);

	// Start simulation
	for(int start_time = 0; start_time < 15216; start_time++) {

		map<int, map<string, int> >::iterator records_it = records.find(start_time);

		if(records_it != records.end()) {

			//Found start time
			// Create passenger waiting at start floor
			int start_floor = records_it->second["start_floor"];
			int end_floor = records_it->second["end_floor"];
			Passenger p(end_floor);

			floors[start_floor].addPassenger(p);
		}

		// Update each elevator
		for(list<Elevator>::iterator it = elevators.begin(); it != elevators.end(); ++it) {
			it->update();
//			cout << j << " : " << floor(it->getCurrentFloor()) << endl;
		}

		// Update each floor
		for(vector<Floor>::iterator it = floors.begin(); it != floors.end(); ++it) {

		}


	}
	/*
	for(int start_time = 0; start_time < 15216; start_time++) {
		map<int, map<string, int>> ::iterator records_it = records.find(start_time);
		if (records_it != records.end()) {
			cout << start_time << endl;
		}
	}

*/

	return 0;

}
