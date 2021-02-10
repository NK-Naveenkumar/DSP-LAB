
#include <stdio.h>
void selectionsort(int A[],int n){
    int min;
    for(int i=0;i<n;i++){
        min= i;
        for(int j=i+1;j<n;j++)
           if(A[j]<A[min]) min=j;
        
        int temp=A[i];
        A[i]=A[min];
        A[min]= temp;
        
    }
}
void display(int A[],int n){
    printf("\ndisplaying elements:\n");
    for(int i=0;i<n;i++){
        printf("%d\n",A[i]);
    }
}

int main()
{
    int n;
    printf("enter no of elements: ");
    scanf("%d",&n);
    int A[n];
    printf("enter elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    selectionsort(A,n);
    printf("\nAfter sorting:");
    display(A,n);

    return 0;
}
