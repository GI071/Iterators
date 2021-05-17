#include <iostream>
using namespace std;

class GeoProgIterator {
    public:
		static long long int first;
        static long long int current;
		static long long int step;
		static long long int elements;
		long long int counter = 0;

        GeoProgIterator() {}

        void next() {
			
			if ( over() ) {
                return;
            }
            current *= step;
			counter += 1;
        }

        void operator++() { next(); }

        bool over() { return counter > elements; }

        int value() { return current; }

        int operator*() { return value(); }
};

long long int GeoProgIterator::first = 5;
long long int GeoProgIterator::current = first;
long long int GeoProgIterator::elements = 42;
long long int GeoProgIterator::step = 2;

int main() {
	GeoProgIterator seq;

    for ( ; !seq.over(); seq.next() ) {
        cout << seq.value() <<" ";
    }

    return 0;
}

