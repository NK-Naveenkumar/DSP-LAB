#include <stdio.h> //preprocessing includes standard i/o header file
#define N 10 //defining the max no of elements in the stack

int Q1[N],Q2[N],front1=-1,rear1=-1,front2=-1,rear2=-1,count=0;

void enqueue1(int x){
    if(rear1==N-1) printf("Stack is full");
    else{
       if(front1==-1 && rear1==-1){
          front1=0;
          rear1=0;
          Q1[rear1]=x;
       }
      else{
          rear1=rear1+1;
          Q1[rear1]=x;
      }
    }
}
int dequeue1(){
    int a;
    if(front1<=rear1){
      if(front1==rear1) {
      a=Q1[front1];
      front1=-1;
      rear1=-1;
      return a;
      }
      else
      return Q1[front1++];
    }
}
void enqueue2(int x){
    if(rear2==N-1) printf("Stack is full");
    else{
       if(front2==-1 && rear2==-1){
          front2=0;
          rear2=0;
          Q2[rear2]=x;
       }
      else{
          rear2=rear2+1;
          Q2[rear2]=x;
      }
    }
}
int dequeue2(){
   int a;
    if(front2<=rear2){
      if(front2==rear2) {
      a=Q2[front2];
      front2=-1;
      rear2=-1;
      return a;
      }
      else
      return Q2[front2++];
    }
    
}


void push(int x){
    enqueue1(x);
    count++;
}
void pop(){
    if(rear1==-1 && rear2==-1) printf("Stack is empty\n");
    else{
         for(int i=0;i<count-1;i++){
           enqueue2(dequeue1());
         }
         printf("Element removed is: %d\n",dequeue1());
         count--;
         for(int i=0;i<count;i++){
           enqueue1(dequeue2());
         }
    }
    
}
void display(){
    printf("Elements in the Stack are:\n");
    for(int i=front1;i<=rear1;i++){
        printf("%d\n",Q1[i]);
        
    }
}

int main() //start of execution
{   
    int choice = 0;
    int x;
    printf("stack size <=10\n");
    while(choice!=4){
        printf("Enter the operation you want to perform: 1.push\t2.pop\t3.display elements\t4.Exit\n");
        scanf("%d",&choice);
    
        if(choice==1){
            printf("enter the element you want to push:\n");
            scanf("%d",&x);
            push(x);
            }
        else if(choice==2) pop();
        else if(choice ==3) display();
        else if(choice==4) printf("exiting\n");
        else printf("enter valid choice\n");
    }
    return 0;
}
