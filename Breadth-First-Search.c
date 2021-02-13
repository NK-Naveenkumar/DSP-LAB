#include <stdio.h>
#include <stdbool.h>
#define N 10
int Graphnum; // number of graphs to be solved
// Queue to implement BFS and Path to store the BFS path
int queue[N],path[N]; 
int front = -1,rear=-1; //front and rear to implement queue

// function to insert value in the queue
void enqueue(int val){
    if(front ==-1 ){
        front = front +1;
        rear = rear+1;
        queue[rear] = val;
        //printf("%d", queue[rear]);
        return;
    }
    rear = rear+1;
    queue[rear] = val;
    //printf("%d",queue[rear]);
    return;
}

// function to delete value from the queue
int dequeue(){
    int imd=queue[front];
    front=front+1;
    return imd;
}

// function to find if the queue is empty
int isempty(){
    //printf("%d %d",front,rear);
    if(front>rear) return 0;
    else return 1;
    
}

// function to search if the value is there in the queue or not
int search_Q(int key){
    int i=front;
    while(i<=rear){
        if(queue[i]==key) return 0;
        i++;
    }
    return 1;
}

// fundtion to search if the value is present in path array
int search_path(int key,int n){
    for(int i=0;i<n;i++) if(path[i]==key) return 0;
    return 1;
}

// function to implement Breadth-First-Search
void BFS(int graph[N][N],int k,int n){
    enqueue(k);
    int curr,m=0;
   // printf("%d",m);
    while(isempty()!=0){
    curr=dequeue();
    //printf("%d",curr);
    path[m] = curr;
    m++;
    for(int i=0;i<n;i++){
        if(graph[curr][i]==1 && search_Q(i)==1 && search_path(i,n)==1){
            enqueue(i);
        }
    }
    if(Graphnum==1) for(int i=0;i<m;i++) printf("%d ",path[i]);
    if(Graphnum==2) for(int i=0;i<m;i++) printf("%d ",path[i]+1);
    printf("\n");
    }
}

//main
int main()
{   int select =3;
    while(select!=0){
        front = -1;
        rear = -1;
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
    printf("BFS along with every iteration:\n");
    BFS(graph1,0,5);
    }
    else if(Graphnum==2){
    int graph2[6][6] = {{0,1,0,1,0,0},   
                       {1,0,1,0,1,0},
                       {0,1,0,0,0,0},
                       {1,0,0,0,0,0},
                       {0,1,0,0,0,1},
                       {0,0,0,0,1,0}};
    /* int graph2[9][9] = {{0,1,0,1,0,0,0,0,1},
                           {1,0,0,0,0,0,0,1,0},
                           {0,0,0,1,0,1,0,1,0},
                           {1,0,1,0,1,0,0,0,0},
                           {0,0,0,1,0,0,0,0,1},
                           {0,0,1,0,0,0,1,0,0},
                           {0,0,0,0,0,1,0,0,0},
                           {0,1,1,0,0,0,0,0,0},
                           {1,0,0,0,1,0,0,0,0}}; */
    printf("BFS along with every iteration:\n");
    BFS(graph2,0,6);
    }
    else if(Graphnum==0){ 
        printf("Exited");
        break;
    }
    }
    return 0;
}


