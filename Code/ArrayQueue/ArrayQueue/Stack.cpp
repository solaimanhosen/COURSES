//#include <iostream>
//
//using namespace std;
//
//#define S_MAX 10000
//
//template <class T> class Stack
//{
//	T myStack[S_MAX];
//	int length;
//	int top;
//public:
//	Stack(){ top = -1; length = 0; }
//	void push(T data){
//		if (top == -1){
//			top = 0;
//			myStack[top] = data;
//			length++;
//			return;
//		}
//		top = (top + 1) % S_MAX;
//		myStack[top] = data;
//		length++;
//	}
//	void pop(){
//		top--;
//		length--;
//	}
//	T Top(){
//		return myStack[top];
//	}
//	bool empty(){
//		return (top == -1);
//	}
//	int size(){ return length; }
//};
//
//int main()
//{
//	Stack<int>s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	while (!s.empty()){
//		cout << s.Top() << endl;
//		s.pop();
//	}
//
//
//	return 0;
//}