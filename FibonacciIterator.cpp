#include <iostream>
#include <cmath>
using namespace std;

class FibonacciIterator {
    public:
		static long long int number;
        long long int current;
		static long long int elements;
		static int counter;
		static int temp1;
		static int temp2;

		FibonacciIterator() {}

		void next() {
			
			if ( over() ) {
                return;
            }
			if (counter == 1) {
				current = 1;
				counter += 1;
				return;
			}
			if (counter == 2) {
				current = 1;
				counter += 1;
				return;
			}
			if (counter == 3) {
				temp1 = current;
				current += 1;
				temp2 = current;
				counter += 1;
				return;
				
			}
			if (counter > 3) {
				current += temp1;
				temp1 = temp2;
				temp2 = current;
				counter += 1;
				return;
			}
        }

        void operator++() { next(); }

        bool over() { return counter > elements; }

        int value() { return current; }

        int operator*() { return value(); }
};

long long int FibonacciIterator::number = 10;
// long long int FibonacciIterator::current = 0;
long long int FibonacciIterator::elements = number;
int FibonacciIterator::temp1 = 0;
int FibonacciIterator::temp2 = 0;
int FibonacciIterator::counter = 1;


int main() {
	FibonacciIterator seq;

    for ( ; !seq.over(); seq.next() ) {
		cout << seq.value() <<" ";
    }

    return 0;
}

