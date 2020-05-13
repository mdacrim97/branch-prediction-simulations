#include "smithCounter.h"
using namespace std;

//Mario Alex Crim

SmithCounter::SmithCounter(){
    count = 0;
}

void SmithCounter::increment(){
    if(count <3) count++;
}

void SmithCounter::decrement(){
    if(count > 0) count--;
}

int SmithCounter::getCount(){
	return count;
}

bool SmithCounter::prediction(){
	return count >= 2;
}
