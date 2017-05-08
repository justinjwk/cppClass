#ifndef __ELEVATOR_ENUM__
#define __ELEVATOR_ENUM__

enum elevator_state {STOPPED, STOPPING, MOVING_UP, MOVING_DOWN};
enum direction {UP, DOWN};
enum passenger_state {WAITING, RIDING, ARRIVED};

#endif
