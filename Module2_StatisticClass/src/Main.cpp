#include <iostream>
#include "StatisticH.h"
using namespace std;

void output(StatisticH s) {
	cout << "Average: " << s.average();
	cout << "\tSTD : " << s.STD() << "\n";
}

int main() {

	StatisticH s;

	output(s);




}
