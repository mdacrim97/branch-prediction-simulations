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
	
	//set up smith counter vector    
	for(int i=0; i <256; i++)
        counters.push_back(SmithCounter());
	//set up bht
	for(int i=0; i<4; i++)
		bht.push_back(BranchHistoryRegister());


	//open file and confirm it opened before proceeding.
	ifstream infile(filePath, ios::in);
	if(!infile){
		cerr << "Can't open file...Cancelling" << endl;
		return;
	}

    while(infile >> address >> tmpDecision){

		//get position of counter in vector
		position = address >> 2;
		tmp = pow(2, 8) - 1;
		position = position & tmp;
		tmp = position; //position in bht
		position = position << 6;
		position = position | bht[tmp].getValue();

		//check what actual decision was
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

		//increment or decrement based on decision
        if(decision){
            takenCount++;
			counters[position].increment();
		}
		else{
			notTakenCount++;
            counters[position].decrement();
    	}

		//update the branch history register
		bht[tmp].update(decision);
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
