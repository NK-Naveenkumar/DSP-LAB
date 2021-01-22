#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include<math.h>
#include<stdbool.h>
#define N 50 
 
struct node 
{ 
	int data; 
	char symbol;
	int isValue;
	struct node *left, *right; 
}; 

struct node* newNode(int value, char symbol, int isValue) 
{  
    struct node* new = (struct node *) malloc( sizeof(struct node) );
    if(isValue == 1)
	{
		new->data = value;
		new->symbol = symbol;	
	}
    else
	{
		new->symbol = symbol; 
	}
	new->isValue = isValue;
	new->left = new->right = NULL; 
	return new; 
} 

bool isoperand(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == '^' || s == ')' )
	   return false;
	else	return true;
}

int getPriority(char x)
{
    switch(x)
    {
	    case '(':
	        return 0;
	    case ')':
	        return 0;
	    case '-':
	        return 1;
	    case '+':
	        return 1;
	    case '/':
	        return 2;
	    case '*':
	        return 2; 
	    case '^':
	        return 3;
    } 
}

bool isValidChar(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '(' || s == '0' || s == '1' || 
	   s == '2' || s == '3' || s == '4' || s == '5' || s == '6' || s == '7' || s == '8' || s == '9' ||  	   
	   s == ')' )
	   return true;
	else return false;
}
   
struct node* buildexptree(char s[],int n) 
{ 
	struct node* stN[50]; 
	char stC[50]; 
    struct node* t = (struct node *) malloc( sizeof(struct node) );
    struct node* t1 = (struct node *) malloc( sizeof(struct node) );
    struct node* t2 = (struct node *) malloc( sizeof(struct node) );
    int i;
    int value, isLastDigit = 0;
    int stC_top = -1,stN_top = -1;
	for (i = 0; i < n; i++) 
	{ 
		if (s[i] == '(') { 
			isLastDigit = 0;
			stC_top++;
			stC[stC_top] = s[i];
		} 
		else if (isoperand(s[i])) 
		{   
			value = s[i] - '0';
			
			if(isLastDigit == 1) 
			{
				stN[stN_top]->data = stN[stN_top]->data *10 + value;
			}
			else
			{
				t = newNode(value,s[i],1); 
				stN_top++;
				stN[stN_top] = t; 
			} 
			isLastDigit = 1;
		} 
		else if (getPriority(s[i]) > 0) 
		{   
			isLastDigit = 0;
				while ( 
				stC_top != -1 && stC[stC_top] != '('
				&& ((s[i] != '^' && getPriority(stC[stC_top]) >= getPriority(s[i])) 
					|| (s[i] == '^'	&& getPriority(stC[stC_top]) > getPriority(s[i])))) 
			{ 
				t = newNode(0,stC[stC_top],0);  
				stC[stC_top] = '\0';
				stC_top--;

				t1 = stN[stN_top];  
				stN[stN_top] = '\0';
				stN_top--;

				t2 = stN[stN_top];  
				stN[stN_top] = '\0';
				stN_top--;
				t->left = t2; 
				t->right = t1; 
				stN_top++;
				stN[stN_top] = t;
			} 
			stC_top++;
			stC[stC_top] = s[i];
		} 
		else if (s[i] == ')') { 
		    isLastDigit = 0;
			while ( stC_top != -1 && stC[stC_top] != '(') 
			{ 
				t = newNode(0,stC[stC_top],0);  
				stC[stC_top] = '\0';
				stC_top--;
				t1 = stN[stN_top];  
				stN[stN_top] = '\0';
				stN_top--;
				t2 = stN[stN_top];  
				stN[stN_top] = '\0';
				stN_top--;
				t->left = t2; 
				t->right = t1;  
				stN_top++;
				stN[stN_top] = t;
			}  
			stC[stC_top] = '\0';
			stC_top--;
		} 
	} 
	t = stN[stN_top]; 
	return t; 
} 

int evaluate(struct node* root)  
{   
	int res;
    if (!root)  
        return 0;  
  
    if (!root->left && !root->right)  
        return root->data;  
  
    int l_val = evaluate(root->left);  
    int r_val = evaluate(root->right);  
    
    switch(root->symbol)
    {
	    case '+':
	            res=l_val+r_val;break;
	    case '-':
	            res=l_val-r_val;break;
	    case '*':
	            res=l_val*r_val;break;
	    case '/':
	            res=l_val/r_val;break;
	    case '%':
	            res=l_val%r_val;break;
	    case '^':
	            res=pow(l_val,r_val);
    }
    return res;
}  

int main() 
{ 
	int i,n; 
	char s1[N],s2[60];   
    scanf("%s", s1);    
   	n = strlen(s1);    	
   	s2[0]= '('; 
   	i = 0;
   	while(i<n)
	{
   		if(isValidChar(s1[i]))
		{
   			s2[i+1]=s1[i]; 
		}
		else
		{
	    	printf("Invalid");	
			return 0;		
		} 
		i++; 	
	}
   	s2[i+1]=')'; 
	struct node* root = buildexptree(s2,n+2); 
	if(root)
	{
		printf("\n%d",evaluate(root)); 
	}
	else 
	{ 
	    printf("Tree not created\n");
	}
    return 0; 
}
