#include "bhr.h"

//Mario Alex Crim

BranchHistoryRegister::BranchHistoryRegister(){
	value = 0;
	max = pow(2, 6) -1;

}


void BranchHistoryRegister::update(bool decision){
	int tmpVal = value;
	tmpVal = tmpVal << 1u;

	int tmp;
	if(decision){tmp = 1;} 
		
	else{tmp = 0;}
		
	
	tmpVal = tmpVal | tmp;
	value = tmpVal & max;
}


