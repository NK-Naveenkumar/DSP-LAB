#include <stdio.h>
char stack[20];
int top=-1;

void push(char x){
    top++;
    stack[top]=x;
}
char pop(){
    return stack[top--];
}
int priority(char x){
    if(x=='(') return 0;
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    if(x=='^') return 3;
}
int main()
{
    char expression[20];
    printf("Enter the expression \n");
    scanf("%s",expression);
    char *e,x;
    e=expression;
    printf("postfix expression is:\n");
    while(*e!='\0'){
        if(isalnum(*e)) printf("%c",*e);
        else if(*e=='(') push(*e);
        else if(*e==')') {
            while((x=pop())!='(') printf("%c",x);
        }
        else{
            while(priority(stack[top])>=priority(*e)) 
            printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    printf("%c",pop());

    return 0;
}
