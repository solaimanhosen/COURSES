#include<stdio.h>


typedef struct
{
    int data;
    struct node* next;
} list;

list *head;
list *curr;
list *tail;


void create(int data)
{
    curr = (list*)malloc(sizeof(list));
    curr->data = data;
    curr->next = NULL;

    if(head == NULL)
    {
        head = curr;
        tail = curr;
    }
    else
    {
        tail->next = curr;
        tail = curr;
    }
}

void insertAtBeginning(int data)
{
    curr = (list*)malloc(sizeof(list));
    curr->data = data;
    curr->next = NULL;

    if(head == NULL){
        head = curr;
        tail = curr;
    }
    else
    {
        list* temp;
        temp = head;
        curr->next = temp;
        head = curr;
    }
}

void insertAtMiddle(int data, int pos)
{
    int i;
    if(head == NULL){
        if(pos == 1)
            insertAtBeginning(data);
        else
            printf("Segmentatin Error\n");
    }
    else
    {
        int size = 1;
        curr = head;
        while(curr->next != NULL)
        {
            curr = curr->next;
            size++;
        }

        if(pos == 1)
            insertAtBeginning(data);
        else if(pos == size+1)
            create(data);
        else if(pos <= size){
            curr = (list*)malloc(sizeof(list));
            curr->data = data;
            curr->next = NULL;

            list* temp;
            list* temp1;
            temp = head;
            for(i = 1; i < pos; i++){
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = curr;
            curr->next = temp;
        }
        else
        {
            printf("Segmentation Error\n");
        }

    }
}

void display()
{
    curr = head;
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void reverseList()
{
    curr = head;
    tail = head;
    list* prev = NULL;
    list* next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{
    int data, choice, pos;

    while(1)
    {
        printf("(1) Insert A node\n");
        printf("(2) Insert A node at beginning\n");
        printf("(3) Insert A node at Middle\n");
        printf("(4) Reverse The List\n");

        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        if(choice == 1){
            printf("Enter a Number: ");
            scanf("%d",&data);
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
