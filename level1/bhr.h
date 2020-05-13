#ifndef CRIM_BHR_H
#define CRIM_BHR_H

//Mario Alex Crim

#include <math.h>

class BranchHistoryRegister{
	private:
		int value,
			max;
	public:
		BranchHistoryRegister();
		~BranchHistoryRegister(){}
		int getValue() {return value;}
		void update(bool decision);

};

#endif
