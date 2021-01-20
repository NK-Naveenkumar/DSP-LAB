/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

REVERSE FUNCTION FOR A LINKED LIST CODE
*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void Addbeg(struct node** head_ref,int key){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data=key;
        new_node->next=*head_ref;
        *head_ref = new_node;
    
}
void Addend(struct node** head_ref,int key){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head_ref;
    if(*head_ref == NULL){
        new_node->data=key;
        new_node->next=NULL;
        *head_ref = new_node;
    }
    else{
        while(temp->next!=NULL) temp=temp->next;
        new_node->data = key;
        new_node->next = NULL;
        temp->next=new_node;
    }
}



void Delete(struct node** head_ref, int key){
    struct node* temp = *head_ref,*prev;
    if(temp!=NULL && temp->data==key){
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL) return;
    
    prev->next=temp->next;
    free(temp);
}

void Display(struct node* headr){
    struct node* temp =headr;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void search(struct node** head_ref, int key){
    struct node* temp = *head_ref;
    int flag=0;
    while(temp!=NULL){
        if(temp->data == key){
         printf("\nsearch successful and element found\n");
         flag=1;   
         return;
        }
        
        temp = temp->next;
    } 
    if(flag==0) printf("\nelement not found\n");
}
void reverse(struct node* head_ref){
    struct node *prev,*curr;
    if(head_ref!=NULL){
         prev=head_ref;
         curr = head_ref->next;
         head_ref=head_ref->next;
         prev->next=NULL;
        while(head_ref!=NULL){
            head_ref=head_ref->next;
            curr->next=prev;
            prev=curr;
            curr=head_ref;
        }
    head_ref = prev;
    Display(head_ref);
    }
    else printf("\nlist is empty\n");
}

int main()
{   
    struct node* head=NULL;
    int choice=0,key;
    while(choice!=6){
        printf("enter your choice:\n1.Add element at start\n2.add element at end\n3.Delete given element if present in list\n4.Display elements in the list\n5.Search the given element\n6.reverse linked list\n7.Exiting\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter the value to insert: ");
                    scanf("%d",&key);
                    Addbeg(&head,key);
                    
                    break;
            case 2: printf("enter the value to insert: ");
                    scanf("%d",&key);
                    Addend(&head,key);
                    break;
            case 3: printf("enter the value to delete: ");
                    scanf("%d",&key);
                    Delete(&head,key);
                    break;
            case 4: printf("\nDisplaying elements: \n");
                    Display(head);
                    break;
            case 5: printf("\nenter the value to search: ");
                    scanf("%d",&key);
                    search(&head,key);
                    break;
            case 6: printf("\nReversing the linked list and reveresed list is:\n");
                    reverse(head);
                    break;
            case 7: printf("\nExiting");
            default: printf("\nEnter valid operation\n");
          
            
        }
    }
    return 0;
}
