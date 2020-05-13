#include "simulator.h"

//Mario Alex Crim

using namespace std;

Simulator::Simulator(string inputFile){
	filePath = inputFile;

}

void Simulator::run(){

	int address,
		position,
		tmp;
    char tmpDecision;
	bool decision;

	//Set up vector of smith counters
	for(int i=0; i<256; i++){
		counters.push_back(SmithCounter());
	}
 
	//open file and confirm it opened before proceeding
    ifstream infile(filePath, ios::in);
	if(!infile){
		cerr << "Can't open file...Cancelling" << endl;
		return;
	}

    while(infile >> address >> tmpDecision){
		
		//get position of counter in vector
		position = address >>2;
		tmp = pow(2,8)-1;
		position = position & tmp;

		//check what the actual decision was
		if(tmpDecision == 'T') 
			decision = true;
		else
			decision = false;

		//compare prediction and actual decision
		if(counters[position].prediction() == decision)
			if(decision)
				correctTakenCount++;
			else
				correctNotTakenCount++;
		
		//increment or decrement counter based on decision
        if(decision){
			takenCount++; 
			counters[position].increment();
		}
		else{
			notTakenCount++;
			counters[position].decrement();
		}
        totalBranches++;
    }
	infile.close();
}

void Simulator:: printStats(){

	int percentCorrect = (correctTakenCount+correctNotTakenCount)/(double)totalBranches*100;
    cout << "Number of branches: " << totalBranches << endl
    	 << "Number of branches taken: " << takenCount << endl
    	 << "    Number of taken branches correctly predicted: " << correctTakenCount << endl
    	 << "Number of branches not taken: " << notTakenCount << endl
    	 << "    Number of not taken branches correctly predicted: " << correctNotTakenCount <<endl
    	 << "Overall rate of correct predictions: " << percentCorrect << "%" << endl;

}
