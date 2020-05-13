#include "simulator.h"

//Mario Alex Crim

using namespace std;

int main(int argc, char** argv) {

	if(argc == 1){
		cout << "Pass file as parameter." << endl;
		return -1;	
	}
	
	Simulator sim = Simulator(argv[1]);
	
	sim.run();
	sim.printStats();

	return 0;
}
