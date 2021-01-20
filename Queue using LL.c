//queue implementation using linked list
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front;
struct node* rear;
void enqueue()  
{  
    struct node *ptr;  
    int val;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("cannot insert the value\n");  
        return;  
    }  
    else  
    {   
        printf("Enter value to insert:\n");  
        scanf("%d",&val);  
        ptr -> data = val;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void dequeue()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("queue is empty\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf(" queue is empty\n");  
    }  
    else  
    {   printf("elements in the queue:\n");  
        while(ptr != NULL)   
        {  
            printf("%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  
int main(void) {
	int operation=0;
	while(operation!=4){
	    printf("Enter your operation: 1.enqueue  2.dequeue  3.diaplay elements  4.no operation\n");
	    scanf("%d",&operation);
	    if(operation==1) enqueue();
	    else if(operation==2) dequeue();
	    else if(operation==3) display();
	    else if(operation==4) printf("exit\n");
	    else printf("enter valid operation\n");
	}
	return 0;
}

