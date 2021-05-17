#include <iostream>
using namespace std;

class PrimeNumIterator {
    public:
		long long int number;
        static long long int current;
		static int counter;
		static int temp;

		PrimeNumIterator() {
			cout<<"enter the number:";
			cin>>number;
		}

		void next() {
			
			if ( over() ) {
                return;
            }
			
			label1: 
			current++; 
			counter ++;
			
			for ( int i = 2; i < current; i++) {
				if ( current % i == 0 ) {
					goto label1;
				}
			}
			
			counter += 1;
			return;
			
        }

		void operator++() { next(); }

		bool over() { return current > number; }
		
		int value() { return current; }
		
		int operator*() { return value(); }
		
};

long long int PrimeNumIterator::current=2;
int PrimeNumIterator::temp = 3;
int PrimeNumIterator::counter = 0;


int main() {
	PrimeNumIterator seq;

    for ( ; !seq.over(); seq.next() ) {
		cout << seq.value() <<" ";
    }

    return 0;
}

