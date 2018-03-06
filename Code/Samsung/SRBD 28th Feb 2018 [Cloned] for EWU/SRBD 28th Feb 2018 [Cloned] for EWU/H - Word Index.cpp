#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>

using namespace std;

#define MAX 35999

//class queue
//{
//	string myQueue[MAX];
//	int f;
//	int r;
//	int length;
//public:
//	queue(){ f = r = -1; length = 0; }
//	void push(string str)
//	{
//		if (f == -1 && r == -1){
//			f = r = 0;
//			myQueue[r] = str;
//			length++;
//			return;
//		}
//		r = (r + 1) % MAX;
//		myQueue[r] = str;
//		length++;
//	}
//	int size()
//	{
//		return length;
//	}
//	void pop()
//	{
//		if (f == r){
//			f = r = -1;
//			length--;
//			return;
//		}
//		f = (f + 1) % MAX;
//		length--;
//	}
//	string front()
//	{
//		return myQueue[f];
//	}
//	bool empty()
//	{
//		if (f == -1 && r == -1)
//			return true;
//		return false;
//	}
//	void clear()
//	{
//		f = r = -1;
//	}
//};

bool valid(string str)
{
	for (int i = 0; i < str.length() -1 ; i++){
		if (str[i] >= str[i + 1])
			return false;
	}
	return true;
}

int main() {
	//queue q;
	
	int count;
	string str;

	while ( cin >> str ){
		if (!valid(str)){
			cout << "0" << endl;
			continue;
		}
		count = 0;
		queue<string>q;
		q.push("start");
		while (true){
			string test = q.front();
			q.pop();
			if (test == str){
				break;
			}
			count++;
			if (test == "start"){
				for (char ch = 'a'; ch <= 'z'; ch++){
					char s[2];
					s[0] = ch;
					s[1] = 0;
					q.push(s);
				}
			}
			else{
				char next = test[test.length()-1];
				for (char ch = next + 1; ch <= 'z'; ch++){
					q.push(test + ch);
				}
			}
			
		}
		cout << count << endl;
	}
	return 0;
}