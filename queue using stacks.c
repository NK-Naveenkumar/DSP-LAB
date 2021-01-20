#include <stdio.h> //preprocessing includes standard i/o header file
#define N 10 //defining the max no of elements in the queue

int S1[N],S2[N],top1=-1,top2=-1,count=0;

void push1(int x){ // function to insert element to stack1
    if(top1 == N-1) printf("Queue is full\n"); //overflow
    else{ 
        top1++;
        S1[top1]=x;
    }
}
int pop1(){ //function to remove element to stack1
    return S1[top1--];
}
void push2(int x){ //function to insert element to stack2
    if(top1 == N-1) printf("Queue is full\n"); //overflow
    else{
        top2++;
        S2[top2]=x;
    }
}
int pop2(){  //function to remove element from stack2
    return S2[top2--];
}

void enqueue(int x){   //function to insert element into the queue
    push1(x); // inserting element to stack 1
    count++;
}
void dequeue(){ //function to remove element from queue
    if(top1==-1 && top2==-1) printf("Queue is empty\n");
    else{
      for(int i=0;i<count;i++){
          push2(pop1());
        }
       printf("Item removed: %d \n", pop2());
       count--;
       for(int i=0;i<count;i++){
        push1(pop2());
        }
    }
}
void display(){ // To display all the elements in the queue
    printf("Elements in the queue are:\n");
    for(int i=0;i<=top1;i++) printf("%d\n",S1[i]);
}

int main() //start of execution
{   
    int choice = 0;
    int x;
    while(choice!=4){
        printf("Enter the operation you want to perform: 1.enqueue\t2.dequeue\t3.display elements\t4.Exit\n");
        scanf("%d",&choice);
    
        if(choice==1){
            printf("enter the element you want to enqueue:\n");
            scanf("%d",&x);
            enqueue(x);
            }
        else if(choice==2) dequeue();
        else if(choice ==3) display();
        else if(choice==4) printf("exiting\n");
        else printf("enter valid choice\n");
    }
    return 0;
}
