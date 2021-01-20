//queue implementation using array
#include <stdio.h>
int Arr[10],front=-1,rear=-1,n;
void enqueue()
{
    int x;
    printf("enter the value to enqueue:\n");
        scanf("%d",&x); 
    if(rear+1==n) printf("Queue is full\n");
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else{
        rear=rear+1;
    }
    Arr[rear]=x;
}
void dequeue(){
    int x;
    if (front==-1 || front>rear) printf("queue is empty\n");
    else{
        x=Arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else front=front+1;
        printf("value %d deleted from queue",x);
    }
}
void display(){
    if(front==-1) printf("queue is empty");
    else{
        printf("elements in the queue are:\n");
        while(front<=rear){
            printf("%d\n",Arr[front]);
            front++;
        }
    }
}

int main(void) {
	int operation=0;
	printf("enter the size of queue:<=10\n");
	scanf("%d",&n);
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

