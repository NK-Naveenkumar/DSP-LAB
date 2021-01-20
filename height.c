#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int x){
    struct node* newnode= (struct node*) malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* createbst(struct node* Node, int val){
    if(Node==NULL) return createNode(val);
    if(val < Node->data) Node->left=createbst(Node->left,val);
    else if(val > Node->data) Node->right=createbst(Node->right,val);
    return Node;
}

int maxdepth(struct node* Node){
    if( Node == NULL)
		return 0;
	else
	{
		int leftDepth = maxdepth(Node->left);
		int rightDepth = maxdepth(Node->right);
		
		if(leftDepth > rightDepth)
			return(leftDepth+1);
		else return (rightDepth+1);
	}
}


int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    scanf("%d",&A[0]);
    if(n<=1){
        printf("%d",n);
        return 0;
    }
    struct node* root=NULL,*temp;
    root = createbst(root,A[0]);
    temp=root;
    for(int i=1;i<n;i++){
        scanf("%d",&A[i]);
        temp = createbst(root,A[i]);
    }
    printf("%d",maxdepth(root));

    return 0;
}
