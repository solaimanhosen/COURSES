#include <bits/stdc++.h>
using namespace std;

struct ClassTest
{
    int mark;
    struct ClassTest* next;
};

struct student
{
    string id;
    string name;
    struct ClassTest* CT;
    struct student* next;
};



struct student* head;
struct student* curr;
struct student* tail;

int main()
{
    int std_num, ct_num, choice, mark;
    string id, name;

    while(1)
    {
        printf("(1) Insert A Student Information\n");
        printf("(2) Insert A node at beginning\n");
        printf("(3) Insert A node at Middle\n");
        printf("(4) Reverse The List\n");

        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        if(choice == 1){
            printf("Enter Student Name: ");
            cin >> name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Attended Quiz Number: ";
            cin >> ct_num;

            create(data);
        }
        if(choice == 2){
            printf("Enter a Number: ");
            scanf("%d",&data);
            insertAtBeginning(data);
        }
        if(choice == 3){
            printf("Enter a Number: ");
            scanf("%d",&data);
            printf("Enter Index: ");
            scanf("%d", &pos);
            insertAtMiddle(data, pos);
        }
        if(choice == 4)
            reverseList();

        display();
    }



    return 0;
}
