#include "simulator.h"

//Mario Alex Crim

using namespace std;

Simulator::Simulator(string inputFile){
	filePath = inputFile;

}

void Simulator::run(){

	BranchHistoryRegister bhr = BranchHistoryRegister();
	int address;
    char tmpDecision;
	bool decision;
	int position;
	int i = 0;

	
 
    //set up smith counter vector
	for(int i=0; i <1475 ; i++){
        SmithCounter sCounter;
        counters.push_back(sCounter);
	}

	ifstream infile(filePath, ios::in);
    while(infile >> address >> tmpDecision){

		if(tmpDecision == 'T'){ 
			decision = true;
			takenCount++; 
		}
		else{ 
			decision = false; 
			notTakenCount++;
		}

		//Get new position from bhr
		int position = address >> (16u - 2u),
		    operand = pow(2, 8) - 1; 
		position = position & operand;
	
		position = position ^ bhr.getValue();


        if(counters[position].prediction() != decision){
            if(decision)
                counters[position].increment();
			else
                counters[position].decrement();
        }
		else{
            if(decision)
                correctTakenCount++;
			else
                correctnotTakenCount++;
        }

		bhr.update(decision);
		i++;
    }
	totalBranches = i;

}

void Simulator:: printStats(){

	int percentCorrect = (correctTakenCount+correctnotTakenCount)/(double)totalBranches*100;
    cout << "Number of branches: " << totalBranches << endl
    	 << "Number of branches taken: " << takenCount << endl
    	 << "    Number of taken branches correctly predicted: " << correctTakenCount << endl
    	 << "Number of branches not taken: " << notTakenCount << endl
    	 << "    Number of not taken branches correctly predicted: " << correctnotTakenCount <<endl
    	 << "Overall rate of correct predictions: " << percentCorrect << "%" << endl;

}
