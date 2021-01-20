//stack implementation using linked list 
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    };
struct node* head;

void push(){
    int x;
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) printf("cannot insert element");
    else{
        printf("enter the value:\n");
        scanf("%d",&x);
        if(head==NULL){
            ptr->data = x;
            ptr->next=NULL;
            head=ptr;
        }
        else{
            ptr->data = x;
            ptr->next=head;
            head=ptr;
        }
    }
}
void pop(){
    int x;
    struct node* ptr;
    if(head==NULL) printf("stack is empty\n");
    else{
        x=head->data;
        ptr=head;
        head = head->next;
        free(ptr);
        
    }
}
void display(){
    struct node* ptr=head;
    if(ptr==NULL) printf("stack is empty");
    else{
        printf("elements in the stack are:\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main(void) {
	int operation=0;
	while(operation!=4){
	    printf("enter your operation: 1.push  2.pop  3.display elements  4.no operation Exit\n");
	    scanf("%d",&operation);
	    if(operation==1) push();
	    else if(operation==2) pop();
	    else if(operation==3) display();
	    else if(operation==4) printf("exited\n");
	    else printf("enter valid operation");
	
	}
	
	return 0;
}


