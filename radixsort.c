#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* prev;
	struct node* next;
};
int get_Max(int A[],int n){
	int max = A[0];
	for(int i=0;i<n;i++){
		if(A[i]>max)
		max = A[i];
	}
	return max;
}
int count_Digits(int max){
	int x=0;
	while(max!=0){
		x++;
		max = max/10;		
	}
	return x;
}
struct node* create_Node(int val){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	newnode->prev= NULL;
	return newnode;
}
struct node* create_DList(int A[],int n){
	struct node* head = create_Node(A[0]) ;
	struct node* curr = head;
	for(int i=1;i<n;i++){
		struct node* newnode = create_Node(A[i]);
		curr->next = newnode;
		newnode->prev = curr;
		curr = newnode;
	}
	return head;
}
void display(struct node* x){
	while(x!=NULL){
		printf("%d ",x->data);
		x = x->next;
	}
}
void Radix_Sort(struct node *head,int digits)
{
	for(int i=1,j=1;j<=digits;i=i*10,j++)
	{
	struct node *x;
	struct node *y;
	y=head->next;
	while(y!=NULL)
	{
		int val=y->data;
		int x_yent=y->data/i;
		x_yent=x_yent%10;
		x=y->prev;
		int y_xare=x->data/i;
		y_xare=y_xare%10;
		while(x!=NULL && y_xare>x_yent)
		{
			(x->next)->data=x->data;
			x=x->prev;
			if(x!=NULL)
			{
			y_xare=x->data/i;
			y_xare=y_xare%10;
			}
		}
		if(x!=NULL) (x->next)->data=val;
		else head->data=val;
		y=y->next;
	}
    }
}
int main(){
	int n;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	if(n<=0){
	printf("INVALID INPUT");
	return 0;
    }
	int A[n];
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<n;i++) 
	   if(A[i]<0){
	    printf("INVALID INPUT");
	    return 0;
    }
    struct node* head = create_DList(A,n);
    int max = get_Max(A,n);
    //printf("%d\n",max);
    int digits = count_Digits(max);
    //printf("%d\n",digits);
    Radix_Sort(head,digits);
    display(head);
}