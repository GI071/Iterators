#include <iostream>
using namespace std;

class ArrayIterator {
	public:
	int* array;
	int size;
	int current;
	
	ArrayIterator(int* array, int size) {
		this->array = array;
		this->size = size;
		current = 0;
	}
	
	int& operator[] (const int& n) {
			if (n >= size || n < 0) {
				cout<<"out of index";
			}
			return array[n];
	}
	
	auto begin(){return &array[current];}
	int* end(){return &array[size];}
	
	
	int operator++(){return current++;}
	int operator--(){return current--;}
	bool over() { return current >= size; }
	int value() { return array[current]; }
	
	void next() {
			if ( over() ) {
                return;
            }
			current++;
			return;
    }
	
	void push_backElement(int element) {
		array[size] = element;
		size += 1;
	}
	
};

int main() {
    static int size = 10;
	static int array[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    ArrayIterator seq(array, size);
	
	
	auto it = seq.begin();
	while (it != seq.end()) {
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	
	seq.push_backElement(110);
	seq.push_backElement(120);
	seq.push_backElement(130);
	
	while (!seq.over()) {
		cout<<seq.value()<<" "; 
		seq.next();
	}

    return 0;
}