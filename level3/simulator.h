#ifndef CRIM_SMITH_SIM_H
#define CRIM_SMITH_SIM_H

//Mario Alex Crim

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include "bhr.h"
#include "smithCounter.h"

using namespace std;

class Simulator{
	private:
		string filePath;
		int totalBranches = 0,
			takenCount = 0,
    		notTakenCount = 0,
    		correctTakenCount = 0,
    		correctNotTakenCount = 0;
		
		vector<SmithCounter> counters;

	public:
		Simulator(string filePath);
		~Simulator(){}
		void run();
		void printStats();
		


};

#endif
