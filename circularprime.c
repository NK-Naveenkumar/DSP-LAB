#include <stdio.h>
#include<stdbool.h>
#include<math.h>


bool checkprime(int);
int count=0;
bool circularprime(int);

int main()
{
    int val;
    printf("Enter the number to check circular prime or not: ");
    scanf("%d",&val);
    if(val<=0){
        printf("-1");
        return -1;
    }
    if(val==1){
        printf("0");
        return 0;
    }
    if(circularprime(val)){
        printf("1");
        return 1;
    }
    else printf("0");
    return 0;
}

bool checkprime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0) return false; //if divisible not prime so immediately return false
    }
    return true; // if it comes out of the loop then prime
}

bool circularprime(int n){
    int rem,quot;
    int Actnum=n;
    for(int temp=n;temp!=0;temp/=10) count++;
    while(checkprime(n)){
        rem=n%10; //gives last digit
        quot=n/10; // gives the remaining number other than last digit
        /*to get all combination take remainder and multiply it with 10 to power no of digits-1 and add quotient 
        so the last digit will shift to first digit and remaining three will also get shifted. 
        Ex:on first loop 3779 will become 9377 then 7937 then 7793 and so on.*/
        n = (pow(10,count-1)*rem)+quot;
        if (n==Actnum) return true; // After all the combinations are over it will return to Actual number then it is circular prime
    }
    return false; // if it comes out of loop it is not a circular prime
}