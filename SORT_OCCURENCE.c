/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

CODE IMPLEMENTATION OF SORTING A ARRAY AND FIND START AND END OCCURRENCE OF ELEMENT SORTED LIST 
*******************************************************************************/
#include <stdio.h>
// for swapping elements in array
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// function to fix the position of pivot
int partition(int A[],int p,int r){
    int x=A[r];
    int i=p-1;
    //int temp;
    for(int j=p;j<r;j++){
        if(A[j]<=x){ 
           i=i+1;
           swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}

// recursive function to divide and implement Quicksort
void Quicksort(int A[],int p,int r){
    if(p<r){
        int q=partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
    
}

// function to find the occurence of key value
void findoccurence(int A[],int key,int n){
    int k=0,count = 0;
    for(int i=0;i<n;i++){
        if(A[i]==key && count==0){
            k = i;
            count++;
        }
        else if(A[i]==key && count!=0) count++;
    }
    printf("\nstarting occurence: %d\nEnding occurence: %d\n",k+1,k+count);
}

// Execution starts from main
int main()
{   int n,key;
    printf("enter the no of elements in array: ");
    scanf("%d",&n);
    int A[n];
    printf("enter the elements in the array:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);
    Quicksort(A,0,n-1); // function call for sorting
    printf("sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d  ",A[i]);
    }
    printf("\nenter key value to search occurence in sorted array: ");
     scanf("%d",&key);
    findoccurence(A,key,n); //function call to find and print occurences
    return 0;
}
