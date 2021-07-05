#include <iostream>
using namespace std;

template <typename T>			//using templates for generic data types
class queue {					//queue class implementation
	int size, findex, rindex, n;		//variables for performing operations on queue
	T* data;							//pointer for array of generic data type
public:
	queue(int s = 10) {				//getting default size as 10	
		size = s+1;					//setting size to s+1,extra space for better functioning
		findex = rindex = n = 0;	//setting front index,rear index and no. of values to zero
		data = new T[size];			//pointing data pointer to array of size(s+1)
	}
	queue(const queue<T>& q) {		//copy constructor
		size = q.size;				//setting size equal to other queue's size
		findex = q.findex;			//setting findex equal to other queue's findex
		rindex = q.rindex;			//setting rindex equal to other queue's rindex
		n = q.n;					//setting no. of values equal to other queue's no. of values
		data = new T[size];			//pointing data pointer to array of size(s+1)
		for (int i = 0; i < size; i++) {	//copying data
			data[i] = q.data[i];			//of every index using loop
		}
	}
	void operator = (const queue<T>& q) {
		delete[] data;					//deleting previous memory pointed by data
		size = q.size;					//same
		findex = q.findex;				//operation
		rindex = q.rindex;				//as
		data = new T[size];				//performed
		for (int i = 0; i < size; i++) {//in
			data[i] = q.data[i];		//copy constructor
		}
	}
	void push_front(const T& val) {		//function for pushing data from front of queue
		if (full()) {					//if queue is full
			throw "Cannot add data, Queue is full!\n";		//then throwing exception
		}
		data[findex] = val;				//else pushing value at front index
		findex = (findex - 1) % size;	//moving findex to previous index
		if (findex < 0) {				//if findex is less than zero
			findex = findex + size;		//then setting to equal to required positive index (as in circular queue)
		}
		n++;							//incrementing no. of elements
	}
	void push_rear(const T& val) {		//function for pushing data from rear of queue
		if (full()) {					//if queue is full
			throw "Cannot add data, Queue is full!\n";		//then throwing exception
		}
		rindex = (rindex + 1) % size;		//moving rindex to next index
		data[rindex] = val;					//pushing value at rear index
		n++;							//incrementing no. of elements
	}
	void pop_front() {					//function for removing data from rear of queue
		if (empty()) {					//if queue is empty
			throw "Cannot remove data, Queue is empty!\n";		//then throwing exception
		}
		findex = (findex + 1) % size;		//else moving findex to next index
		n--;							//decrementing no. of elements
	}
	void pop_rear() {
		if (empty()) {					//if queue is empty
			throw "Cannot remove data, Queue is empty!\n";		//then throwing exception
		}
		rindex = (rindex - 1) % size;	//moving rindex to previous index
		n--;							//decrementing no. of elements
	}
	T front() {						//function for getting value at front of queue
		if (empty()) {					//if queue is empty
			throw "Cannot get data, Queue is empty!\n";		//then throwing exception
		}
		return data[(findex + 1) % size];		//returning data at next position of findex
	}
	T rear() {						//function for getting value at rear of queue
		if (empty()) {					//if queue is empty
			throw "Cannot get data, Queue is empty!\n";		//then throwing exception
		}
		return data[rindex];		//returning data at rindex
	}
	bool full() {				//function for checking if queue is full or not
		return ((rindex + 1) % size) == findex;		//true if next index from rindex is findex
	}
	bool empty() {				//function for checking if queue is empty or not		
		return (n == 0);		//true if n=0
	}
	void makeempty() {			//function for making queue empty
		findex = rindex = n = 0;	//setting findex,rindex and n equal to zero
	}
	~queue() {
		delete[] data;			//deleting memory allocated in destructor
	}
};

template <typename T>
void display(queue<T> q) {			//function for displaying data in queue
	T val;							//variable for getting data
	while (!q.empty()) {			//getting data
		val = q.front();			//and displaying it while
		q.pop_front();				//queue is not
		cout << val << "\t";		//empty
	}
	cout << endl;
}

int main()							//client code
{
	queue<int> q(5);				//declaring queue of integer type of size 5
	q.push_front(2);				//pushing 2 from front
	display(q);						//displaying data in queue
	q.push_front(1);				//pushing 1 from front
	display(q);						//displaying data in queue
	q.push_rear(0);					//pushing 0 from rear
	display(q);						//displaying data in queue
	q.push_rear(6);					//pushing 6 from rear
	display(q);						//displaying data in queue
	q.pop_front();					//popping value from front
	display(q);						//displaying data in queue
	q.pop_rear();					//popping value from rear
	display(q);						//displaying data in queue
	q.pop_front();					//popping value from front
	display(q);						//displaying data in queue
	return 0;
}