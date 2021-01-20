//stack implementation using array
#include <stdio.h>
int Arr[10],n, top=-1;
void push(){
    int x;
    if(top == n) printf("stack is full\n");
    else
   { printf("enter the value to push:\n");
     scanf("%d",&x);
      top=top+1;
    Arr[top]=x;
   }
}
void pop()
{
    int x;
    if(top==-1) printf("Stack is empty");
    else
    {
     x=Arr[top];
     printf("value removed from stack: %d \n",val);
     top=top-1;
    }
}

void display()
{
    if(top==-1) printf("stack is empty");
    else{
        printf("elements in the stack:\n");
        for(int i=top;i>-1;i--)
        printf("%d \n",Arr[i]);
        
    }
}
int main(void) {
	// your code goes here
	int operation =0;
	printf("no of elements in the Stack <= 10:\n");
	scanf("%d",&n);
	while(operation!=4){
	printf("enter your operation : 1.push  2.pop  3.display  4.no operation exit :\n");
	scanf("%d",&operation);
	if(operation==1)  push();
	else if(operation==2) pop();
	else if(operation==3)  display();
	else if(operation==4) printf("exiting\n");
	else printf("enter valid choice");
	}
	
	
	
	return 0;
}

