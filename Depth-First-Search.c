#include <stdio.h>
#include <stdbool.h>
#define N 6
int Graphnum;
int stack[N],path[N];
int top=-1;
void stackpush(int val){
    top=top+1;
    stack[top]=val;
}
int stackpop(){
    int imd=stack[top];
    top = top-1;
    return imd;
}
int isempty(){
    //printf("%d",top);
    if(-1==top) return 0;
    else return 1;
    
}
int search_stack(int key){
    int i=0;
    if(top==-1) return 1;
    while(i<=top){
        if(stack[i]==key) return 0;
        i++;
    }
    return 1;
}
int search_path(int key){
    for(int i=0;i<5;i++) if(path[i]==key) return 0;
    return 1;
}
void DFS(int graph[N][N],int k,int n){
    stackpush(k);
    int curr,m=0;
   //printf("%d",(top));
    while(isempty()!=0){
    curr=stackpop();
   // printf("%d\n",curr);
    path[m] = curr;
    m++;
    for(int i=0;i<n;i++){
        if(graph[curr][i]==1 && search_stack(i)==1 && search_path(i)==1){
            stackpush(i);
        }
    }
    if(Graphnum==1) for(int i=0;i<m;i++) printf("%d ",path[i]);
    if(Graphnum==2) for(int i=0;i<m;i++) printf("%d ",path[i]+1);
    printf("\n");
    }
}

int main()
{   int select =3;
    while(select!=0){
        for(int i=0;i<N;i++){
            path[i] = 0;
        }
    printf("Enter your selection: graph1 or graph2 or 0 to exit: ");
    scanf("%d",&Graphnum);
    select=Graphnum;
    if(Graphnum==1){
    int graph1[5][5] = {{0,1,1,1,0},
                       {1,0,1,0,0},
                       {1,1,0,0,1},
                       {1,0,0,0,0},
                       {0,0,1,0,0}};
    printf("DFS along with every iteration:\n");
    DFS(graph1,0,5);
    }
    else if(Graphnum==2){
    int graph2[6][6] = {{0,1,0,1,0,0},
                       {1,0,1,0,1,0},
                       {0,1,0,0,0,0},
                       {1,0,0,0,0,0},
                       {0,1,0,0,0,1},
                       {0,0,0,0,1,0}};
    printf("DFS along with every iteration:\n");
    DFS(graph2,0,6);
    }
    else if(Graphnum==0) printf("Exited");
    }
    return 0;
}
