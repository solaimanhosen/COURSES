#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(){next = NULL;}
};

class Queue
{
    Node* head, *curr, *tail, *temp;
public:
    void Push(int data)
    {
        temp = new Node;
        temp->data = data;
        if(tail == NULL){
            head = tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
	void Pop()
    {
        Node* temp;
        temp = head;
        head = head->next;
        delete temp;
    }
    int Front()
    {
        return head->data;
    }
    bool Empty()
    {
        if(head == NULL)
            return true;
        return false;
    }
    int Size()
    {
        //return length;
    }

};

int main()
{
    Queue q;
    q.Push(5);
    q.Push(10);
    q.Pop();
	q.Push(7);
    q.Push(5);
    while(!q.Empty()){
        cout << q.Front() <<  " ";
        q.Pop();
    }
    cout << endl;
    q.Push(2);
    q.Push(9);
    q.Push(0);
    while(!q.Empty()){
        cout << q.Front() <<  " ";
        q.Pop();
    }
    cout << endl;




    //cout << head->data << " " << tail->data << endl;

    //temp = new Node;
    //temp->data = 10;



    //cout << head->data << " " << tail->data << endl;





    return 0;
}
