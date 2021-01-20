#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *left,*right;
};

struct node* newnode(int data){
    struct node* nodenew = (struct node*)malloc(sizeof(struct node));
    nodenew->val = data;
}
int search(int A[],int start,int end,int key){
    for(int i=start;i<=end;i++){
        if(A[i]==key) return i;
    }
}
struct node* build(int inorder[], int postorder[], int start, int end,int *pindex){
    if(start>end) return NULL;
    struct node* Node = newnode(postorder[(*pindex)]);
    (*pindex)--;
    if(start==end) return Node;
    int iindex = search(inorder,start,end,Node->val);
    
    Node->right =  build(inorder,postorder,iindex+1,end, pindex);
    Node->left = build(inorder,postorder,start,iindex-1, pindex);
    return Node;
}

struct node* Buildtree(int inorder[],int postorder[],int n){
    int pindex=n-1;
    return build(inorder, postorder,0,n-1,&pindex);
}

void preorder(struct node* root){
    if(root==NULL) return;
        printf("%d ",root->val);
        preorder(root->left);
        preorder(root->right);
}
int main(){
    int n;
    printf("Enter no of nodes: ");
    scanf("%d",&n);
    int postorder[n],inorder[n];
    printf("\nEnter inorder: \n");
    for(int j=0;j<n;j++){
        scanf("%d",&inorder[j]);
    }
    printf("\nEnter postorder:\n");
    for(int j=0;j<n;j++){
        scanf("%d",&postorder[j]);
    }
   struct node* root = Buildtree(inorder,postorder,n);
   preorder(root);
}