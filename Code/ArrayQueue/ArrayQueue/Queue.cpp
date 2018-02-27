#include <iostream>

using namespace std;

#define q_size 100000

template<class T> class queue
{
	T myqueue[q_size];
	int front, rear;
	int length;
public:
	queue(){
		front = rear = -1;
		length = 0;
	}
	void push(T data){
		if (front == -1 && rear == -1){
			front = rear = 0;
			myqueue[rear] = data;
			length++;
			return;
		}
		rear = (rear + 1) % q_size;
		myqueue[rear] = data;
		length++;
	}
	void pop(){
		if (front == rear){
			front = rear = -1;
			length--;
			return;
		}
		front = (front + 1) % q_size;
		length--;
	}
	T Front(){
		return myqueue[front];
	}
	bool empty(){
		if (front == -1 && rear == -1)
			return true;
		return false;
	}
	int size(){
		return length;
	}
	void clear(){
		front = rear = -1;
	}
};

struct point
{
	int x;
	int y;
};

int main()
{
	queue<point>q;

	q.push({ 2, 3 });
	q.push({ 2, 3 });
	q.push({ 2, 3 });
	q.push({ 2, 3 });
	q.push({ 2, 3 });

	while (!q.empty()){
		point temp;
		temp = q.Front();
		q.pop();
		cout << temp.x << " " << temp.y << endl;
	}


	return 0;
}