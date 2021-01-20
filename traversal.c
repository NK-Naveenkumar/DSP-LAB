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
void preorder(struct node* root){
    if(root==NULL) return;
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
}
 
void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node* root,int n){
    struct node* s1[n];
    struct node* s2[n];
    int top1=-1,top2=-1;
    s1[++top1]=root;
    
    struct node* Node;
    while(top1>=0){
        Node=s1[top1];
        s1[top1--]=NULL;
       // printf("%d t1\n",top1);
       // printf("\n**%d\n",Node->data);
        s2[++top2]=Node;
        //printf("\ns2 %d",s2[top2]->data);
        if(Node->left!=NULL)
          s1[++top1]=Node->left;
        if(Node->right!=NULL)
          s1[++top1]=Node->right;
    }
    /*for(int i=top2;i>=0;i--){
        printf("%d ",s2[i]->data);
    }*/
    while(top2!=-1){
        printf("%d ",(s2[top2])->data);
        top2--;
    }
    
}


int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    scanf("%d",&A[0]);
    struct node* root=NULL,*temp;
    root = createbst(root,A[0]);
    temp=root;
    for(int i=1;i<n;i++){
        scanf("%d",&A[i]);
        temp = createbst(root,A[i]);
    }
    //printf("%d",maxdepth(root));
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root,n);
    return 0;
}
