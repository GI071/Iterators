#include <iostream>
#include <fstream>
using namespace std;

class FileIterator {
	public:
	char c;
	static int current;
	int length;
	fstream fileIter;
	
	FileIterator() {
		string filename;
		cout<<"enter file name: ";
		cin>>filename;
		fileIter.open(filename, ios::in | ios::out);
		if(!fileIter.is_open()) {
			cout<<"file not found"<<endl;
		}
		
		fileIter.seekg(fileIter.beg, fileIter.end);
		length = fileIter.tellg();
		// cout<<"length: "<<length<<" ";
		// cout<<"length: "<<fileIter.tellg()<<endl;
		fileIter.seekg(fileIter.beg);
	}
	
	char begin(){
		fileIter.seekg(0, fileIter.beg);
		return c;
	}
	char end(){
		fileIter.seekg(0, fileIter.end);
		return c;
	}
	
	bool over() { return current >= length; }
	
	auto value() { fileIter.get(c); return c; }
	
	char next() { current++; return c; }
	
	char get(char c) { fileIter.seekg(0, fileIter.cur); return c; }
	
	void push_backElement(char element) {
		fileIter.seekg(0, ios::end);
		fileIter.put(element);
		length += 1;
	}
	
	
	
};

int FileIterator::current=0;

int main() {
	FileIterator a;
	
	a.push_backElement('A');
	
	a.begin();
	while (!a.over()) {
		cout<<a.value();
		a.next();
	}

    return 0;
}