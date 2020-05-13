#ifndef CRIM_SMITH_COUNTER_H
#define CRIM_SMITH_COUNTER_H

//Mario Alex Crim

using namespace std;

class SmithCounter {
	private:
		int count;
	public:
		explicit SmithCounter();
		~SmithCounter(){}
		void increment();
		void decrement();
		int getCount();
		bool prediction();
};


#endif
