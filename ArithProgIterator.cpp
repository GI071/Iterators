#include <iostream>
using namespace std;

class ArithProgIterator {
    public:
        static int current;
		static int step;
		static int elements;
		static int first;
		int counter = 0;

        Iterator() {}

        void next() {
			
			if ( over() ) {
                return;
            }
            current += step;
			counter += 1;
        }

        void operator++() { next(); }

        bool over() { return counter > elements; }

        int value() { return current; }

        int operator*() { return value(); }
};

int ArithProgIterator::first = 5;
int ArithProgIterator::current = first;
int ArithProgIterator::elements = 42;
int ArithProgIterator::step = 2;

int main() {
	ArithProgIterator seq;

    for ( ; !seq.over(); seq.next() ) {
        cout << seq.value() << " ";
    }

    return 0;
}

