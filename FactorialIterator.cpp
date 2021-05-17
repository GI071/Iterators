#include <iostream>
#include <cmath>
using namespace std;

class GeoProgIterator {
    public:
		static long long int number;
		static long long int first;
        static long long int current;
		// static long long int step;
		static long long int elements;
		long long int counter = 1;

		GeoProgIterator() {}

        
		
		void next() {
			
			if ( over() ) {
                return;
            }
			counter += 1;
            current = current*counter;
        }

        void operator++() { next(); }

        bool over() { return counter > elements; }

        int value() { return current; }

        int operator*() { return value(); }
};

long long int GeoProgIterator::number = 5;
long long int GeoProgIterator::first = 1;
long long int GeoProgIterator::current = first;
long long int GeoProgIterator::elements = number;
// long long int GeoProgIterator::step = 2;

int main() {
	GeoProgIterator seq;

    for ( ; !seq.over(); seq.next() ) {
        cout << seq.value() <<" ";
    }

    return 0;
}

