#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 

int stack[20];
int top=-1;

void push(int x){
    stack[++top]=x;
}
int pop(){
    return stack[top--];
}
int evaluatePostfix(char* expr) 
{ 

	for (int i = 0; expr[i]; ++i) 
	{  
		if ( isdigit(expr[i]) ) {
			push(expr[i] - '0');
		}
			

		else
		{ 
			int val1 = pop(); 
			int val2 = pop(); 
			
			if (expr[i] == '+') push( val2 + val1);
			else if(expr[i] == '-') push( val2 - val1);
			else if(expr[i] == '*') push( val2 * val1);
			else if(expr[i] == '/') push(val2/val1);
			
		} 
	} 
	
	return pop();
} 

int main() 
{ 
	char expr[] = "231*+9-"; 
	printf ("for given input %s postfix evaluation: %d", expr,evaluatePostfix(expr)); 
	return 0; 
} 

